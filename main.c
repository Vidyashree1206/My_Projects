/*
 Name: Vidyashree B Shettar
 enrollment no: 23013_085 (emertxe) 
 * File:   main.c
 */

#include <xc.h>


void init_adc(void);
unsigned short read_adc(void);
void init_adc(void)
{
    /* Selecting Right Justification */
    ADFM = 1;
    
    /* Starting the ADC Module */
    ADON = 1;

    /*select the channel 0*/
    CHS0 = 0;
    CHS1 = 0;
    CHS2 = 0;
    CHS3 = 0;
}

unsigned short read_adc(void)
{
    unsigned short adc_reg_val; // 2bytes
    
    /* Start the ADC conversion */
    GO = 1;
    
    /* Wait for the conversion to complete */
    while (nDONE); //nDONE = 0 GO = 0
    
   
    adc_reg_val = (ADRESH << 8) | ADRESL;  // 11 1111 1111 -> 1023
    
    return adc_reg_val; // 0 to 1023
    
}

void main(void) {
    init_adc();
    init_config();
    unsigned short adc_reg_val; //0 to 1023
    unsigned short op_voltage; // 0 to 100 volts
    

    while (1) {
        adc_reg_val = read_adc();//10 bits -> 0 to 1023
        op_voltage = adc_reg_val/10;  //((adc_reg_val*5)/1024)*20 this formula is used but to make it short i will round it to 1/10
    }
    return 0;
}
