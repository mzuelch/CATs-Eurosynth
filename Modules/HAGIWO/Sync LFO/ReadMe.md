<h2>Revision History</h2>
<table>
	<tr>
		<th>Revision</th>
		<th>Changes</th>
	</tr>
	<tr>
		<td>012202</td>
		<td>Initial Release</td>
	</tr>
	<tr>
		<td>022303</td>
		<td>Arduino Nano rotated by 180deg. No changes in pot or jack position. PCB layout adapted accordingly.<br>Make space for a shrouded IDC header. Mark the correct header and USB connector orientation on the backside.</td>
	</tr>
</table>

<h2>Modulove Appendix</h2>
This is a PCB version of the awesome HAGIWO Clock SYNC LFO.
It was published on Github by [mzuelch](https://github.com/mzuelch/ "mzuelch") and we (modulove) put together the design & kits in our lab.

![HAGIWO Sync LFO Kit](https://modulove.de/syncLFO-b1/MDL_HGW_SYNC-LFO_panelPCBkit_1000px.jpg)

The module is a Arduino-based LFO and can be clocked / synced via the trigger input and offers internal modulation to create complex waveforms.
It can be modified / reprogrammed easily with the Arduino IDE.

![HAGIWO Sync LFO module](https://modulove.de/syncLFO-b1/Modulove_LFO_Productshot_Front_1000px.jpg)

It offers six waveforms and the following hardware features:

- Panel Design by [bkrsmdesign](https://www.instagram.com/bkrsmdesign/ "Sasha Kruse")
- Knob1: Amplifier control. Set the output voltage
- Knob2: Phase control. Set the phase from 0-360°
- Knob3: Waveform control. Select the waveform type.
- Knob4: Internal modulation, creating complex waveforms.
- CLK in: Clock IN.
- OUTPUT Voltage 0/+10V
- Skiff friendly & 6P
- 50 mA draw

<h1>Changes mzuelch made to the original design</h1>
<ul>
	<li>PWM -> Analog Conversion by active Steiner LPF (fg=500Hz) instead of passive RC network</li>
	<li>Unipolar output changed from 0/+5V to 0/+10V</li>
	<li>Additional bipolar output +/-10V</li>
	<li>Additional inverted bipolar output +/-10V</li>
</ul>


DIY Info:

Building the Module is simple and suited for beginners. The Kit comes with SMD parts already soldered.

Assembly Instructions / Video [here](https://youtube.com/playlist?list=PL9-2_fDMIm5cuEoAXl6-avylgxBkOdHC9 "HAGIWO module build video")

More Info:

- [HAGIWO original Articles](https://note.com/solder_state/n/n4c600f2431c3 "HAGIWO Sync LFO module article").

- [HAGIWO Display Video](https://www.youtube.com/watch?v=m64jyVz2w3M "HAGIWO Clock Sync LFO module Youtube Video").


