#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpiops.h"
#include "xstatus.h"
#include "xparameters.h"

#define EMIO_0 78	// 0~77 are number of MIO
#define EMIO_1 79	// 78 for EMIO[0] and 79 for EMIO[1] and so on.
			// Reference to ug1085 page.770

XGpioPs EMIO;	// a XGpioPs struct named EMIO

int main()
{
	int status;
	int x;

	XGpioPs_Config *GPIOConfig;
	// Look up gpiops' configuration from memory
	// XPAR_XGPIOPS_0_DEVICE_ID in xparameters.h
	GPIOConfig = XGpioPs_LookupConfig(XPAR_XGPIOPS_0_DEVICE_ID);
	// Initialize EMIO which is XGpioPs
	status = XGpioPs_CfgInitialize(&EMIO, GPIOConfig, GPIOConfig->BaseAddr);	
	// check successfully initialize or not
	if(status != XST_SUCCESS) return XST_FAILURE;	
	// Set direction of gpio output
	XGpioPs_SetDirectionPin(&EMIO, EMIO_0, 1);	
	// Set direction of gpio output
	XGpioPs_SetDirectionPin(&EMIO, EMIO_1, 1); 	
	// Enable output
	XGpioPs_SetOutputEnablePin(&EMIO, EMIO_0, 1);	
	// Enable output
	XGpioPs_SetOutputEnablePin(&EMIO, EMIO_1, 1);	
	// Set output voltage low
	XGpioPs_WritePin(&EMIO, EMIO_0, 0);	
	// Set output voltage low
	XGpioPs_WritePin(&EMIO, EMIO_1, 0);	

	while(1)
	{
		// for convenience to change EMIOs output
		printf("Ouptut:");	
		scanf("%d", &x);
		printf("%d\n", x);

		// Set output voltage high or low dependent on x
		XGpioPs_WritePin(&EMIO, EMIO_0, x&0x01);	
		// Set output voltage high or low dependent on x
		XGpioPs_WritePin(&EMIO, EMIO_1, x&0x01);	
	}
    return 0;
}
