//#error "para probar que este archivo esta siendo compilado"
 
 #define COL 4
 #define FIL 3

char A[FIL][COL] ={
                       { 0,1,2,3},
                       { 4,5,6,7},
                       { 9,2,4,5}
                     };

void adc_init(void)
{ 
 set_tris_d(0x00);
 setup_adc(ADC_CLOCK_DIV_8);      // Set ADC conversion time to 8Tosc
 setup_adc_ports(AN0);             // Configure RA0 (AN0) as analog
 set_adc_channel(0);               // Select channel 0 input	
 delay_ms(5); 
}

unsigned int16 read(void)
{
 return read_adc();
}







