
module unsaved (
	clk_clk,
	leds_external_connection_export,
	sw_external_connection_export);	

	input		clk_clk;
	output	[9:0]	leds_external_connection_export;
	input	[1:0]	sw_external_connection_export;
endmodule
