<h1>CAT's Eurosynth</h1>
<p>This is my repository for my analog synth eurorack compatible modules. Files given via the "Gerber" directories are actual production data used for my own prototyping. Bugs are to be expected. Corrections for finished boards marked as "working" are done in KiCAD only.</p>
<p>Please read the "Known Issues" section given in this repository as "ReadMe.md" whenever appropriate.</p>
<h1>License</h1>
<p>Code (AVR projects): GPL3.0.</p>
<p>Code (STM32F projects): MIT license.</p>
<p>Hardware: CC BY-NC-SA 4.0</p>
<img src="https://mirrors.creativecommons.org/presskit/buttons/88x31/svg/by-nc-sa.svg">
<p>unless specified otherwise.</p>
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
<ul>
	<li><a href="https://github.com/mzuelch/CATs-Eurosynth/blob/main/Libraries/Symbols/ReadMe.md">Symbols</a></li>
	<li><a href="https://github.com/mzuelch/CATs-Eurosynth/blob/main/Libraries/Footprints/ReadMe.md">Footprints</a></li>
	<li><a href="https://github.com/mzuelch/CATs-Eurosynth/blob/main/Libraries/3D%20Shapes/ReadMe.md">3D Shapes</a></li>
</ul>
<h1>Published Designs</p>
<h2>Standard Line</h2>
<p>Collection of modules with no regard to size. These designs are based on either my own ideas and mistakes or published in so many places I can't figure out the original source.</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Power%20Module">Power Module (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Atari%20Punk%20Console">Atari Punk Console (THT, Working)</a></h3>
<h3><s>Baby8 Sequencer (THT, Rework)</s></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/4Ch%20Mixer">4Ch Mixer (SMT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Clock%20Divider">Clock Divider (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Abakus">Abakus (SMT/THT, Working)</a></h3>
<h3><s>Manual Gate (THT, Rework)</s></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Envelope%20Follower">Envelope Follower (THT, WIP)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Vactrol%20VCF">Vactrol VCF (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Standard%20Line/Classic%20ADSR">Classic ADSR (SMT, Working)</a></h3>
<h2>Slim Line</h2>
<p>Slim Modules to cope with the ever increasing lamentations from my bandmates and wife. Also these designs are based on either my own ideas and mistakes or published in so many places I can't figure out the original source.</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Attenuator">Single Attenuator (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Buffered%20Multiple">Buffered Multiple (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Sample%26Hold">Dual Sample&Hold (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Precision%20Adder">Precision Adder (SMT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Rectifier">Rectifier (THT, WIP)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/VCA">VCA (THT, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Slimline%20Clock%Divider">Clock Divider (SMD, Working)</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Slim%20Line/Slimline%20Clock%Divider%NG">Clock Divider Next Generation (SMD, Working)</a></h3>

<h2>Purely Mechanical</h2>
<p>Some purely mechanical projects - blinds, cases,...</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Mechanicals/Blinds/1TE">1TE Blind Panel</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Mechanicals/Blinds/3TE">3TE Blind Panel</a></h3>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Mechanicals/Cases">Cases</a></h3>

<h2>MFOS Clones</h2>
<p>The basic electronic design was made by <a href="http://musicfromouterspace.com/">Music From Outer Space</a>.
The remodelling in KiCAD, slight adaptation, PCB layout and frontpanel designs are based on my own faults</p>
<p>RIP Ray Wilson</p>
<h3>Dual VCA #2 (THT, Working)</h3>
<ul>
	<li><a href="http://musicfromouterspace.com/analogsynth_new/OLDIESBUTGOODIES/VCA/dualvca-2.html">Original Build Documentation</a></li>
</ul>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/MFOS/Noise%20Cornucopia">Noise Cornucopia (THT, Working)</a></h3>
<ul>
	<li><a href="http://musicfromouterspace.com/analogsynth_new/NOISECORNREV01/NOISECORNREV01.php">Original Build Documentation</a></li>
</ul>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/MFOS/Eight%20Stage%20Phase%20Shifter">Eight Stage Phase Shifter (SMT, Working)</a></h3>
<ul>
	<li><a href="http://musicfromouterspace.com/analogsynth_new/PHASESHIFTER2007/PHASESHIFTER2007.php">Original Build Documentation</a></li>
</ul>

<h2>YuSynth Clones</h2>
<p>The basic electronic design was made by <a href="https://yusynth.net">YuSynth</a>.
The remodelling in KiCAD, slight adaptation (especially changes to +/-12V), PCB layout and frontpanel designs are based on my own faults.</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/YuSynth/Improved%20Steiner%20VCF">Improved Steiner VCF (SMT, Working)</a></h3>
<ul>
	<li><a href="http://yusynth.net/Modular/EN/STEINERVCF/index-v2.html">Original Build Documentation</a></li>
</ul>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/YuSynth/Balanced%20Modulator"><b>Single</b> balanced Modulator (THT/SMT, WIP)</a></h3>
<ul>
	<li><a href="http://yusynth.net/Modular/EN/RINGMOD/index.html">Original Build Documentation</a></li>
</ul>

<h2>Haraldswerk</h2>
<p>The basic electronic design was made by <a href="https://www.haraldswerk.de/">Haraldswerk</a>.
The remodelling in KiCAD, slight adaptation (especially to Eurorack format), PCB layout and frontpanel designs are based on my own faults.</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/Haraldswerk/NGF-E%20LFO/">Next Generation Formant LFO (THT, Working)</a></h3>
<ul>
	<li><a href="https://www.haraldswerk.de/NGF_E/NGF_E_LFO/NGF_E_LFO.html">Original Build Documentation</a></li>
</ul>

<h2>Ken Stone / Cat Girl Synth</h2>
<p>The basic electronic design was made by <a href="https://sdiy.info/wiki/CatGirl_Synth">Ken Stone aka Cat Girl Synth</a>.
The remodelling in KiCAD, slight adaptation (especially changes to +/-12V), PCB layout and frontpanel designs are based on my own faults</p>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/CGS/Analog%20Switch%20Matrix">Analog Switch Matrix (THT/SMT, Working)</a></h3>
<ul>
	<li><a href="https://sdiy.info/wiki/CGS_analog_switch_matrix">Original Build Documentation</a></li>
</ul>

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
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/HAGIWO/Arduino%20VCO">Arduino VCO (SMT, Working)</a></h3>
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
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/HAGIWO/4Ch%20Sample%20Player">4Ch Sample Player (SMT, Working)</a></h3>
<ul>
	<li>
		<strong>TR-808/909 sample play , 4CH wav trigger</strong>
		<br><a href="https://www.youtube.com/watch?v=7Vcwk8KYZM8&t">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n0209d16d0d08">Original Build Documentation</a>
	</li>
</ul>
<h3><a href="https://github.com/mzuelch/CATs-Eurosynth/tree/main/Modules/HAGIWO/Sync%20LFO">Sync LFO (SMT, WIP)</a></h3>
<ul>
	<li>
		<strong>Clock Sync LFO</strong>
		<br><a href="https://www.youtube.com/watch?v=m64jyVz2w3M">YouTube</a>
		<br><a href="https://note.com/solder_state/n/n4c600f2431c3">Original Build Documentation</a>
	</li>
</ul>