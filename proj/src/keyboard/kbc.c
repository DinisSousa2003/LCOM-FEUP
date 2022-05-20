#include <kbc.h>
#include <minix/sysutil.h>

//uint8_t scancode;
int kbc_hook_id = 1;
uint8_t data = 0;
bool makecode, kbd_valid = false, full_code_ready = false;
int size = 0;
uint8_t scancode[2];

void (kbc_ih)(void) {
    if (kbd_get_status_byte()) return;

    if (kbc_read_value()) return;
}

int (kbd_get_status_byte)() {
    uint8_t status;
    kbd_valid = false;
    if (util_sys_inb(KBC_ST_REG, &status)) {
        printf("Error reading status register");
        return 1;
    }
    if (status & (KBC_PAR_ERR | KBC_TO_ERR | KBC_ST_AUX)) {
        kbd_valid = false;
        printf("ERROR parity, timeout or mouse");
        return 0;
    }
    if (status & KBC_ST_OBF) {
        kbd_valid = true;
        return 0;
    }
    return 1;
}

int (kbc_read_value)(){
    
    if(full_code_ready) {   //reset das variaveis
        full_code_ready = false;
        size = 0;
    }
    
    if(util_sys_inb(KBC_OUT_BUF, &data)){
        printf("Error reading out buffer");
        return 1;
    }
    if(!kbd_valid) return 1;

    scancode[size] = data;
    size++;
    if(size == 1 && (data == KBC_TWO_BYTE)) {   //quando ainda nao esta pronto
        full_code_ready = false;
    } else {    //quando ja esta pronto
        makecode = ((data & 0x80) == 0x80) ? false : true;
        full_code_ready = true;
    }
    return 0;

}

int (kbc_read_cmd)(uint8_t* cmd) {
    if (sys_outb(KBC_CMD_REG,KBC_READ_CMD)) return 1;
    if (util_sys_inb(KBC_OUT_BUF,cmd)) return 1;
    return 0;
}

int (kbc_write_cmd)(uint8_t cmd) {
    if(sys_outb(KBC_CMD_REG,KBC_WRITE_CMD)) return 1;
    if(sys_outb(KBC_ARG_CMD,cmd)) return 1;
    return 0;
}

void (kbc_restore_interrupts)() {
    printf("restoring keyboard \n");
    uint8_t command;
    kbc_read_cmd(&command);
    command |= BIT(0);
    kbc_write_cmd(command);
    printf("done \n");
}

int (kbd_subscribe_int)(uint8_t *bit_no) {
  kbc_hook_id = *bit_no;
  return sys_irqsetpolicy(KBC_IRQ,IRQ_REENABLE|IRQ_EXCLUSIVE,&kbc_hook_id);
}

int (kbd_unsubscribe_int)() {
  return sys_irqrmpolicy(&kbc_hook_id);
}

