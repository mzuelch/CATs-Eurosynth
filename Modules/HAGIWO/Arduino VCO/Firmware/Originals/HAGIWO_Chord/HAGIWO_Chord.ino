#include <MozziGuts.h>
#include <Oscil.h> // oscillator template

#include <tables/saw2048_int8.h> // saw table for oscillator
#include <tables/square_no_alias512_int8.h> // saw table for oscillator
#include <tables/triangle_hermes_2048_int8.h> // saw table for oscillator
#include <tables/sin2048_int8.h> // sine table for oscillator
#include <tables/waveshape_chebyshev_3rd_256_int8.h> // sine table for oscillator
#include <tables/halfsin256_uint8.h> // sine table for oscillator
#include <tables/waveshape_sigmoid_int8.h> // sine table for oscillator
#include <tables/phasor256_int8.h> // sine table for oscillator

Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aSaw1(SAW2048_DATA);
Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aSaw2(SAW2048_DATA);
Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aSaw3(SAW2048_DATA);
Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aSaw4(SAW2048_DATA);
Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aSaw5(SAW2048_DATA);

Oscil <SQUARE_NO_ALIAS512_NUM_CELLS, AUDIO_RATE> aSqu1(SQUARE_NO_ALIAS512_DATA);
Oscil <SQUARE_NO_ALIAS512_NUM_CELLS, AUDIO_RATE> aSqu2(SQUARE_NO_ALIAS512_DATA);
Oscil <SQUARE_NO_ALIAS512_NUM_CELLS, AUDIO_RATE> aSqu3(SQUARE_NO_ALIAS512_DATA);
Oscil <SQUARE_NO_ALIAS512_NUM_CELLS, AUDIO_RATE> aSqu4(SQUARE_NO_ALIAS512_DATA);
Oscil <SQUARE_NO_ALIAS512_NUM_CELLS, AUDIO_RATE> aSqu5(SQUARE_NO_ALIAS512_DATA);

Oscil <TRIANGLE_HERMES_2048_NUM_CELLS, AUDIO_RATE> aTri1(TRIANGLE_HERMES_2048_DATA);
Oscil <TRIANGLE_HERMES_2048_NUM_CELLS, AUDIO_RATE> aTri2(TRIANGLE_HERMES_2048_DATA);
Oscil <TRIANGLE_HERMES_2048_NUM_CELLS, AUDIO_RATE> aTri3(TRIANGLE_HERMES_2048_DATA);
Oscil <TRIANGLE_HERMES_2048_NUM_CELLS, AUDIO_RATE> aTri4(TRIANGLE_HERMES_2048_DATA);
Oscil <TRIANGLE_HERMES_2048_NUM_CELLS, AUDIO_RATE> aTri5(TRIANGLE_HERMES_2048_DATA);

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin1(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin2(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin3(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin4(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin5(SIN2048_DATA);

Oscil <CHEBYSHEV_3RD_256_NUM_CELLS, AUDIO_RATE> aChb1(CHEBYSHEV_3RD_256_DATA);
Oscil <CHEBYSHEV_3RD_256_NUM_CELLS, AUDIO_RATE> aChb2(CHEBYSHEV_3RD_256_DATA);
Oscil <CHEBYSHEV_3RD_256_NUM_CELLS, AUDIO_RATE> aChb3(CHEBYSHEV_3RD_256_DATA);
Oscil <CHEBYSHEV_3RD_256_NUM_CELLS, AUDIO_RATE> aChb4(CHEBYSHEV_3RD_256_DATA);
Oscil <CHEBYSHEV_3RD_256_NUM_CELLS, AUDIO_RATE> aChb5(CHEBYSHEV_3RD_256_DATA);

Oscil <HALFSIN256_NUM_CELLS, AUDIO_RATE> ahSin1(HALFSIN256_DATA);
Oscil <HALFSIN256_NUM_CELLS, AUDIO_RATE> ahSin2(HALFSIN256_DATA);
Oscil <HALFSIN256_NUM_CELLS, AUDIO_RATE> ahSin3(HALFSIN256_DATA);
Oscil <HALFSIN256_NUM_CELLS, AUDIO_RATE> ahSin4(HALFSIN256_DATA);
Oscil <HALFSIN256_NUM_CELLS, AUDIO_RATE> ahSin5(HALFSIN256_DATA);

Oscil <WAVESHAPE_SIGMOID_NUM_CELLS, AUDIO_RATE> aSig1(WAVESHAPE_SIGMOID_DATA);
Oscil <WAVESHAPE_SIGMOID_NUM_CELLS, AUDIO_RATE> aSig2(WAVESHAPE_SIGMOID_DATA);
Oscil <WAVESHAPE_SIGMOID_NUM_CELLS, AUDIO_RATE> aSig3(WAVESHAPE_SIGMOID_DATA);
Oscil <WAVESHAPE_SIGMOID_NUM_CELLS, AUDIO_RATE> aSig4(WAVESHAPE_SIGMOID_DATA);
Oscil <WAVESHAPE_SIGMOID_NUM_CELLS, AUDIO_RATE> aSig5(WAVESHAPE_SIGMOID_DATA);

Oscil <PHASOR256_NUM_CELLS, AUDIO_RATE> aPha1(PHASOR256_DATA);
Oscil <PHASOR256_NUM_CELLS, AUDIO_RATE> aPha2(PHASOR256_DATA);
Oscil <PHASOR256_NUM_CELLS, AUDIO_RATE> aPha3(PHASOR256_DATA);
Oscil <PHASOR256_NUM_CELLS, AUDIO_RATE> aPha4(PHASOR256_DATA);
Oscil <PHASOR256_NUM_CELLS, AUDIO_RATE> aPha5(PHASOR256_DATA);
#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable
#define AUDIO_MODE HIFI

int freq1 = 110;//base freq
int voct = 1000;//external V/OCT LSB

int freqv1 = 440;//apply voct
int freqv2 = 440;
int freqv3 = 440;
int freqv4 = 440;
int freqv5 = 440;

byte note1 = 0;//Root
byte note2 = 0;//2nd
byte note3 = 0;//3rd
byte note4 = 0;//4th
byte note5 = 0;//Root

byte inv_aply1 = 0; //0 = no inv , 1 = inv , Root
byte inv_aply2 = 0; //2nd
byte inv_aply3 = 0; //3rd
byte inv_aply4 = 0; //4th
bool inv_aply5 = 0; //0 = no output root sound , 1 = output root sound

int inv = 0;
int inv_knob = 0;
int chord = 0;
byte wave = 0;//0=saw,1=squ,2=tri,3=sin,etc...

const static float voctpow[1024] PROGMEM = {
 0,  0.004882, 0.009765, 0.014648, 0.019531, 0.024414, 0.029296, 0.034179, 0.039062, 0.043945, 0.048828, 0.05371,  0.058593, 0.063476, 0.068359, 0.073242, 0.078125, 0.083007, 0.08789,  0.092773, 0.097656, 0.102539, 0.107421, 0.112304, 0.117187, 0.12207,  0.126953, 0.131835, 0.136718, 0.141601, 0.146484, 0.151367, 0.15625,  0.161132, 0.166015, 0.170898, 0.175781, 0.180664, 0.185546, 0.190429, 0.195312, 0.200195, 0.205078, 0.20996,  0.214843, 0.219726, 0.224609, 0.229492, 0.234375, 0.239257, 0.24414,  0.249023, 0.253906, 0.258789, 0.263671, 0.268554, 0.273437, 0.27832,  0.283203, 0.288085, 0.292968, 0.297851, 0.302734, 0.307617, 0.3125, 0.317382, 0.322265, 0.327148, 0.332031, 0.336914, 0.341796, 0.346679, 0.351562, 0.356445, 0.361328, 0.36621,  0.371093, 0.375976, 0.380859, 0.385742, 0.390625, 0.395507, 0.40039,  0.405273, 0.410156, 0.415039, 0.419921, 0.424804, 0.429687, 0.43457,  0.439453, 0.444335, 0.449218, 0.454101, 0.458984, 0.463867, 0.46875,  0.473632, 0.478515, 0.483398, 0.488281, 0.493164, 0.498046, 0.502929, 0.507812, 0.512695, 0.517578, 0.52246,  0.527343, 0.532226, 0.537109, 0.541992, 0.546875, 0.551757, 0.55664,  0.561523, 0.566406, 0.571289, 0.576171, 0.581054, 0.585937, 0.59082,  0.595703, 0.600585, 0.605468, 0.610351, 0.615234, 0.620117, 0.625,  0.629882, 0.634765, 0.639648, 0.644531, 0.649414, 0.654296, 0.659179, 0.664062, 0.668945, 0.673828, 0.67871,  0.683593, 0.688476, 0.693359, 0.698242, 0.703125, 0.708007, 0.71289,  0.717773, 0.722656, 0.727539, 0.732421, 0.737304, 0.742187, 0.74707,  0.751953, 0.756835, 0.761718, 0.766601, 0.771484, 0.776367, 0.78125,  0.786132, 0.791015, 0.795898, 0.800781, 0.805664, 0.810546, 0.815429, 0.820312, 0.825195, 0.830078, 0.83496,  0.839843, 0.844726, 0.849609, 0.854492, 0.859375, 0.864257, 0.86914,  0.874023, 0.878906, 0.883789, 0.888671, 0.893554, 0.898437, 0.90332,  0.908203, 0.913085, 0.917968, 0.922851, 0.927734, 0.932617, 0.9375, 0.942382, 0.947265, 0.952148, 0.957031, 0.961914, 0.966796, 0.971679, 0.976562, 0.981445, 0.986328, 0.99121,  0.996093, 1.000976, 1.005859, 1.010742, 1.015625, 1.020507, 1.02539,  1.030273, 1.035156, 1.040039, 1.044921, 1.049804, 1.054687, 1.05957,  1.064453, 1.069335, 1.074218, 1.079101, 1.083984, 1.088867, 1.09375,  1.098632, 1.103515, 1.108398, 1.113281, 1.118164, 1.123046, 1.127929, 1.132812, 1.137695, 1.142578, 1.14746,  1.152343, 1.157226, 1.162109, 1.166992, 1.171875, 1.176757, 1.18164,  1.186523, 1.191406, 1.196289, 1.201171, 1.206054, 1.210937, 1.21582,  1.220703, 1.225585, 1.230468, 1.235351, 1.240234, 1.245117, 1.25, 1.254882, 1.259765, 1.264648, 1.269531, 1.274414, 1.279296, 1.284179, 1.289062, 1.293945, 1.298828, 1.30371,  1.308593, 1.313476, 1.318359, 1.323242, 1.328125, 1.333007, 1.33789,  1.342773, 1.347656, 1.352539, 1.357421, 1.362304, 1.367187, 1.37207,  1.376953, 1.381835, 1.386718, 1.391601, 1.396484, 1.401367, 1.40625,  1.411132, 1.416015, 1.420898, 1.425781, 1.430664, 1.435546, 1.440429, 1.445312, 1.450195, 1.455078, 1.45996,  1.464843, 1.469726, 1.474609, 1.479492, 1.484375, 1.489257, 1.49414,  1.499023, 1.503906, 1.508789, 1.513671, 1.518554, 1.523437, 1.52832,  1.533203, 1.538085, 1.542968, 1.547851, 1.552734, 1.557617, 1.5625, 1.567382, 1.572265, 1.577148, 1.582031, 1.586914, 1.591796, 1.596679, 1.601562, 1.606445, 1.611328, 1.61621,  1.621093, 1.625976, 1.630859, 1.635742, 1.640625, 1.645507, 1.65039,  1.655273, 1.660156, 1.665039, 1.669921, 1.674804, 1.679687, 1.68457,  1.689453, 1.694335, 1.699218, 1.704101, 1.708984, 1.713867, 1.71875,  1.723632, 1.728515, 1.733398, 1.738281, 1.743164, 1.748046, 1.752929, 1.757812, 1.762695, 1.767578, 1.77246,  1.777343, 1.782226, 1.787109, 1.791992, 1.796875, 1.801757, 1.80664,  1.811523, 1.816406, 1.821289, 1.826171, 1.831054, 1.835937, 1.84082,  1.845703, 1.850585, 1.855468, 1.860351, 1.865234, 1.870117, 1.875,  1.879882, 1.884765, 1.889648, 1.894531, 1.899414, 1.904296, 1.909179, 1.914062, 1.918945, 1.923828, 1.92871,  1.933593, 1.938476, 1.943359, 1.948242, 1.953125, 1.958007, 1.96289,  1.967773, 1.972656, 1.977539, 1.982421, 1.987304, 1.992187, 1.99707,  2.001953, 2.006835, 2.011718, 2.016601, 2.021484, 2.026367, 2.03125,  2.036132, 2.041015, 2.045898, 2.050781, 2.055664, 2.060546, 2.065429, 2.070312, 2.075195, 2.080078, 2.08496,  2.089843, 2.094726, 2.099609, 2.104492, 2.109375, 2.114257, 2.11914,  2.124023, 2.128906, 2.133789, 2.138671, 2.143554, 2.148437, 2.15332,  2.158203, 2.163085, 2.167968, 2.172851, 2.177734, 2.182617, 2.1875, 2.192382, 2.197265, 2.202148, 2.207031, 2.211914, 2.216796, 2.221679, 2.226562, 2.231445, 2.236328, 2.24121,  2.246093, 2.250976, 2.255859, 2.260742, 2.265625, 2.270507, 2.27539,  2.280273, 2.285156, 2.290039, 2.294921, 2.299804, 2.304687, 2.30957,  2.314453, 2.319335, 2.324218, 2.329101, 2.333984, 2.338867, 2.34375,  2.348632, 2.353515, 2.358398, 2.363281, 2.368164, 2.373046, 2.377929, 2.382812, 2.387695, 2.392578, 2.39746,  2.402343, 2.407226, 2.412109, 2.416992, 2.421875, 2.426757, 2.43164,  2.436523, 2.441406, 2.446289, 2.451171, 2.456054, 2.460937, 2.46582,  2.470703, 2.475585, 2.480468, 2.485351, 2.490234, 2.495117, 2.5,  2.504882, 2.509765, 2.514648, 2.519531, 2.524414, 2.529296, 2.534179, 2.539062, 2.543945, 2.548828, 2.55371,  2.558593, 2.563476, 2.568359, 2.573242, 2.578125, 2.583007, 2.58789,  2.592773, 2.597656, 2.602539, 2.607421, 2.612304, 2.617187, 2.62207,  2.626953, 2.631835, 2.636718, 2.641601, 2.646484, 2.651367, 2.65625,  2.661132, 2.666015, 2.670898, 2.675781, 2.680664, 2.685546, 2.690429, 2.695312, 2.700195, 2.705078, 2.70996,  2.714843, 2.719726, 2.724609, 2.729492, 2.734375, 2.739257, 2.74414,  2.749023, 2.753906, 2.758789, 2.763671, 2.768554, 2.773437, 2.77832,  2.783203, 2.788085, 2.792968, 2.797851, 2.802734, 2.807617, 2.8125, 2.817382, 2.822265, 2.827148, 2.832031, 2.836914, 2.841796, 2.846679, 2.851562, 2.856445, 2.861328, 2.86621,  2.871093, 2.875976, 2.880859, 2.885742, 2.890625, 2.895507, 2.90039,  2.905273, 2.910156, 2.915039, 2.919921, 2.924804, 2.929687, 2.93457,  2.939453, 2.944335, 2.949218, 2.954101, 2.958984, 2.963867, 2.96875,  2.973632, 2.978515, 2.983398, 2.988281, 2.993164, 2.998046, 3.002929, 3.007812, 3.012695, 3.017578, 3.02246,  3.027343, 3.032226, 3.037109, 3.041992, 3.046875, 3.051757, 3.05664,  3.061523, 3.066406, 3.071289, 3.076171, 3.081054, 3.085937, 3.09082,  3.095703, 3.100585, 3.105468, 3.110351, 3.115234, 3.120117, 3.125,  3.129882, 3.134765, 3.139648, 3.144531, 3.149414, 3.154296, 3.159179, 3.164062, 3.168945, 3.173828, 3.17871,  3.183593, 3.188476, 3.193359, 3.198242, 3.203125, 3.208007, 3.21289,  3.217773, 3.222656, 3.227539, 3.232421, 3.237304, 3.242187, 3.24707,  3.251953, 3.256835, 3.261718, 3.266601, 3.271484, 3.276367, 3.28125,  3.286132, 3.291015, 3.295898, 3.300781, 3.305664, 3.310546, 3.315429, 3.320312, 3.325195, 3.330078, 3.33496,  3.339843, 3.344726, 3.349609, 3.354492, 3.359375, 3.364257, 3.36914,  3.374023, 3.378906, 3.383789, 3.388671, 3.393554, 3.398437, 3.40332,  3.408203, 3.413085, 3.417968, 3.422851, 3.427734, 3.432617, 3.4375, 3.442382, 3.447265, 3.452148, 3.457031, 3.461914, 3.466796, 3.471679, 3.476562, 3.481445, 3.486328, 3.49121,  3.496093, 3.500976, 3.505859, 3.510742, 3.515625, 3.520507, 3.52539,  3.530273, 3.535156, 3.540039, 3.544921, 3.549804, 3.554687, 3.55957,  3.564453, 3.569335, 3.574218, 3.579101, 3.583984, 3.588867, 3.59375,  3.598632, 3.603515, 3.608398, 3.613281, 3.618164, 3.623046, 3.627929, 3.632812, 3.637695, 3.642578, 3.64746,  3.652343, 3.657226, 3.662109, 3.666992, 3.671875, 3.676757, 3.68164,  3.686523, 3.691406, 3.696289, 3.701171, 3.706054, 3.710937, 3.71582,  3.720703, 3.725585, 3.730468, 3.735351, 3.740234, 3.745117, 3.75, 3.754882, 3.759765, 3.764648, 3.769531, 3.774414, 3.779296, 3.784179, 3.789062, 3.793945, 3.798828, 3.80371,  3.808593, 3.813476, 3.818359, 3.823242, 3.828125, 3.833007, 3.83789,  3.842773, 3.847656, 3.852539, 3.857421, 3.862304, 3.867187, 3.87207,  3.876953, 3.881835, 3.886718, 3.891601, 3.896484, 3.901367, 3.90625,  3.911132, 3.916015, 3.920898, 3.925781, 3.930664, 3.935546, 3.940429, 3.945312, 3.950195, 3.955078, 3.95996,  3.964843, 3.969726, 3.974609, 3.979492, 3.984375, 3.989257, 3.99414,  3.999023, 4.003906, 4.008789, 4.013671, 4.018554, 4.023437, 4.02832,  4.033203, 4.038085, 4.042968, 4.047851, 4.052734, 4.057617, 4.0625, 4.067382, 4.072265, 4.077148, 4.082031, 4.086914, 4.091796, 4.096679, 4.101562, 4.106445, 4.111328, 4.11621,  4.121093, 4.125976, 4.130859, 4.135742, 4.140625, 4.145507, 4.15039,  4.155273, 4.160156, 4.165039, 4.169921, 4.174804, 4.179687, 4.18457,  4.189453, 4.194335, 4.199218, 4.204101, 4.208984, 4.213867, 4.21875,  4.223632, 4.228515, 4.233398, 4.238281, 4.243164, 4.248046, 4.252929, 4.257812, 4.262695, 4.267578, 4.27246,  4.277343, 4.282226, 4.287109, 4.291992, 4.296875, 4.301757, 4.30664,  4.311523, 4.316406, 4.321289, 4.326171, 4.331054, 4.335937, 4.34082,  4.345703, 4.350585, 4.355468, 4.360351, 4.365234, 4.370117, 4.375,  4.379882, 4.384765, 4.389648, 4.394531, 4.399414, 4.404296, 4.409179, 4.414062, 4.418945, 4.423828, 4.42871,  4.433593, 4.438476, 4.443359, 4.448242, 4.453125, 4.458007, 4.46289,  4.467773, 4.472656, 4.477539, 4.482421, 4.487304, 4.492187, 4.49707,  4.501953, 4.506835, 4.511718, 4.516601, 4.521484, 4.526367, 4.53125,  4.536132, 4.541015, 4.545898, 4.550781, 4.555664, 4.560546, 4.565429, 4.570312, 4.575195, 4.580078, 4.58496,  4.589843, 4.594726, 4.599609, 4.604492, 4.609375, 4.614257, 4.61914,  4.624023, 4.628906, 4.633789, 4.638671, 4.643554, 4.648437, 4.65332,  4.658203, 4.663085, 4.667968, 4.672851, 4.677734, 4.682617, 4.6875, 4.692382, 4.697265, 4.702148, 4.707031, 4.711914, 4.716796, 4.721679, 4.726562, 4.731445, 4.736328, 4.74121,  4.746093, 4.750976, 4.755859, 4.760742, 4.765625, 4.770507, 4.77539,  4.780273, 4.785156, 4.790039, 4.794921, 4.799804, 4.804687, 4.80957,  4.814453, 4.819335, 4.824218, 4.829101, 4.833984, 4.838867, 4.84375,  4.848632, 4.853515, 4.858398, 4.863281, 4.868164, 4.873046, 4.877929, 4.882812, 4.887695, 4.892578, 4.89746,  4.902343, 4.907226, 4.912109, 4.916992, 4.921875, 4.926757, 4.93164,  4.936523, 4.941406, 4.946289, 4.951171, 4.956054, 4.960937, 4.96582,  4.970703, 4.975585, 4.980468, 4.985351, 4.990234, 4.995117
};
const static byte chord_table[8][4]PROGMEM = {
 {  0,  68, 119,  205,  },//Maj
 { 0,  68, 119,  187,  },//Maj7
 { 0,  68, 119,  239,  },//Majadd9
 { 0,  34, 119,  205,  },//sus2
 { 0,  51, 119,  239,  },//minadd9
 { 0,  51, 119,  170,  },//min7
 { 0,  51, 119,  205,  },//min
 { 0,  0,  0,  0,  }//root
};

void setup()
{
 startMozzi(CONTROL_RATE); // :)
}
void updateControl() {
 //chord setting
 chord = (mozziAnalogRead(3) / 128) + (mozziAnalogRead(5) / 128);
 chord = constrain(chord, 0, 7);

 //inversion setting
 inv_knob = mozziAnalogRead(1);
 inv = (inv_knob  / 64)+ (mozziAnalogRead(4) / 64);
 inv = constrain(inv, 0, 15);

 if (inv_knob < 1020) { //when selecting wave , not apply
   switch (inv) {
     case 0:
       inv_aply1 = 0;
       inv_aply2 = 0;
       inv_aply3 = 0;
       inv_aply4 = 0;
       inv_aply5 = 0;
       break;

     case 1:
       inv_aply1 = 1;
       inv_aply2 = 0;
       inv_aply3 = 0;
       inv_aply4 = 0;
       inv_aply5 = 0;
       break;

     case 2:
       inv_aply1 = 1;
       inv_aply2 = 1;
       inv_aply3 = 0;
       inv_aply4 = 0;
       inv_aply5 = 0;
       break;

     case 3:
       inv_aply1 = 1;
       inv_aply2 = 1;
       inv_aply3 = 1;
       inv_aply4 = 0;
       inv_aply5 = 0;
       break;

     case 4:
       inv_aply1 = 1;
       inv_aply2 = 1;
       inv_aply3 = 1;
       inv_aply4 = 1;
       inv_aply5 = 0;
       break;

     case 5:
       inv_aply1 = 2;
       inv_aply2 = 1;
       inv_aply3 = 1;
       inv_aply4 = 1;
       inv_aply5 = 0;
       break;

     case 6:
       inv_aply1 = 2;
       inv_aply2 = 2;
       inv_aply3 = 1;
       inv_aply4 = 1;
       inv_aply5 = 0;
       break;

     case 7:
       inv_aply1 = 2;
       inv_aply2 = 2;
       inv_aply3 = 2;
       inv_aply4 = 1;
       inv_aply5 = 0;
       break;

     case 8:
       inv_aply1 = 2;
       inv_aply2 = 2;
       inv_aply3 = 2;
       inv_aply4 = 1;
       inv_aply5 = 1;
       break;

     case 9:
       inv_aply1 = 2;
       inv_aply2 = 2;
       inv_aply3 = 1;
       inv_aply4 = 1;
       inv_aply5 = 1;
       break;

     case 10:
       inv_aply1 = 2;
       inv_aply2 = 1;
       inv_aply3 = 1;
       inv_aply4 = 1;
       inv_aply5 = 1;
       break;

     case 11:
       inv_aply1 = 1;
       inv_aply2 = 1;
       inv_aply3 = 1;
       inv_aply4 = 1;
       inv_aply5 = 1;
       break;

     case 12:
       inv_aply1 = 1;
       inv_aply2 = 1;
       inv_aply3 = 1;
       inv_aply4 = 0;
       inv_aply5 = 1;
       break;

     case 13:
       inv_aply1 = 1;
       inv_aply2 = 1;
       inv_aply3 = 0;
       inv_aply4 = 0;
       inv_aply5 = 1;
       break;

     case 14:
       inv_aply1 = 1;
       inv_aply2 = 0;
       inv_aply3 = 0;
       inv_aply4 = 0;
       inv_aply5 = 1;
       break;

     case 15:
       inv_aply1 = 0;
       inv_aply2 = 0;
       inv_aply3 = 0;
       inv_aply4 = 0;
       inv_aply5 = 1;
       break;
   }
 }
 //setting chord note
 if (inv_knob < 1020) { //when selecting wave , not apply
   note1 = (pgm_read_byte(&(chord_table[chord][0])));
   note2 = (pgm_read_byte(&(chord_table[chord][1])));
   note3 = (pgm_read_byte(&(chord_table[chord][2])));
   note4 = (pgm_read_byte(&(chord_table[chord][3])));
   note5 = (pgm_read_byte(&(chord_table[chord][0])));
 }

 //OSC frequency knob
 freq1 = mozziAnalogRead(0) / 4 ;

 //set wave
 if (inv_knob >= 1020) { //inv knob max
   wave = (mozziAnalogRead(3) / 128);
 }

 //frequency setting
 voct = mozziAnalogRead(7) ;
 freqv1 = freq1 * pow(2, (pgm_read_float(&(voctpow[voct + 205 * inv_aply1 + note1])))); //ROOT
 freqv2 = freq1 * pow(2, (pgm_read_float(&(voctpow[voct + 205 * inv_aply2 + note2])))); //2nd
 freqv3 = freq1 * pow(2, (pgm_read_float(&(voctpow[voct + 205 * inv_aply3 + note3])))); //3rd
 freqv4 = freq1 * pow(2, (pgm_read_float(&(voctpow[voct + 205 * inv_aply4 + note4])))); //4th
 freqv5 = freq1 * pow(2, (pgm_read_float(&(voctpow[voct + note5])))); //ROOT

 switch (wave) {
   case 0://saw
     aSaw1.setFreq(freqv1); // set the frequency
     aSaw2.setFreq(freqv2);
     aSaw3.setFreq(freqv3);
     aSaw4.setFreq(freqv4);
     aSaw5.setFreq(freqv5);
     break;

   case 1://squ
     aSqu1.setFreq(freqv1); // set the frequency
     aSqu2.setFreq(freqv2);
     aSqu3.setFreq(freqv3);
     aSqu4.setFreq(freqv4);
     aSqu5.setFreq(freqv5);
     break;

   case 2://tri
     aTri1.setFreq(freqv1); // set the frequency
     aTri2.setFreq(freqv2);
     aTri3.setFreq(freqv3);
     aTri4.setFreq(freqv4);
     aTri5.setFreq(freqv5);
     break;

   case 3://sin
     aSin1.setFreq(freqv1); // set the frequency
     aSin2.setFreq(freqv2);
     aSin3.setFreq(freqv3);
     aSin4.setFreq(freqv4);
     aSin5.setFreq(freqv5);
     break;

   case 4://
     aChb1.setFreq(freqv1); // set the frequency
     aChb2.setFreq(freqv2);
     aChb3.setFreq(freqv3);
     aChb4.setFreq(freqv4);
     aChb5.setFreq(freqv5);
     break;

   case 5://
     ahSin1.setFreq(freqv1); // set the frequency
     ahSin2.setFreq(freqv2);
     ahSin3.setFreq(freqv3);
     ahSin4.setFreq(freqv4);
     ahSin5.setFreq(freqv5);
     break;

   case 6://
     aSig1.setFreq(freqv1); // set the frequency
     aSig2.setFreq(freqv2);
     aSig3.setFreq(freqv3);
     aSig4.setFreq(freqv4);
     aSig5.setFreq(freqv5);
     break;

   case 7://
     aPha1.setFreq(freqv1); // set the frequency
     aPha2.setFreq(freqv2);
     aPha3.setFreq(freqv3);
     aPha4.setFreq(freqv4);
     aPha5.setFreq(freqv5);
     break;
 }
}

int updateAudio() {
  int f=8;
 switch (wave) {

   case 0:
     return MonoOutput::from8Bit(aSaw1.next() / f + aSaw2.next() / f + aSaw3.next() / f + aSaw4.next() / f + aSaw5.next() / f * inv_aply5);
     break;

   case 1:
     return MonoOutput::from8Bit(aSqu1.next() / f + aSqu2.next() / f + aSqu3.next() / f + aSqu4.next() / f + aSqu5.next() / f * inv_aply5);
     break;

   case 2:
     return MonoOutput::from8Bit(aTri1.next() / f + aTri2.next() / f + aTri3.next() / f + aTri4.next() / f + aTri5.next() / f * inv_aply5);
     break;

   case 3:
     return MonoOutput::from8Bit(aSin1.next() / f + aSin2.next() / f + aSin3.next() / f + aSin4.next() / f + aSin5.next() / f * inv_aply5);
     break;

   case 4:
     return MonoOutput::from8Bit(aChb1.next() / f + aChb2.next() / f + aChb3.next() / f + aChb4.next() / f + aChb5.next() / f * inv_aply5);
     break;

   case 5:
     return MonoOutput::from8Bit(ahSin1.next() / f + ahSin2.next() / f + ahSin3.next() / f + ahSin4.next() / f + ahSin5.next() / f * inv_aply5);
     break;

   case 6:
     return MonoOutput::from8Bit(aSig1.next() / f + aSig2.next() / f + aSig3.next() / f + aSig4.next() / f + aSig5.next() / f * inv_aply5);
     break;

   case 7:
     return MonoOutput::from8Bit(aPha1.next() / f + aPha2.next() / f + aPha3.next() / f + aPha4.next() / f + aPha5.next() / f * inv_aply5);
     break;

 }
}
void loop() {
 audioHook(); // required here
}
