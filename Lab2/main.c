#include <stdio.h>
#include "types.h"
#include "DIO.h"
#include "Timer0.h"
#include "Systic_timer.h"
int z=0;
void fun1() {
  while(1){
     // TimerEnable(TIMER0_BASE,TIMER_A);
      //DIO_WritePin(&GPIO_PORTF_DATA_R,1,0);
      //while((TIMER0_RIS_R & 0x01) == 0);
      //etBit(TIMER0_ICR_R,0);
      DIO_WritePin(&GPIO_PORTF_DATA_R,3,0);
      DIO_WritePin(&GPIO_PORTF_DATA_R,2,0);
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,1);
      //while((TIMER0_RIS_R & 0x01) == 0);
      //setBit(TIMER0_ICR_R,0);
  }
    
}


void fun2() {
  while(1){
      TimerEnable(TIMER0_BASE,TIMER_A);
      
      
      
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,2,0);
      
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
      DIO_WritePin(&GPIO_PORTF_DATA_R,3,0);
      DIO_WritePin(&GPIO_PORTF_DATA_R,1,0);
      
      DIO_WritePin(&GPIO_PORTF_DATA_R,2,1);
      
      
      while((TIMER0_RIS_R & 0x01) == 0);
      setBit(TIMER0_ICR_R,0);
  }
}
uint32 blinky1[40];
uint32_ptr blinky1_sp= &blinky1[40];
uint32 blinky2[40];
uint32_ptr blinky2_sp= &blinky2[40];
int main()
{
  DIO_init();
  Systick_Init_int();
  
 *(--blinky1_sp)= (1<<24); //psr
 *(--blinky1_sp)= (uint32)(&fun1); //psr
 *(--blinky1_sp)= 0x9;
*(--blinky1_sp)= 0xc;
 *(--blinky1_sp)= 0x3;
*(--blinky1_sp)= 0x2;
*(--blinky1_sp)= 0x1;
 *(--blinky1_sp)= 0x0;
 
   *(--blinky2_sp)= (1<<24); //psr
 *(--blinky2_sp)= (uint32)(&fun2); //psr
  *(--blinky2_sp)= 0x90;
  *(--blinky2_sp)= 0xc0;
  *(--blinky2_sp)= 0x30;
  *(--blinky2_sp)= 0x20;
 *(--blinky2_sp)= 0x10;
 *(--blinky2_sp)= 0x00;
 
 while(1){
   
 }
  return 0;
}

void  SysTick_handler(){
  z++;
}
