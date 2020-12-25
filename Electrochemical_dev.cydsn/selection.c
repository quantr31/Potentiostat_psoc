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
#include <project.h>
#include "selection.h"
#include "helper.h"
#include "globals.h"

void CV_run(void){
    if(!isr_dac_GetState()){
        lut_index = 0;
        lut_value = waveform_lut[0];
        helper_hardware_wakeup();
        DVDAC_source_SetValue(lut_value);
        CyDelay(1);
        ADC_DelSig_StartConvert();
        CyDelay(20);
        PWM_isr_WriteCounter(100);
        data[lut_index] = ADC_DelSig_GetResult16();
        
        isr_dac_Enable();
        isr_adc_Enable();
    }
    //else UART_PutString("Error");
  
}
/* [] END OF FILE */
