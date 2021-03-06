/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** main.c
**
** Beschrijving:	Flash PORTD.7 when PORTC.0 is pressed
** Target:			AVR mcu
** Author: 			maartenwn@gmail.com en aaron.isra�ls@home.nl
** -------------------------------------------------------------------------*/
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>



/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/******************************************************************/
int main( void )


/*		https://youtu.be/dEsYkCZcsi8
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Looping forever, turning 1 led at a time and each cycle it turns the next led on.
Version :    	DMK, Initial code
*******************************************************************/
{
	DDRD = 0b11111111;			// All pins PORTD are set to output 
	DDRC = 0b11111111;
	int i = 0x01;
		
	while (1)
	{
		//i = i << 1;
		i++;
		if(i > 0xFF){
			i = 0x01;
		}
		PORTD = i;
		wait(200);
		
	}

	return 1;
}