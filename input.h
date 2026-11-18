#ifndef LAB4_VARIANT6_INPUT_H_
#define LAB4_VARIANT6_INPUT_H_

#include <string>

// Reads a finite floating-point number. Repeats the prompt after invalid input.
double ReadDouble(const std::string& prompt);

// Reads an integer menu choice. Repeats the prompt after invalid input.
int ReadInt(const std::string& prompt);

#endif  // LAB4_VARIANT6_INPUT_H_
