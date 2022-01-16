	component unsaved is
		port (
			clk_clk                          : in  std_logic                    := 'X';             -- clk
			latx_external_connection_export  : out std_logic_vector(7 downto 0);                    -- export
			portx_external_connection_export : in  std_logic_vector(1 downto 0) := (others => 'X')  -- export
		);
	end component unsaved;

	u0 : component unsaved
		port map (
			clk_clk                          => CONNECTED_TO_clk_clk,                          --                       clk.clk
			latx_external_connection_export  => CONNECTED_TO_latx_external_connection_export,  --  latx_external_connection.export
			portx_external_connection_export => CONNECTED_TO_portx_external_connection_export  -- portx_external_connection.export
		);

