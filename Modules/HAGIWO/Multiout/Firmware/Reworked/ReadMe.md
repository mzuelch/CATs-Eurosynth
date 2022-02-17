<h2>Reworked Firmwares</h2>
<p>Check and install dependecies in the corresponding directories</p>
<h3>HAGIWO_MultiOut_Calibration</h3>
<p>Calibration tool for both analog out channels as well as a tool to calculate the proper calibration settings:</p>
<ul>
	<li>AD_CH1_calib_m</li>
	<li>AD_CH1_calib_b</li>
	<li>AD_CH2_calib_m</li>
	<li>AD_CH2_calib_b</li>
</ul>
<p>Run this tool prior to the actual programming and change the "real" firmware accordingly</p>
<h3>HAGIWO_Quantizer_Interrupt</h3>
<p>Firmware update based on the original release.</p>
<ul>
	<li>EEPROM functionality and SAVE-Routine by implementing FlashStorage_SAMD and the introduction of a signature key to determine if the EEPROM is valid</li>
	<li>Encoder handling changed to EncoderButton incl. event handling instead of brute force pulling</li>
	<li>Ext. Trigger handling changed to interrupt service routine</li>
	<li>I2C sped up to 3.4MHz communication speed</li>
	<li>Changed Calibration formula</li>
	<li>General debugging</li>
</ul>
<h4>ToDo's</h4>
<ul>
	<li>Input calibration routine instead of hardcoded calibration factor</li>
	<li>Additional envelope generators:
		<ul>
			<li>Gate</li>
			<li>Trigger</li>
			<li>ASR</li>
		</ul>
	</li>
	<li>The XIAO still kills itself when turning the encoder too fast. It's also an issue in the original firmware, I still haven't figured out the reason.</li>
</ul>