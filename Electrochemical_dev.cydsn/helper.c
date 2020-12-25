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
#include "globals.h"
#include "helper.h"


void helper_hardware_start(void){
    DVDAC_source_Start();
    PWM_isr_Start();
    Opamp_Aux_Start();
    ADC_DelSig_Start();
    TIA_Start();
    VDAC8_TIA_Start();
    UART_Start();
}

void helper_hardware_sleep(void)
{
    DVDAC_source_Sleep();
    ADC_DelSig_Sleep();
    TIA_Sleep();
    VDAC8_TIA_Sleep();
    Opamp_Aux_Sleep();
    PWM_isr_Sleep();
    UART_Sleep();
}

void helper_hardware_wakeup(void){
    DVDAC_source_Wakeup();
    CyDelay(1);
    DVDAC_source_SetValue(lut_value); 
    CyDelay(10);
    ADC_DelSig_Wakeup();
    TIA_Wakeup();
    VDAC8_TIA_Wakeup();
    Opamp_Aux_Wakeup();
    PWM_isr_Wakeup();   
    UART_Wakeup();
}
/* [] END OF FILE */
