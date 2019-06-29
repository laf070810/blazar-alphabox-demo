/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Blazar_shell.h"
#include "Blazar_ADC.h"
#include <string.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static char * dtoa(double d, char *str);

/*******************************************************************************
 * Code
 ******************************************************************************/
int32_t do_adc(p_shell_context_t context, int32_t argc, char **argv)
{
	if (argc == 2)
	{
		if (strcmp(argv[1], "temp") == 0)
		{
			PRINTF("Temperature: %f\r\n\r\n", ADC_Read(ADC_TEMPERATURE_CHANNEL) / 1.0);
			
			return 0;
		}
		else if (strcmp(argv[1], "potential") == 0)
		{	
			PRINTF("Voltage(V): %f\r\n\r\n", ADC_Read(ADC_POTENTIOMETER_CHANNEL) / 4095.0 * 3.3);
			
			return 0;
		}
		else if (strcmp(argv[1], "light") == 0)
		{
			PRINTF("Lightness: %f\r\n\r\n", ADC_Read(ADC_LIGHT_CHANNEL) / 4095.0 * 3.3);
			
			return 0;
		}
		else
		{
			PRINTF("Error: Unknown option. \r\n\r\n");
			
			return 1;
		}
	}
	
	PRINTF("Error: Unknown option. \r\n\r\n");
	return 1;
}


static char * dtoa(double d, char *str)
{
	char str1[40];
	int j = 0,k,i;
	i = (int)d;
	while(i > 0)
	{
		str1[j++] = i % 10 + '0';
		i = i / 10;
	}
	for(k = 0;k < j;k++)
	{
		str[k] = str1[j-1-k];
	}
 
 
	str[j++] = '.';
 
	d = d - (int)d;
	for(i = 0;i < 10;i++)
	{
		d = d*10;
		str[j++] = (int)d + '0';
		d = d - (int)d;
	}
	while(str[--j] == '0');
	str[++j] = '\0';
	return str;
}
