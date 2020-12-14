//#error "para probar que este archivo esta siendo compilado"
 

static char A[3][4] ={
                       { 0,1,2,3},
                       { 1,2,3,4},
                       { 2,3,4,5}
                     };
void adc_init(void)
{ 
 setup_adc(ADC_CLOCK_DIV_8);      // Set ADC conversion time to 8Tosc
 setup_adc_ports(AN0);             // Configure RA0 (AN0) as analog
 set_adc_channel(0);               // Select channel 0 input	
 delay_ms(5); 
}

unsigned int16 read(void)
{
 return read_adc();
}







