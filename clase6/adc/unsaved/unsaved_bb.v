
module unsaved (
	clk_clk,
	adc_external_interface_sclk,
	adc_external_interface_cs_n,
	adc_external_interface_dout,
	adc_external_interface_din,
	leds_external_connection_export);	

	input		clk_clk;
	output		adc_external_interface_sclk;
	output		adc_external_interface_cs_n;
	input		adc_external_interface_dout;
	output		adc_external_interface_din;
	output	[7:0]	leds_external_connection_export;
endmodule
