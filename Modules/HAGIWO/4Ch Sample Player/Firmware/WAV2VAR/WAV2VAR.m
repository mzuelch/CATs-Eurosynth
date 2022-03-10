function retval = WAV2VAR(inputfile, outputfile, bits, rate, frames, start, showfigure = false)
	[original, sr] = audioread(inputfile);
	original = resample(original, rate, sr);
	output = zeros(frames,1);
	if length(original)<(frames+start)
		original = postpad (original, length(output));
	endif
	output = original(start:start+frames-1);
	factor = max([abs(max(output)) abs(min(output))]);
	output = abs(round(output/factor*2^(bits-1)+2^(bits-1)-1));		
	retval = "{";
	retval = strcat(retval, num2str(output', "%d, "));
	retval = strtrunc(retval, length(retval)-1);
	retval = strcat(retval, "}");
	of_id = fopen(outputfile, 'w');
	fprintf(of_id, retval);
	fclose(of_id);
	if (showfigure)
		f = plot(output);
	endif
	retval = output;
endfunction
