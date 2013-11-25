/*
 * main.cpp
 *
 * Note - if you get "undefined refernce errors" when linking c++ files and c files together,
 * MAKE SURE your regular C files have extern "C"{ } wrappers (surrounded by #ifdef __cplusplus #endif.
 *
 * This will save you lots of headaches later when you swear you're linking is setup correctly
 * but you still can't get it find all references.
 *
 *  Created on: Nov 24, 2013
 *      Author: Kevin
 */

#include <LPC13Uxx.h>    /* LPC13Uxx definitions */
#include <Serial.h>
#include <timer16.h>

/**
 * Starter function
 * @return 0 (shouldn't ever happen though)
 */
int main(void){

	SystemInit();
	SystemCoreClockUpdate();

	//initialize peripherals
	init_timer16(0, 1000);

	Serial myTest;
	myTest.begin(115200);


	//set it running..
	enable_timer16(0);
	while(1){
		delayMs(0,1000);
		myTest.print("This is a huge test");

	}



	return 0;
}


