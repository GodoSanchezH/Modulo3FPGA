	component unsaved is
		port (
			clk_clk                                        : in    std_logic := 'X'; -- clk
			accelerometer_external_interface_I2C_SDAT      : inout std_logic := 'X'; -- I2C_SDAT
			accelerometer_external_interface_I2C_SCLK      : out   std_logic;        -- I2C_SCLK
			accelerometer_external_interface_G_SENSOR_CS_N : out   std_logic;        -- G_SENSOR_CS_N
			accelerometer_external_interface_G_SENSOR_INT  : in    std_logic := 'X'  -- G_SENSOR_INT
		);
	end component unsaved;

	u0 : component unsaved
		port map (
			clk_clk                                        => CONNECTED_TO_clk_clk,                                        --                              clk.clk
			accelerometer_external_interface_I2C_SDAT      => CONNECTED_TO_accelerometer_external_interface_I2C_SDAT,      -- accelerometer_external_interface.I2C_SDAT
			accelerometer_external_interface_I2C_SCLK      => CONNECTED_TO_accelerometer_external_interface_I2C_SCLK,      --                                 .I2C_SCLK
			accelerometer_external_interface_G_SENSOR_CS_N => CONNECTED_TO_accelerometer_external_interface_G_SENSOR_CS_N, --                                 .G_SENSOR_CS_N
			accelerometer_external_interface_G_SENSOR_INT  => CONNECTED_TO_accelerometer_external_interface_G_SENSOR_INT   --                                 .G_SENSOR_INT
		);

