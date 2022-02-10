	component unsaved is
		port (
			clk_clk                         : in  std_logic                    := 'X';             -- clk
			leds_external_connection_export : out std_logic_vector(9 downto 0);                    -- export
			sw_external_connection_export   : in  std_logic_vector(1 downto 0) := (others => 'X')  -- export
		);
	end component unsaved;

	u0 : component unsaved
		port map (
			clk_clk                         => CONNECTED_TO_clk_clk,                         --                      clk.clk
			leds_external_connection_export => CONNECTED_TO_leds_external_connection_export, -- leds_external_connection.export
			sw_external_connection_export   => CONNECTED_TO_sw_external_connection_export    --   sw_external_connection.export
		);

