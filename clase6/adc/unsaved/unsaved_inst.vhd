	component unsaved is
		port (
			clk_clk                         : in  std_logic                    := 'X'; -- clk
			adc_external_interface_sclk     : out std_logic;                           -- sclk
			adc_external_interface_cs_n     : out std_logic;                           -- cs_n
			adc_external_interface_dout     : in  std_logic                    := 'X'; -- dout
			adc_external_interface_din      : out std_logic;                           -- din
			leds_external_connection_export : out std_logic_vector(7 downto 0)         -- export
		);
	end component unsaved;

	u0 : component unsaved
		port map (
			clk_clk                         => CONNECTED_TO_clk_clk,                         --                      clk.clk
			adc_external_interface_sclk     => CONNECTED_TO_adc_external_interface_sclk,     --   adc_external_interface.sclk
			adc_external_interface_cs_n     => CONNECTED_TO_adc_external_interface_cs_n,     --                         .cs_n
			adc_external_interface_dout     => CONNECTED_TO_adc_external_interface_dout,     --                         .dout
			adc_external_interface_din      => CONNECTED_TO_adc_external_interface_din,      --                         .din
			leds_external_connection_export => CONNECTED_TO_leds_external_connection_export  -- leds_external_connection.export
		);

