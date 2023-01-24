
#include "MSP430F5529.h"
#include "elem.h"
#include "Black_DELAY.h"
#include "Black_USART.h"
#include "oled.h"
int main( void )
{
  // Stop watchdog timer to prevent time out reset
      WDTCTL = WDTPW + WDTHOLD;
  allinit();
  System_overclocking(16);
  OLED_ShowNum(74,0,0,2,16);
  
    while(1)
    {
      PWMInit();
      one();
      //Trig();
      //two();
    }
  return 0;
}
// Echo back RXed character, confirm TX buffer is ready first

//#pragma vector=USCI_A0_VECTOR
//__interrupt void USCI_A0_ISR(void)
//
//
//
//{
//  switch(__even_in_range(UCA0IV,4))
//  {
//  case 0:break;                             // Vector 0 - no interrupt
//  case 2:                                   // Vector 2 - RXIFG
//    while (!(UCA0IFG&UCTXIFG));              // USCI_A0 TX buffer ready?
//     UCA0TXBUF=UCA0RXBUF;
//    break;
//  case 4:break;                             // Vector 4 - TXIFG
//  default: break;
//  }
//}

