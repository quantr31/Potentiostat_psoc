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
#include "LUT_protocols.h"
#include "globals.h"

/******************************************************************************
* Function Name: LUT_make_side
*******************************************************************************
*
* Summary:
*  Make a ramp from start to end in waveform_lut starting at index
*  Does not matter if start or end is higher
*
* Parameters:
*  uint16 start: first value to put in the look up table
*  uint16 end: end value to put in the look up table
*  uint16 index: the place to start putting in numbers in the look up table
*
* Return:
*  uint16: first place after the filled in area of the look up table
*
* Global variables:
*  waveform_lut: Array the look up table is stored in
*
*******************************************************************************/

uint16 LUT_make_line(uint16 start, uint16 end, uint16 index) {
    if (start < end) {
        for (uint16 value = start; value <= end; value++) {
            waveform_lut[index] = value;
            index ++;
        }
    }
    else {
        for (uint16 value = start; value >= end; value--) {
            waveform_lut[index] = value;
            index ++;
        }
    }
    return index;
}

/******************************************************************************
* Function Name: LUT_MakeTriangleWave
*******************************************************************************
*
* Summary:
*  Fill in the look up table (waveform_lut) for the DACs to perform a cyclic voltammetry experiment.
*  Start the CV protocol at the user defined start value
*
* Parameters:
*  uint16 start_value: first value to put in the dac
*  uint16 end_value: to peak dac value
*
* Return:
*  uint16: how long the look up table is
*
* Global variables:
*  waveform_lut: Array the look up table is stored in
*
*******************************************************************************/

uint16 LUT_MakeTriangleWave(uint16 start_value, uint16 end_value) {
    uint16 _lut_index = 0;  // start at the beginning of the lut
    
    //LCD_Position(1,0);
    //LCD_PrintDecUint16(end_value);
    
    _lut_index = LUT_make_line(start_value, end_value, 0);
    
    _lut_index = LUT_make_line(end_value, start_value, _lut_index-1);
    waveform_lut[_lut_index] = start_value;  // the DAC is changed before the value is checked in the isr so it will go 1 over so make it stay at last voltage
    _lut_index++;
    //LCD_PutChar('|');
    //LCD_PrintDecUint16(_lut_index);
    //LCD_PutChar('|');
    return _lut_index;  
}



/******************************************************************************
* Function Name: LUT_MakeCVStartZero
*******************************************************************************
*
* Summary:
*  Fill in the look up table (waveform_lut) for the DACs to perform a cyclic voltammetry experiment.
*  Start the CV protocol at 0 volts
*
* Parameters:
*  uint16 start_value: first value the dac goes after it starts at 0 V
*  uint16 end_value: the dac value to go to after going to start_value, dac then goes to 0 V (e.g. virtual ground)
*
* Return:
*  uint16: how long the look up table is
*
* Global variables:
*  waveform_lut: Array the look up table is stored in
*
*******************************************************************************/

uint16 LUT_MakeCVStartZero(uint16 start_value, uint16 end_value){
    uint16 _lut_index = 0;  // start at the beginning of the lut
    
    //LCD_Position(1,0);
    //LCD_PrintDecUint16(end_value);
    
    _lut_index = LUT_make_line(dac_ground_value, start_value, 0);
    
    _lut_index = LUT_make_line(start_value, end_value, _lut_index-1);
    _lut_index = LUT_make_line(end_value, dac_ground_value, _lut_index-1);
    waveform_lut[_lut_index] = dac_ground_value;  // the DAC is changed before the value is checked in the isr so it will go 1 over so make it stay at virtual ground
    _lut_index++;
    //LCD_PutChar('|');
    //LCD_PrintDecUint16(_lut_index);
    //LCD_PutChar('|');
    return _lut_index;  
}

/* [] END OF FILE */
