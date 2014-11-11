#ifndef ADC_H
#define	ADC_H

void initialize_voltage_reference(void);
void initialize_adc(void);
uint16_t analog_read(void);

#endif	/* ADC_H */