#ifndef I2C_H
#define	I2C_H

void initialize_i2c_readonly_slave(uint8_t seven_bit_address);

void i2c_2_byte_master_read_request_handler(volatile uint16_t * data_to_send_to_master);

#endif	/* I2C_H */