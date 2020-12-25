/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"
#include "stdlib.h"
#include "cytypes.h"
#include "globals.h"
#include "LUT_protocols.h"
#include "helper.h"
#include "selection.h"

uint16 lut_length;
//char buffer[100];
char test[10];
char result[10];

float32 uA_per_adc_count = 0.0527428;
//float32 R_analog_route = 0.94092;
int16 voltage_error = 0;
float32 R_analog_route = 0;

CY_ISR(isr_dac){   
    //DVDAC_source_SetValue(vdac);
    lut_value = waveform_lut[lut_index];
    sprintf(test, "%d\t", lut_value);
    UART_PutString(test);
    DVDAC_source_SetValue(lut_value);
    lut_index++;
    
    if(lut_index > lut_length){
        isr_dac_Disable();
        //isr_adc_Disable();
        data[lut_index] = 0xC000;
        helper_hardware_sleep();
        lut_index = 0;
    }
}

CY_ISR(isr_adc){
    //ADC_DelSig_StartConvert();
    //ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT);
    data[lut_index] = ADC_DelSig_GetResult16();
    sprintf(result, "%d\n", data[lut_index]);
    UART_PutString(result);
    //voltage_error = -ADC_DelSig_GetResult16() * uA_per_adc_count * R_analog_route;
    
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    //PWM_isr_Start();
    //UART_Start();

    isr_dac_StartEx(isr_dac);
    isr_dac_Disable();
    
    isr_adc_StartEx(isr_adc);
    isr_adc_Disable();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    helper_hardware_start();
    helper_hardware_sleep();    
    
    lut_length = LUT_MakeTriangleWave(1000, 4000);
        //sprintf(buffer, "lut length: %d", lut_length);
        //UART_PutString(buffer);
    
    CyWdtStart(CYWDT_1024_TICKS, CYWDT_LPMODE_NOCHANGE);
    for(;;)
    {
        /* Place your application code here. */
        CyWdtClear();
        CV_run();
    }
}

/* [] END OF FILE */
