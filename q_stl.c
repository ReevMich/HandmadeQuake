#include "quakedef.h"

void Q_strcpy(char *dest, const char *src)
{
	// while pointer to src and count is valid copy bites to the destination.
	while (*src) 
	{
		*dest++ = *src++;
	}
	// zero out the end of the string
	*dest = 0;
}

void Q_strncpy(char *dest, const char *src, int32 count)
{

	if (count < 0)
		return;
	
	// while pointer to src and count is valid copy bites to the destination.
	while (*src && count)
	{
		*dest++ = *src++;
		--count;
	}

	// If we have copied over all the bites from src to dest but still 
	// have counts left fill the destination with 0 until count is 0
	while (count)
	{
		*dest++ = 0;
		--count;
	}
}

int32 Q_strlen(const char  *str)
{
	int32 count = 0;

	// while the currentl str location is valid keep counting the 
	// number of character.
	while (str[count])
	{
		++count;
	}
	return count;
}

int32 Q_strcmp(const char* str1, const char* str2)
{
	// While these two character pointers are the same
	// keep looping until *s1 reaches the null terminator 0
	while (*str1 == *str2)
	{
		if (!*str1)
			return 0;

		++str1;
		++str2;
	}

	// Ternary opperator 
	return ((*str1 < *str2) ? -1 : 1);
}

int32 Q_atoi(const char *str)
{
	int32 sign = 1;
	int32 val = 0;
	uint8 c;

	// Negative
	// Checks to see if there is a negative number in the beginning of the string
	if (*str == '-')
	{
		sign = -1;
		str++;
	}

	// Hexidecimal Notation
	// If we are in hexidecimal mode proceed
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {

		// if the first two values are 0 & x/X we want to move past those in the pointer str
		str += 2;

		// Doing the hexidecimal magic here.
		while (1) {
			c = *str;
			str++;
			if (c >= '0' && c <= '9')
			{
				// assume c = '5'; char '5' = 53 and char '0' = 48 
				// if you subtract c - '0' you should retrieve numerical value 5
				// same for the other values below
				val = val * 16 + c - '0';
			}
			else if (c >= 'a' && c <= 'f')
			{
				val = val * 16 + c - 'a' + 10;
			}
			else if (c >= 'A' && c <= 'F')
			{
				val = val * 16 + c - 'A' + 10;
			}
			else
				return val*sign;
		}
	}

	// Decimal Notation
	// Doing the decimal magic here
	while (1)
	{
		c = *str;
		str++;

		if (c < '0' || c > '9')
			return sign * val;
		val = val * 10 + c - '0';
	}
	return 0;
}

 