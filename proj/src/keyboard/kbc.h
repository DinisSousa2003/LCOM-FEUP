#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>	

#include "i8042.h"

void (kbc_ih)(void);

int (kbd_get_status_byte)();

int (kbc_read_value)();

void (kbc_issue_command)(uint8_t cmd);

int (kbc_write_cmd)(uint8_t cmd);
int (kbc_read_cmd)(uint8_t* cmd);

void (kbc_restore_interrupts)();

int (kbd_subscribe_int)(uint8_t *bit_no);
int (kbd_unsubscribe_int)();

int (mouse_subscribe_int)(uint8_t *bit_no);
int (mouse_unsubscribe_int)();
int (enable_mouse)();
int (disable_mouse)();
int (mouse_write_to_port)(uint8_t port, uint8_t cmd);
int (mouse_write_cmd)(uint8_t cmd);
int (mouse_enbl_data_reporting)();
int (mouse_disable_data_reporting)();

void (mouse_ih)(void);
int (mouse_read_value)();
int (parse_packet)();
