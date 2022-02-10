<h2>Reworked Firmwares</h2>
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