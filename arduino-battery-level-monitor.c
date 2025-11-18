/*
 * Course: Arduino Battery Level Monitor
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Arduino Battery Level Monitor" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/arduino-battery-level-monitor/
 * Repository: https://github.com/engasm89/arduino-battery-level-monitor
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

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

int main(void) { // Program entry point
  printf("Arduino Battery Level Monitor\n"); // Title
  int adc = 850; // Example ADC value
  int pct = to_percent(adc); // Convert to percent
  double volts = to_voltage(adc, 5.0, 2.0); // Example: 2:1 divider, 5V ref
  const char *state = (pct > 80)?"FULL":(pct > 40)?"MED":(pct > 20)?"LOW":"CRITICAL"; // State
  printf("adc=%d percent=%d%% voltage=%.2fV state=%s\n", adc, pct, volts, state); // Log
  return 0; // Exit
} // End of main function

