#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>

/******** CONSTANTS ********/

#define SER_IRQ     4
#define SER_PORT    0x3F8

#define SER_INIT    2
#define SER_START   3

#define SER_GOAL_1  40
#define SER_GOAL_2  41

#define SER_RBR 0 
#define SER_THR 0

//---LSR----
#define SER_LSR         5 
#define SER_DATA_READY  BIT(0)
#define SER_OVERRUN_ERR BIT(1)
#define SER_PARITY_ERR  BIT(2)
#define SER_FRAME_ERR   BIT(3)
#define SER_UART_READY  BIT(5)
#define SER_THR_EMPTY   BIT(6)

//---IER----
#define SER_IER     1
#define SER_ERBFI   BIT(0)

//---IIR----
#define SER_IIR         2
#define SER_INT_PEND    BIT(0)
#define SER_INT_ID      BIT(1) | BIT(2)
#define SER_TX_INT      1
#define SER_RX_INT      2
#define SER_RLS_INT     3

//---LCR----
#define SER_LCR         3
#define SER_WORD_LENGTH BIT(0) | BIT(1)
#define SER_DLAB        BIT(7)

#define SER_FCR 2
/******** FUNCTIONS ********/

int (ser_init)();
int (ser_read_lsr_status)(uint8_t* status);
int (ser_read_data)();
int (ser_transmit_data)(uint8_t data);
int (ser_ih)();
int (ser_check_connection)();

int (ser_subscribe_int)(uint8_t *bit_no);
int (ser_unsubscribe_int)();
