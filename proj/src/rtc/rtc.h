#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>

/******** CONSTANTS ********/

#define RTC_IRQ     8       /*!< IRQ line of the RTC */

#define RTC_ADDR_REG    0x70    /*!<  Address to sent the byte offet of the RTC data */
#define RTC_DATA_REG    0x71    /*!<  Address from which to read the selected data */

#define RTC_SEC         0   /*!< Byte offset of the seconds */
#define RTC_SEC_ALRM    1   /*!< Byte offset of the seconds alarm */
#define RTC_MIN         2   /*!< Byte offset of the minutes */
#define RTC_MIN_ALRM    3   /*!< Byte offset of the minutes alarm */
#define RTC_HRS         4   /*!< Byte offset of the hours */
#define RTC_HRS_ALRM    5   /*!< Byte offset of the hours alarm */
#define RTC_D_WEEK      6   /*!< Byte offset of the day of the week */
#define RTC_D_MONTH     7   /*!< Byte offset of the day of the month */
#define RTC_MONTH       8   /*!< Byte offset of the month */
#define RTC_YEAR        9   /*!< Byte offset of the year */
#define RTC_REG_A       10  /*!< Byte offset of the register A */
#define RTC_REG_B       11  /*!< Byte offset of the register B */
#define RTC_REG_C       12  /*!< Byte offset of the register C */ 
#define RTC_REG_D       13  /*!< Byte offset of the register D */

#define RTC_A_UIP       BIT(7)  /*!< Bit in Register A signaling Update in Progress (do not read or write) */


/******** FUNCTIONS ********/

/**
 * Waits until Update in Progress in Register A is complete
 * 
 */
void (rtc_wait_for_access)();
/**
 * Converts the number in BCD to hexadecimal
 * 
 * @param n 
 * @return uint8_t 
 */
uint8_t rtc_convert_BCD(uint8_t n);
/**
 * Reads from hours address to check if it is night or day
 * 
 */
void (rtc_update_darkmode)();
/**
 * Subscribes to interrupts from the RTC
 * @return 1 - error | 0 - success
 */
int (rtc_subscribe_int)(uint8_t *bit_no);
/**
 * Unubscribes to interrupts from the RTC
 * @return 1 - error | 0 - success
 */
int (rtc_unsubscribe_int)();
