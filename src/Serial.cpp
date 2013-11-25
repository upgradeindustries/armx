#include <LPC13Uxx.h>    /* LPC13Uxx definitions */
#include <Serial.h>
#include <uart.h>

/**
 * Default constructor, uses default settings
 */
Serial::Serial() : my_baud(9600){
}


/**
 * Open up a serial port at the chosen baud
 * with all other parameters as their default value
 * @param baud
 */
void Serial::begin(uint32_t baud){
	my_baud=baud;
	UARTInit(my_baud);
}


/**
 * Send a single character
 * @param ch Character to send
 * @return The character that was sent
 */
int Serial::sendchar (int ch)  {
  if (ch == '\n')  {
	  ch = SERIAL_CR;

  }
  //wait for ready
  while (!(LPC_USART->LSR & 0x20));
  //fill the transmit register
  LPC_USART->THR = ch;
  return LPC_USART->THR;
}

/**
 * Gets a single key value
 * @return
 */
int Serial::getkey (void)  {
	//wait for receive
	while (!(LPC_USART->LSR & 0x01));
	return (LPC_USART->RBR);
}

/**
 * Writes a long buffer to the UART
 * @param buff pointer to a buffer to send
 * @param len length of buffer
 */
void Serial::write(uint8_t* buff, uint32_t len){
	UARTSend(buff,len);
}

/**
 * This function takes a null terminated string buffer
 * and prints it out via the uart
 * @param buff A null-terminated string.
 */
void Serial::print(char* buff){
	print_string((uint8_t*)buff);
}

