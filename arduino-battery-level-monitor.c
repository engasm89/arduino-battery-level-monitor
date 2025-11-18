#include <stdio.h> // Include I/O for battery logs

// Simulate analog reading and convert to percentage
int to_percent(int adc) { // Map ADC 0..1023 to 0..100
  return (adc * 100) / 1023; // Linear mapping
} // End to_percent

// Convert ADC reading to voltage assuming divider and reference
double to_voltage(int adc, double vref, double scale) { // ADC->volts
  double v = (double)adc / 1023.0 * vref; // Raw ADC volts
  return v * scale; // Account for divider scale
}

int main(void) { // Entry
  printf("Arduino Battery Level Monitor\n"); // Title
  int adc = 850; // Example ADC value
  int pct = to_percent(adc); // Convert to percent
  double volts = to_voltage(adc, 5.0, 2.0); // Example: 2:1 divider, 5V ref
  const char *state = (pct > 80)?"FULL":(pct > 40)?"MED":(pct > 20)?"LOW":"CRITICAL"; // State
  printf("adc=%d percent=%d%% voltage=%.2fV state=%s\n", adc, pct, volts, state); // Log
  return 0; // Exit
} // End main

