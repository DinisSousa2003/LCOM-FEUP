#ifndef _LCOM_I8254_H_
#define _LCOM_I8254_H_

#include <lcom/lcf.h>

#define DELAY_US    20000

#define KBC_IRQ     0x01

#define KBC_TWO_BYTE    0xE0

#define KBC_ESC_KEY 0x81

#define KBC_OUT_BUF 0x60    //value of the "command byte" is read and written from here
#define KBC_ARG_CMD 0x60
#define KBC_ST_REG  0x64
#define KBC_CMD_REG 0x64


//  Status register
#define KBC_PAR_ERR     BIT(7)
#define KBC_TO_ERR      BIT(6)
#define KBC_ST_AUX      BIT(5)
#define KBC_ST_INH      BIT(4)
#define KBC_ST_IBF      BIT(1)
#define KBC_ST_OBF      BIT(0)


//  Keyboard-Related KBC Commands
    /*  
        Written using KBC_CMD_REG
        Arguments are passed using 0x60 (KBC_ARG_CMD)
        Return values ar passed in the KBC_OUT_BUF
    */
#define KBC_READ_CMD        0x20
#define KBC_WRITE_CMD       0x60
#define CHECK_KBC           0xAA    //0x55 if OK, 0xFC if error
#define CHECK_KB_INTERFACE  0xAB    //0 if OK
#define DISABLE_KBI         0xAD
#define ENABLE_KBI          0xAE


//  KBC "Command Byte"
    /*  
        First, issue a command (KBC_RCB / KBC_RCB) to KBC_CMD_REG
        It's value must be read/written to 0x60 (KBC_OUT_BUF)
    */
#define KBC_DIS_MOUSE       BIT(5)
#define KBC_DIS_KBI         BIT(4)
#define KBC_ENA_OBF_MOUSE   BIT(1)
#define KBC_ENA_OBF_KB      BIT(0)

#define KEY_UP 0x48
#define KEY_DOWN 0x50
#define KEY_ENTER 0x1C

#endif
