/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 * by: Fady Maher
 * created: 5/9/2023
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/ADC/ADC.h"
#include "LDR_Interface.h"

extern G_u8Target;

u16 LDR_readint(void)
{
	//	Declare the value of LDR value & ADC Value
	u16 L_u16LDRvalue, L_u16ADCValue = 0;
	/*
     *  get the digital value of the sensor Analog reading
	 *  that sensor on channel 1
 	 */
	G_u8Target = TARGET_LDR;
	L_u16ADCValue = ADC_u16GetDigitalValue(SENSOR_CHANNEL_ID);

    /*
     * LDR_value is declared as a variable of type u16, which typically represents a 16-bit unsigned integer. This variable will store the result of the LDR calculation.
	 * adc_value is assumed to be a variable representing the raw ADC reading, and it's cast to a u64 (64-bit unsigned integer) to ensure the calculations are performed with sufficient precision.
	 * SENSOR_MAX_INTENSITY is representing the maximum intensity or brightness value that the LDR can measure.
	 * ADC_REF_VOLT_VALUE is representing the reference voltage of the ADC, which is used to convert the ADC reading to a voltage value.
	 * ADC_MAXIMUM_VALUE is representing the maximum possible value that the ADC can return.
	 * SENSOR_MAX_VOLT_VALUE is representing the maximum voltage value that the LDR can produce.
     * "adc_value * SENSOR_MAX_INTENSITY" This operation is done to scale the ADC reading to the intensity or brightness range.
     *  " * ADC_REF_VOLT_VALUE multiplies " This operation converts the scaled ADC reading into a voltage value.
     * /(ADC_MAXIMUM_VALUE * SENSOR_MAX_VOLT_VALUE) This step scales the voltage value down to a fractional value between 0 and 1.
     * "u16" This is done because the LDR value is likely being represented as a 16-bit integer.
     */

     L_u16LDRvalue = (u16)(((u64)L_u16ADCValue*SENSOR_MAX_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return L_u16LDRvalue;
}


