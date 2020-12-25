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
#if !defined(GLOBALS_H)
#define GLOBALS_H
    
#include "cytypes.h"

#define MAX_LUT_SIZE 10000
#define VIRTUAL_GROUND 2048
    
uint16 dac_ground_value;
    
volatile uint16 lut_value;
uint16 waveform_lut[MAX_LUT_SIZE];
volatile uint16 lut_index;
int16 data[MAX_LUT_SIZE];
   
#endif   
/* [] END OF FILE */
