#include <plib.h>


int main()
{
	TRISE=0x0;

	TRISD = 1 << 5;  // btnOn
	TRISD |= 1 << 6; // btnOff

	int led = 0; // значение от 0 до 8 (0-ниодин светодиод не горит, 1..8 - горит один из этих светодиодов)
	int stateOn = 0 ; // Кнопка btnOn была уже нажата, тогда 1, иначе 0
	int stateOff = 0; // Кнопка btnOff была уже нажата, тогда 1, иначе 0

	while( 1 ) {

		if (PORTD & (1 << 5)) {
			if ( led > 8 ) {
				PORTE = 0;
				led = led % 9;
			}
			if (stateOn == 0)
				led++;
			stateOn = 1;
		} else 
			stateOn = 0;
		

		if (PORTD & (1 << 6)) {
			if ( stateOff == 1 )
				if ( led != 0 )
					led--;
				
			stateOff = 1;
		} else 
			stateOff = 0;
		
		

		for (int i = 0; i < led; i++) 
			PORTE |= 1<<i;
	} 
}