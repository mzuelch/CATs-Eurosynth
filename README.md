<h1>CAT's Eurosynth</h1>
<p>This is my repository for my analog synth eurorack compatible modules. Files given via the "Gerber" directories are actual production data used for my own prototyping. Bugs are to be expected. Corrections for finished boards marked as "working" are done in KiCAD only.</p>
<h1>License</h1>
<p>Code (AVR projects): GPL3.0.</p>
<p>Code (STM32F projects): MIT license.</p>
<p>Hardware: cc-by-sa-3.0</p>
<p>unless otherwise specified</p>
<h2>Custom Libraries</h2>
<p>Most of the schematics and layouts use custom libraries since some of the stock libries are either buggy or unsuited for my designs. The libraries can be found <a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Libraries">here</a>.</p>
<p>I am about to remodel all the KiCAD Files to use environment variables:</p>
<table>
	<tr>
		<th>Variable</th>
		<th>points to</th>		
	</tr>
	<tr>
		<td>KI_CUSTOM_MOD</td>
		<td>Footprint Data (where all the .pretty stuff is hidden)</td>		
	</tr>
	<tr>
		<td>KI_CUSTOM_3DMOD</td>
		<td>3D Model Data (where all the .3dshapes stuff is hidden)</td>		
	</tr>
	<tr>
		<td>KI_CUSTOM_SYMBOLS</td>
		<td>Symbol Data (where all the .lib stuff is hidden)</td>		
	</tr>
</table>
<p>Layout specific data (mainly front panel stuff) are stored in the corresponding folders. Most of the Links are absolute atm. I will change them as soon as the particular layout is modified.</p>
<p>Proper Aliases and other informations are given in these ReadMe's:</p> 
<table>
	<tr>
		<td><a href=https://github.com/mzuelch/CATs-Eurosynth/blob/main/Libraries/Symbols/ReadMe.md">Symbols</a></td>
		<td><a href=https://github.com/mzuelch/CATs-Eurosynth/blob/main/Libraries/Footprints/ReadMe.md">Footprints</a></td>
		<td><a href=https://github.com/mzuelch/CATs-Eurosynth/blob/main/Libraries/3D%20Shapes/ReadMe.md">3D Shapes</a></td>
	</tr>
</tables>
<h1>Published Designs</p>
<h2>Standard Line</h2>
<p>Collection of modules with no regard to size. These designs are based on either my own ideas and mistakes or published in so many places I can't figure out the original source.</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Power%20Module">Power Module (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Atari%20Punk%20Console">Atari Punk Console (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Baby8%20Sequencer">Baby8 Sequencer (THT, Working (sort of), but i can do better)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/4Ch%20Mixer">4Ch Mixer (SMT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Clock%20Divider">Clock Divider (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Abakus">Abakus (SMT/THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Manual%20Gate">Manual Gate (THT, WIP)</a></h3>

<h2>Slim Line</h2>
<p>Slim Modules to cope with the ever increasing lamentations from my bandmates and wife. Also these designs are based on either my own ideas and mistakes or published in so many places I can't figure out the original source.</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Attenuator">Single Attenuator (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Buffered%20Multiple">Buffered Multiple (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Sample%26Hold">Dual Sample&Hold (THT, Working)</a></h3>

<h2>Purely Mechanical</h2>
<p>Some purely mechanical projects - blinds, cases,...</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Mechanicals/Blinds/1TE">1TE Blind Panel</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Mechanicals/Cases">Cases</a></h3>

<h2>MFOS Clones</h2>
<p>The basic electronic design was made by <a href="http://musicfromouterspace.com/">Music From Outer Space</a>.
The remodelling in KiCAD, slight adaptation, PCB layout and frontpanel designs are based on my own faults</p>
<p>RIP Ray Wilson</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/MFOS/Dual%20VCA%20%232">Dual VCA #2 (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/MFOS/Noise%20Cornucopia">Noise Cornucopia (THT, Working)</a></h3>

<h2>YuSynth Clones</h2>
<p>The basic electronic design was made by <a href="https://yusynth.net">YuSynth</a>.
The remodelling in KiCAD, slight adaptation (especially changes to +/-12V), PCB layout and frontpanel designs are based on my own faults.</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/YuSynth/Improved%20Steiner%20VCF">Improved Steiner VCF (SMT, Working)</a></h3>

<h2>Haraldswerk</h2>
<p>The basic electronic design was made by <a href="https://www.haraldswerk.de/">Haraldswerk</a>.
The remodelling in KiCAD, slight adaptation (especially to Eurorack format), PCB layout and frontpanel designs are based on my own faults.</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Haraldswerk/NGF-E%20LFO/">Next Generation Formant LFO (THT, Working)</a></h3>
<h2>HAGIWO</h2>
<p>The basic electronic design was made by <a href="https://www.youtube.com/channel/UCxErrnnVNEAAXPZvQFwobQw">HAGIWO</a>.
The remodelling in KiCAD, slight adaptation in hard- and software, PCB layout and frontpanel designs are based on my own faults.</p>
<p>The schematics are Public Domain, firmware is Open Source unless otherwise specified.</p>
<p>This part of the repository is made public with permission from HAGIWO itself. It really appreciate it.</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/HAGIWO/6Ch%20Trigger%20Sequencer">6Ch Trigger Sequencer (SMT, Working)</a></h3>
<ul>
	<li>
		<strong>6Ch Gate Sequencer</strong>
		<br><a href="https://www.youtube.com/watch?v=YszdC8YdFl0&t">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n17c69afd484d">Original Build Documentation</a>
	</li>
	<li>
		<strong>6Ch Euclidian Rythm Sequencer</strong>
		<br><a href="https://www.youtube.com/watch?v=lkoBfiq6KPY">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n433b32ea6dbc">Original Build Documentation</a>
	</lt>
</ul>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/HAGIWO/Ringfolder">Ringfolder (SMT, Working)</a></h3>
<ul>
	<li>
		<strong>Ring Modulator & Wavefolder</strong>
		<br><a href="https://www.youtube.com/watch?v=gYwEPNSfJLE">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n9d138d74b39d">Original Build Documentation</a>
	</li>
</ul>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/HAGIWO/Multiout">Multiout (SMT, Working)</a></h3>
<ul>
	<li>
		<strong>Sequencer Roland SH-101 type</strong>
		<br><a href="https://www.youtube.com/watch?v=--qb_QYZrTk&t">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n80f4baf81226">Original Build Documentation</a>
	</li>
	<li>
		<strong>Dual quantizer and Envelope generator</strong>
		<br><a href="https://www.youtube.com/watch?v=6FJpljEYZq4">YouTube</a>
		<br><a href="https://note.com/solder_state/n/nb8b9a2f212a2">Original Build Documentation</a>
	</li>
</ul>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/HAGIWO/Display">Display (SMT, Working)</a></h3>
<ul>
	<li>
		<strong>Oscilloscope & Spectrum analyzer</strong>
		<br><a href="https://www.youtube.com/watch?v=yAes5pS3ZTo">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n6b4cc8d1c6b9">Original Build Documentation</a>
	</li>
</ul>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/HAGIWO/Arduino%20VCO">Arduino VCO (SMT, WIP)</a></h3>
<ul>
	<li>
		<strong>Additive VCO</strong>
		<br><a href="https://www.youtube.com/watch?v=wjWOJ-h5w5w">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n30b3a8737b1e">Original Build Documentation</a>
	</li>
	<li>
		<strong>Chord VCO</strong>
		<br><a href="https://www.youtube.com/watch?v=Ikhd3OmoN40">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n681d2e07e324">Original Build Documentation</a>
	</li>
	<li>
		<strong>FM VCO</strong>
		<br><a href="https://www.youtube.com/watch?v=NZKacfP9aNI">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n88317851a4c7">Original Build Documentation</a>
	</li>
</ul>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/HAGIWO/4Ch%20Sample%20Player">4Ch Sample Player (SMT, WIP)</a></h3>
<ul>
	<li>
		<strong>TR-808/909 sample play , 4CH wav trigger</strong>
		<br><a href="https://www.youtube.com/watch?v=7Vcwk8KYZM8&t">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n0209d16d0d08">Original Build Documentation</a>
	</li>
</ul>
