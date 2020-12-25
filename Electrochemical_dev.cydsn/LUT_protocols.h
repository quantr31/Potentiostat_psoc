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
#if !defined(LUT_PROTOCOLS_H)
#define LUT_PROTOCOLS_H
    
#include <project.h>
#include "stdlib.h"
#include "stdio.h"    
    
uint16 LUT_MakeCVStartZero(uint16 start_val, uint16 end_val);    
uint16 LUT_MakeTriangleWave(uint16 start_val, uint16 end_val);
uint16 LUT_make_line(uint16 start, uint16 end, uint16 index);

extern uint16 waveform_lut[];
#endif     
/* [] END OF FILE */
