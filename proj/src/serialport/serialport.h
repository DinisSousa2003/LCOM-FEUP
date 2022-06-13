#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>

/******** CONSTANTS ********/

#define SER_IRQ     4       /*!< IRQ line of the serial port */
#define SER_PORT    0x3F8   /*!< Address of the host pipe */

#define SER_INIT    2       /*!< Message signaling being ready for connection */
#define SER_START   3       /*!< Message signaling to start game execution */

#define SER_GOAL_1  40      /*!< Message signaling goal from player 1 */
#define SER_GOAL_2  41      /*!< Message signaling goal from player 2 */

#define SER_RBR 0           /*!< Byte offset of the Reciever Buffer Register */
#define SER_THR 0           /*!< Byte offset of the Transmitter Holding Register */

//---LSR----
#define SER_LSR         5       /*!< Byte offset of the Line Status Register */
#define SER_DATA_READY  BIT(0)  /*!< Bit in LSR signaling data available and ready for reading */
#define SER_OVERRUN_ERR BIT(1)  /*!< Bit in LSR signaling overrun error */
#define SER_PARITY_ERR  BIT(2)  /*!< Bit in LSR signaling parity error */
#define SER_FRAME_ERR   BIT(3)  /*!< Bit in LSR signaling framing error */
#define SER_UART_READY  BIT(5)  /*!< Bit in LSR signaling transmitter register ready for recieving data */
#define SER_THR_EMPTY   BIT(6)  /*!< Bit in LSR signaling transmitter register empty */

//---IER----
#define SER_IER     1           /*!< Byte offset of the Interrupt Enable Register */
#define SER_ERBFI   BIT(0)      /*!< Bit in LSR signaling to enable recieved data available interrupts*/

/******** FUNCTIONS ********/

/**
 * Enables interrupts for recieving data, reads leftover data in the Receiver Buffer Register and transmits a initial message saying it is ready to connect
 * @return 1 - error | 0 - success
 */
int (ser_init)();
/**
 * Reads the Line Status Register to check for errors and available data
 * @return 1 - error | 0 - success
 */
int (ser_read_lsr_status)(uint8_t* status);
/**
 * If data is available it will read all entries in the buffer until there are none left(to maintain it updated)
 * @return 1 - error | 0 - success
 */
int (ser_read_data)();
/**
 * Sends the given data to the Transmitter Holding Register
 * @return 1 - error | 0 - success
 */
int (ser_transmit_data)(uint8_t data);
/**
 * Used in the beginning of the connection to determine what to do next
 * @return 1 - error | 0 - success
 */
int (ser_check_connection)();
/**
 * Unubscribes to interrupts from the Serial Port
 * @return 1 - error | 0 - success
 */
int (ser_subscribe_int)(uint8_t *bit_no);
/**
 * Unubscribes to interrupts from the Serial Port
 * @return 1 - error | 0 - success
 */
int (ser_unsubscribe_int)();
