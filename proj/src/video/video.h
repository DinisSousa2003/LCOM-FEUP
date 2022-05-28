#include <lcom/lcf.h>
#include <math.h>
#include "video_macros.h"


int (vg_mode)(uint16_t mode);
unsigned(bits_to_byte_ceil)(unsigned bits_per_pixel);
int (map_video_memory) (uint16_t mode);
void (refresh_buffer)();
void (clear_buffer)();
int (vg_set_pixel) (uint32_t color, uint16_t x, uint16_t y);
int (vg_draw_hline) (uint16_t x, uint16_t y, uint16_t len, uint32_t color);
int (draw_rectangle)(uint32_t color, uint16_t x, uint16_t y, uint16_t width, uint16_t height);
int (draw_pattern)(uint8_t no_rectangles, uint32_t first, uint8_t step);
int (draw_sprite)(uint16_t x, uint16_t y, xpm_image_t img);
