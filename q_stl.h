 #pragma once

// String compare method.
int32 Q_strcmp(uint8* str1, uint8* str2); 

// Converts Numbers in String to the actual numerical values
// Hexidecimal, decimal, positive number, and negative numbers
int32 Q_atoi(uint8 *str);

// Copies one string to different destination
void Q_strcpy(uint8 *dest, uint8 *src);

// Copies a certain amount of bites from one string to another
void Q_strncpy(uint8 *dest, uint8 *src, int32 count);

// Gets the lenth of a string
int32 Q_strlen(uint8 *str);

