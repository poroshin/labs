#include <plib.h>

// Define timing constants
                             
int main()
{
	TRISE = 0;
	TRISD = 1 <<5;
	while (1)
  	{
    		if (PORTD & (1<<5)) {
		PORTE = 0;
		}
	else{
	PORTE = 1<<7;
	}
  	}
	
}
