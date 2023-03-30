/**
 * @file GenerativeSeq_SyncLFO.ino
 * @author Adam Wonak (https://github.com/awonak/)
 * @brief Generative Sequencer firmware for HAGIWO Sync Mod LFO (demo: https://youtu.be/okj47TcXJXg)
 * @version 0.1
 * @date 2023-03-26
 *
 * @copyright Copyright (c) 2023
 *
 */

// Install the "AVR Standard C Time Libaray", used for faster PWM frequencies
// and smoother analog cv output.
#include <avr/io.h>

// GPIO Pin mapping for knobs and jacks.
#define P1 0 // Probability
#define P2 1 // Sequence step length
#define P3 3 // Amplitiude
#define P4 5 // Refrain count

#define CLOCK_IN 3
#define PWM_OUT 10

// Uncomment to print state to serial monitoring output.
// #define DEBUG

// State variables.
bool clock_in, old_clock_in;
int probability, steps, amplititude;

int output;
int step;
int refrain_counter;
int rand_val;

int refrain = 1;
int refrain_max = 4;
int pattern_size_max = 16;
int cv_max = 1023;
int cv_pattern[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int pattern_options[8] = {1, 2, 3, 4, 6, 8, 12, 16};

void setup()
{
    Serial.begin(9600);
    pinMode(CLOCK_IN, INPUT);
    pinMode(PWM_OUT, OUTPUT);

    // Fast PWM configuration.
    TCCR1A = 0b00100001;
    TCCR1B = 0b00100001;
    delay(50);

    // Inititialize random values in sequence.
    for (int i = 0; i < pattern_size_max; i++)
    {
        cv_pattern[i] = random(cv_max);
    }
}

void loop()
{
    // Read clock input.
    old_clock_in = clock_in;
    clock_in = digitalRead(CLOCK_IN);

    // Check for new clock trigger.
    if (old_clock_in == 0 && clock_in == 1)
    {
        // Increment the current sequence step.
        // Right shift to scale input to a range of 8.
        steps = pattern_options[(analogRead(P2) >> 7)];
        step = (step + 1) % steps;

        // Increment Refrain at the first step of the sequence.
        if (step == 0)
        {
            // Right shift to scale input to a range of 4.
            refrain = (analogRead(P4) >> 8) + 1;
            refrain_counter = (refrain_counter + 1) % refrain;
        }

        // Check probability and refrain counter to see if the current step
        // should be updated.
        probability = analogRead(P1);
        rand_val = random(cv_max);
        if (refrain_counter == 0 && probability > rand_val)
        {
            cv_pattern[step] = random(cv_max);
        }

        debug();
    }

    // Scale amplititude down to a range of 255 to match PWM range.
    amplititude = analogRead(P3) >> 2;

    // Update PWM CV output value.
    output = map(cv_pattern[step], 0, cv_max, 0, amplititude);
    analogWrite(PWM_OUT, output);
}

void debug()
{
#ifdef DEBUG
    Serial.println(
        "Prob: " + String(probability) + " > " + String(rand_val) + "\tValue: " + String(cv_pattern[step]) + "\tRefrain: [" + String(refrain_counter) + "/" + String(refrain) + "]" + "\tSteps: [" + String(step) + "/" + String(steps) + "]" + "\tAmp: " + String(amplititude));
#endif
}
