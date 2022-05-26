#include <lcom/lcf.h>
#include <lcom/proj.h>
#include <lcom/pixmap.h>

#include <stdbool.h>
#include <stdint.h>

#include "video/video.h"
#include "keyboard/kbc.h"
#include "game/handlers.h"
#include "game/images.h"

extern uint8_t scancode;


int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/proj/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/proj/output.txt");

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
  /*initialize graphic mode*/
  
  map_video_memory(VIDEO_MODE);
  if(vg_mode(VIDEO_MODE) != OK){
    vg_exit();
    printf("Failed to go into graphic mode.\n");
    return 1;
  }
  

  int ipc_status;
  message msg;
  int r;

  uint8_t timer_int_bit = 0;
  uint8_t kbc_int_bit = 1; 

  if (kbd_subscribe_int(&kbc_int_bit) != OK){
    printf("Error subscribing to keyboard.\n");
    return 1;
  }

  if (timer_subscribe_int(&timer_int_bit) != OK){
    return 1;
  } 

  load_all_images();

  draw_sprite(0, 0, game_images[MENU_IMG]);

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
                      mainHandler(KEYBOARD);
                  }
                  
                  if (msg.m_notify.interrupts & BIT(timer_int_bit)) { /* subscribed interrupt */
                      timer_int_handler();
                      refresh_buffer();
                      //mainHandler(TIMER);
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
  
  if(vg_exit() != OK){
    printf("Error exiting video.\n");
    return 1;
  }
  

  if(timer_unsubscribe_int() != OK){
    printf("Error unsubscribing KBC.\n");
    return 1;
  } 


  if(kbd_unsubscribe_int() != OK){
    printf("Error unsubscribing KBC.\n");
    return 1;
  } 

  return 0;
}
