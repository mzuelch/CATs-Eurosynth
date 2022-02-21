<h1>Changes to the original design</h1>
<p>For ease of production and the posibility for a 12bit output resolution for both channels, the internal DAC output was replaced by a second MCP4725.</p>
<p>The firmware given in this repository is written for MCP4725<bold>A0</bold>T-* and A<bold>J</bold>NN. When using differnt version of the MCP4725, the base I2C address has to be changed in Periphery.h.<br>
For further information see <a href="https://github.com/mzuelch/CATs-Eurosynth/blob/main/Modules/HAGIWO/Multiout/Documentation/Datasheet/MCP4725.pdf">datasheet</a>.</p>

<h1>Board Manager for Seeeduino XIAO</h1>
<p>The design and firmware is made for a Seeduino XIAO standard MCU. RP2040 or BLE MCUs won't work.</p>
<a href="https://wiki.seeedstudio.com/Seeeduino-XIAO/#software">Install HowTo</a>
<h1>Known Issues</h1>
<table>
	<tr>
		<th>#</th>
		<th>Solved?</th>
		<th>Hardware</th>
		<th>Firmware</th>
		<th>Issue</th>
	</tr>
	<tr>
		<td>001</td>
		<td>No</td>
		<td>X</td>
		<td></td>
		<td>Design uses not readily available BAT43W. Redesign to BAV99W as JLCPCB basic component.</td>
	</tr>
</table>