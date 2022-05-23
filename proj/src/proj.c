#include <lcom/lcf.h>
#include <lcom/proj.h>
#include <lcom/pixmap.h>

#include <stdbool.h>
#include <stdint.h>

#include "video/video.h"
#include "keyboard/kbc.h"
#include "pong.h"

extern uint8_t scancode;


int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab2/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab2/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}


int(proj_main_loop)(int argc, char* argv[])
{
  uint16_t mode = 0x115;
  map_video_memory(mode);
  //graphic mode
  if(vg_mode(mode) != OK){
    vg_exit();
    printf("Failed to go into graphic mode.\n");
    return 1;
  }

  int x = 10, y = 10;
  //https://web.fe.up.pt/~pfs/aulas/lcom2122/labs/lab5/src/doc/group__xpm.html#ga5b655f0fa14e7c32f6983ba8d0c0d4c3
  xpm_image_t img;
  xpm_load(PONG, XPM_8_8_8_8, &img);
  draw_sprite(x, y, img);
  refresh_buffer();

  int ipc_status;
  message msg;
  int r;

  uint8_t kbc_int_bit = 1; 
  if (kbd_subscribe_int(&kbc_int_bit) != OK) return 1;
  
  while( scancode != KBC_ESC_KEY ) { //terminar quando o scancode é 0x81
      /* Get a request message. */
      if ( (r = driver_receive(ANY, &msg, &ipc_status)) != OK ) { 
          printf("driver_receive failed with: %d", r);
          continue;
      }
      if (is_ipc_notify(ipc_status)) { /* received notification */
          switch (_ENDPOINT_P(msg.m_source)) {
              case HARDWARE: /* hardware interrupt notification */				
                  if (msg.m_notify.interrupts & BIT(kbc_int_bit)) { /* subscribed interrupt */
                      kbc_ih();
                  }
                  break;
              default:
                  break; /* no other notifications expected: do nothing */	
          }
      } else { /* received a standard message, not a notification */
          /* no standard messages expected: do nothing */
      }
  }

  //back to text
  vg_exit();

  if(kbd_unsubscribe_int() != OK){
    printf("Error unsubscribing KBC.\n");
    return 1;
  } 

  return 0;
}
