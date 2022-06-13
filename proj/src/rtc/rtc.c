#include <lcom/lcf.h>
#include <stdbool.h>
#include <stdint.h>

#include <lcom/utils.h>
#include "rtc.h"

int rtc_hook_id = 1;
bool darkmode;

void (rtc_wait_for_access)() {
    uint32_t status;
    do {
        sys_outb(RTC_ADDR_REG,RTC_REG_A);
        sys_inb(RTC_DATA_REG,&status);
    } while ((status & RTC_A_UIP) != 0);
}

uint8_t rtc_convert_BCD(uint8_t n) {
    uint8_t temp = n & 0x0f;

    temp += ((n & 0xf0) >> 4) * 10;
    return temp;
}

int (rtc_init)() {

    //SET ALARMS
    //rtc_wait_for_access();
    uint8_t hour = 8;
    sys_outb(RTC_ADDR_REG,RTC_HRS_ALRM);
    sys_outb(RTC_DATA_REG,(uint32_t) hour);

    uint32_t status;
    //rtc_wait_for_access();
    sys_outb(RTC_ADDR_REG,RTC_REG_B);
    sys_inb(RTC_DATA_REG,&status);

    uint8_t word = ((uint8_t) status) & RTC_B_12;
    word |= RTC_B_AIE;

    //rtc_wait_for_access();
    sys_outb(RTC_ADDR_REG,RTC_HRS_ALRM);
    sys_outb(RTC_DATA_REG,(uint32_t) word);

    rtc_update_darkmode();
    
    return 0;
}

void (rtc_update_darkmode)() {

    rtc_wait_for_access();
    uint8_t hour;
    
    sys_outb(RTC_ADDR_REG,RTC_HRS);
    util_sys_inb(RTC_DATA_REG,&hour);
    hour = rtc_convert_BCD(hour);

    if (hour > 8 && hour < 20) darkmode = false;
    else darkmode = true;
}

int (rtc_ih)() {
    uint32_t regC;
    sys_outb(RTC_ADDR_REG, RTC_REG_C);
    sys_inb(RTC_DATA_REG, &regC);
    
    if (regC & RTC_C_AF)
        rtc_update_darkmode();
    
    return 0;
}

int (rtc_subscribe_int)(uint8_t *bit_no) {
  rtc_hook_id = *bit_no;
  return sys_irqsetpolicy(RTC_IRQ,IRQ_REENABLE|IRQ_EXCLUSIVE,&rtc_hook_id);
}

int (rtc_unsubscribe_int)() {
  return sys_irqrmpolicy(&rtc_hook_id);
}

