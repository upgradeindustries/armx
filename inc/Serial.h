#ifndef __SERIAL_CLASS__
#define __SERIAL_CLASS__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


#define SERIAL_CR	0x0D

class Serial{

	private:
		uint32_t  my_baud;

	public:

		/**
		 * Default constructor, uses default settings
		 */
		Serial();
		/**
		 * Open up a serial port at the chosen baud
		 * with all other parameters as their default value
		 * @param baud
		 */
		void begin(uint32_t baud);

		/**
		 * Send a single character
		 * @param ch Character to send
		 * @return The character that was sent
		 */
		int sendchar (int ch);

		/**
		 * Gets a single key value
		 * @return
		 */
		int getkey (void);

		/**
		 * Writes a long buffer to the UART
		 * @param buff pointer to a buffer to send
		 * @param len length of buffer
		 */
		void write(uint8_t* buff, uint32_t len);

		/**
		 * This function takes a null terminated string buffer
		 * and prints it out via the uart
		 * @param buff A null-terminated string.
		 */
		void print(char* buff);

};














#ifdef __cplusplus
}
#endif
#endif //END __SERIAL_CLASS__

