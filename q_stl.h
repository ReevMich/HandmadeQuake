 #pragma once

// String compare method.
int32 Q_strcmp(const char *str1, const char *str2); 

// Converts Numbers in String to the actual numerical values
// Hexidecimal, decimal, positive number, and negative numbers
int32 Q_atoi(const char *str);

// Copies one string to different destination
void Q_strcpy(char *dest, const char *src);

// Copies a certain amount of bites from one string to another
void Q_strncpy(char *dest, const char *src, int32 count);

// Gets the lenth of a string
int32 Q_strlen(char *str);

