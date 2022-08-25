<h1>HowTo Convert WAV to Samples</h1>
<p>Due to copyright reasons, actual sample data are omitted in this repository.</p>
<p>WAV2VAR is a little function written in the OCTAVE (https://octave.org/) "m" format to convert any given WAV-File (maybe from a public domain sample pack) to the actual lines to be inserted into the "samples.h" file.</p>
<code>retval = WAV2VAR(inputfile, outputfile, bits, rate, frames, start, showfigure = false)</code>
<h2>Input parameters:</h2>
<list>
	<li>inputfile<br/>Path and filename of the WAV-File to be converted</li>
	<li>outputfile<br/>Path and filename of a target (dummy) file where the converted data are stored.</li>
	<li>bits<br/>Target data format. <bold>8</bold>bit is the only resoution supported by this firmware</li>
	<li>rate<br/>Target bitrate. <bold>32000</bold>bit/s are a good guess for this firmware</li>
	<li>frames<br/>Target sample length. <bold>8000</bold> samples is the only number of frames supported in this firmware</li>
	<li>start<br/>Startframe in the WAV-File to be converted. <bold>1</bold> works for every good sample package</li>
	<li>showfigure<br/><bold>True</bold> to show a graphic representation of the converted waveform. Mostly for debugging.</li>
</list>
<h2>Output values:</h2>
<list>
	<li>retval<br/>Content of the written file for debugging purposes.</li>
</list>

