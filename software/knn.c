#include "system.h"
#include "periphs.h"
#include <iob-uart.h>
#include "iob_timer.h"
#include "iob_knn.h"
#include "random.h" //random generator for bare metal

//uncomment to use rand from C lib 
//#define cmwc_rand rand

#define S 12
#define ARRAY 100

///////////////////////////////////////////////////////////////////
int main() {

  unsigned long long elapsed;
  unsigned int elapsedu;

  int x[ARRAY], y[ARRAY], i;
  
  //init uart and timer
  uart_init(UART_BASE, FREQ/BAUD);
  uart_printf("\nInit timer\n");
  uart_txwait();

  timer_init(TIMER_BASE);
  //read current timer count, compute elapsed time
  //elapsed  = timer_get_count();
  //elapsedu = timer_time_us();

  //generate random seed 
  random_init(S);

  for(i=0; i<ARRAY; i++){
    x[i] = (short) cmwc_rand();
  }

  //software

  timer_reset();
  timer_start();

  for(i=3; i<ARRAY; i++){
    y[i] = x[i]/x[i-1]-x[i-2]/x[i-3];
  }

  timer_stop();

  uart_printf("timer software: count - %d, %dus\n", timer_get_count(), timer_time_us());
  
  //hardware
  
  timer_reset();
  timer_start();

  for(i=3; i<ARRAY; i++){
    //y[i] = get_y(i);
  }

  timer_stop();

  uart_printf("timer software: count - %d, %dus\n", timer_get_count(), timer_time_us());

}


