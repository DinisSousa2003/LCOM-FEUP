#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>

/******** CONSTANTS ********/

#define RTC_IRQ     8

#define RTC_ADDR_REG    0x70
#define RTC_DATA_REG    0x71

#define RTC_SEC         0
#define RTC_SEC_ALRM    1
#define RTC_MIN         2
#define RTC_MIN_ALRM    3
#define RTC_HRS         4
#define RTC_HRS_ALRM    5
#define RTC_D_WEEK      6
#define RTC_D_MONTH     7
#define RTC_MONTH       8
#define RTC_YEAR        9
#define RTC_REG_A       10
#define RTC_REG_B       11
#define RTC_REG_C       12
#define RTC_REG_D       13

// reg A
#define RTC_A_UIP           BIT(7)  //do not read or write
#define RTC_A_RATE_SEL(n)   BIT(n)  //select rate for periodic interrupts & square wave output

// reg B
#define RTC_B_SET   BIT(7)  //inhibit updates
#define RTC_B_PIE   BIT(6)  //periodic interrupt enable
#define RTC_B_AIE   BIT(5)  //alarm interrupt enable
#define RTC_B_UIE   BIT(4)  //update-ended interrupt enable
#define RTC_B_SQWE  BIT(3)  //enable square-wave generation
#define RTC_B_DM    BIT(2)  // 1:binary | 0: BCD
#define RTC_B_24    BIT(1)  // 1: 0-23
#define RTC_B_12    0xfd    // 0: 1-12
#define RTC_B_DSE   BIT(0)  //enable daylight savings time

// reg C --- MUST BE READ TO CLEAR FLAGS
#define RTC_C_IRQF  BIT(7)  //if any event occured
#define RTC_C_PF    BIT(6)  //set to 1 if an event of this type ocurred
#define RTC_C_AF    BIT(5)
#define RTC_C_UF    BIT(4)

/******** FUNCTIONS ********/

void (rtc_wait_for_access)();
int (rtc_init)();
int (rtc_ih)();
void (rtc_update_darkmode)();

int (rtc_subscribe_int)(uint8_t *bit_no);
int (rtc_unsubscribe_int)();
