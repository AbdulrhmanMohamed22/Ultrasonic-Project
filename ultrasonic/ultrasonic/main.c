/*
 * main.c
 *
 *  Created on: Jun 18, 2023
 *      Author: user
 */

/*-------------------------------------------------------------------------

  [FILE NAME]:     main.c

  [AUTHOR]:        Abdulrhman El-Sanhory

  [DATE CREATED]:  Jun 18, 2023

  [DESCRIPTION]:   Measure the distance using Ultrasonic sensor

--------------------------------------------------------------------------*/

/*-------------------------------INCLUDES---------------------------------*/

#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h>
#include <util/delay.h>

/*-----------------------------Main Function-------------------------------*/
int main(void)
{
	uint16 distance = 0;
	SREG |= (1<<7);
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance = ");
	while(1)
	{
		distance = Ultrasonic_readDistance();
		if(distance>= MIN_DISTANCE && distance <= MAX_DISTANCE)
		{
			LCD_moveCursor(0, 10);
			LCD_intgerToString(distance);
			LCD_displayString("cm ");
			_delay_ms(100);
		}
	}
}

