#include <plib.h>
  

  int main()
  {
          /*
           * Set PORTE as output.
           * Clear PORTE.
           */
          TRISE = 0x00;
          PORTE = 0x00;
  

          /*
           * Set PORTD8 as input.
           * Clear PORTD.
           */
          TRISD |= 1 << 8;
          PORTD = 0x00;
  

          /*
           * Falling edge.
           */
          INTCON &= ~(1 << 1);
  

          /*
           * Set priority.
           */
          IPC1 = 1 << 26;
  

          /*
           * Clear flag and enable intetupt.
           */
          IFS0 &= ~(1 << 7);
          IEC0 |= 1 << 7;
  

          INTEnableSystemMultiVectoredInt();
  

          while(1) ;
  }
  

  void __ISR(7, ipl6) ChangeNotice_Handler(void)
  {
          IFS0 &= ~(1 << 7);
          PORTE ^= 1;
  }
