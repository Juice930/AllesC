#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/tm4c1294ncpdt.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/debug.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"

#define len 338

int mat[len]={1, 9, 15, 17, 15, 17, 15, 17, 15, 17, 15, 17, 15, 17, 15, 17, 15, 18, 13, 19, 13, 19, 13, 19, 13, 19, 13, 19, 13, 19, 13, 19, 13, 19, 12, 21, 11, 21, 11, 21, 11, 21, 11, 21, 11, 21, 11, 21, 11, 21, 10, 23, 9, 23, 9, 23, 9, 23, 9, 23, 9, 23, 9, 23, 9, 23, 8, 24, 8, 25, 7, 25, 7, 25, 7, 25, 7, 25, 7, 25, 7, 25, 7, 25, 7, 25, 6, 26, 6, 27, 5, 27, 5, 27, 5, 27, 5, 27, 5, 27, 5, 27, 5, 27, 5, 27, 4, 28, 4, 28, 4, 28, 4, 29, 3, 29, 3, 29, 3, 29, 3, 29, 3, 29, 3, 29, 3, 29, 3, 29, 3, 29, 2, 30, 2, 30, 2, 30, 2, 30, 2, 30, 2, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 1055, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 31, 1, 30, 2, 30, 2, 30, 2, 30, 2, 30, 2, 30, 2, 30, 2, 30, 2, 30, 2, 30, 2, 30, 3, 29, 3, 29, 3, 29, 3, 29, 3, 28, 4, 28, 4, 28, 4, 28, 4, 28, 4, 28, 4, 28, 4, 28, 4, 28, 5, 27, 5, 27, 5, 26, 6, 26, 6, 26, 6, 26, 6, 26, 6, 26, 6, 26, 6, 26, 6, 26, 7, 25, 7, 24, 8, 24, 8, 24, 8, 24, 8, 24, 8, 24, 8, 24, 8, 24, 9, 23, 9, 22, 10, 22, 10, 22, 10, 22, 10, 22, 10, 22, 10, 22, 10, 22, 11, 20, 12, 20, 12, 20, 12, 20, 12, 20, 12, 20, 12, 20, 12, 20, 12, 19, 14, 18, 14, 18, 14, 18, 14, 18, 14, 18, 14, 18, 14, 18, 14, 17, 16, 16, 16, 16, 16, 16, 16, 8};
int c=0;
int i=1;
int a=0;
void Timer0IntHandler(void){
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    if(a==0){
        if(c++==mat[i]){
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, !GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_0));
            c=0;
            i++;
        }
        if(i==len){
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, !GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_0));
            a=!a;
            c=0;
        }
    }
    else{
         if(c++==mat[i]){
             GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, !GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_0));
             c=0;
             i--;
         }
         if(i==1){
             GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, !GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_0));
             a=!a;
             c=0;
         }
    }
}

void main(void) {
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE) && !SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0)){};
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_0);

    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER0_BASE, TIMER_A, 55);//16MHz/24kHz=666.666 alv

    IntMasterEnable();
    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

    TimerEnable(TIMER0_BASE, TIMER_A);

    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0,mat[0]);
    while(1){};
}
