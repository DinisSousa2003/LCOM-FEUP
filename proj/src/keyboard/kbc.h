#include <lcom/lcf.h>
#include <i8042.h>

#include <stdbool.h>
#include <stdint.h>	

void (kbc_ih)(void);

int (kbd_get_status_byte)();

int (kbc_read_value)();

void (kbc_issue_command)(uint8_t cmd);

int (kbc_write_cmd)(uint8_t cmd);
int (kbc_read_cmd)(uint8_t* cmd);

void (kbc_restore_interrupts)();

int (kbd_subscribe_int)(uint8_t *bit_no);
int (kbd_unsubscribe_int)();
