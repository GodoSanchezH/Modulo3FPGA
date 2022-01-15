	component unsaved is
		port (
			clk_clk                          : in  std_logic                    := 'X'; -- clk
			portd_external_connection_export : out std_logic_vector(7 downto 0)         -- export
		);
	end component unsaved;

	u0 : component unsaved
		port map (
			clk_clk                          => CONNECTED_TO_clk_clk,                          --                       clk.clk
			portd_external_connection_export => CONNECTED_TO_portd_external_connection_export  -- portd_external_connection.export
		);

