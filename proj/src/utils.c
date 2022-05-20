
#include <lcom/lcf.h>

#include <stdint.h>

#ifdef LAB3
int cnt = 0;
#endif

int(util_get_LSB)(uint16_t val, uint8_t *lsb) {
  
  *lsb = (uint8_t) (val & 0x00ff);
  return 0;
}

int(util_get_MSB)(uint16_t val, uint8_t *msb) {
  
  *msb = (uint8_t) (val >> 8);
  return 0;
}

int (util_sys_inb)(int port, uint8_t *value) {
  uint32_t stub;
  bool not_valid = sys_inb(port, &stub);
  #ifdef LAB3
  cnt++;
  #endif
  if (not_valid) return 1;
  *value = (uint8_t) stub;
  return 0;

  
}
