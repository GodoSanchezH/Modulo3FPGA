
module unsaved (
	clk_clk,
	accelerometer_external_interface_I2C_SDAT,
	accelerometer_external_interface_I2C_SCLK,
	accelerometer_external_interface_G_SENSOR_CS_N,
	accelerometer_external_interface_G_SENSOR_INT);	

	input		clk_clk;
	inout		accelerometer_external_interface_I2C_SDAT;
	output		accelerometer_external_interface_I2C_SCLK;
	output		accelerometer_external_interface_G_SENSOR_CS_N;
	input		accelerometer_external_interface_G_SENSOR_INT;
endmodule
