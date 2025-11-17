#include <stdio.h> // Include I/O for battery logs

// Simulate analog reading and convert to percentage
int to_percent(int adc) { // Map ADC 0..1023 to 0..100
  return (adc * 100) / 1023; // Linear mapping
} // End to_percent

int main(void) { // Entry
  printf("Arduino Battery Level Monitor\n"); // Title
  int adc = 850; // Example ADC value
  int pct = to_percent(adc); // Convert to percent
  printf("adc=%d percent=%d%%\n", adc, pct); // Log
  return 0; // Exit
} // End main

