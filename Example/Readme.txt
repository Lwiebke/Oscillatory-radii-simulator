How to use:

- Create one or more "config file/s" following the format from the example:

	kn = Normal constant
	kt = Tangencial constant
	L = Length (high) of the simulation area
	W = Width
	D = Door width 
	N = Number of particles
	V_0 = V_o of particles
	masa = mass of particles
	end_time = Total time to be simulated (seconds)
	dt = Integration timestep 
	dt_escritura = Output to file time step
	radio_base = original radio
	amplitud_radio 
	frecuencia = "W" used as frecuency
 	seed = seed to initialize the random number generator


- Edit "ejecutar.py" to add the path of the binary and the name of the config file/s.

- Using python3, run "ejecutar.py"

