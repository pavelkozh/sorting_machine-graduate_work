#ifndef servolib_H_INCLUDED
#define servolib_H_INCLUDED
#define F_CPU 8000000UL
#include <avr/io.h>
#define FORWARD 45
#define BACKWARD 170

/// Function for servo initialization
void servoInit();

///  Function for Timer2 initialization
void timer2Init(void);

/// Function for choosing angle; 
/// Function returns a count for OCR1A register (PWM)
/// Parameters: uint8_t colour code - code of defined colour (1-5)
uint16_t chooseAngle(uint8_t colour_code);

/// Function for pushing object
/// Parameters: uint8_t direction - direction of pushing
void servoPush(uint16_t direction);

/// Function for changing OCR1A register (changing position of servo)
/// Parameters: uint16_t angle - value for OCR1A register
void servoRotate(uint16_t angle);

/// Function for left shifting array
/// Parameters: uint8_t *array - pointer to array to shift
/// uint16_t size - count of elements
void shiftArray(uint8_t *array, uint16_t size);

#endif