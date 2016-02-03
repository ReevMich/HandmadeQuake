#include <windows.h>
#include <stdint.h>

typedef uint8_t uint8;
typedef int32_t int32;
typedef uint32_t  unint32;

// DEFINES A CONSTANT VALUE FOR THE NUMBER OF ARGUMENTS
#define MAX_NUM_ARGVS 3

// Keeps count of the number or arguments parsed.
int32  argc = 1;

// The character array pointer
uint8 *largv[MAX_NUM_ARGVS+1];

// String compare method.
int32 Q_strcmp(uint8* str1, uint8* str2)
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
	return ((*str1 < *str2)? -1 : 1);
}

// Converts Numbers in String to the actual numerical values
// Hexidecimal, decimal, positive number, and negative numbers
int32 Q_atoi(uint8 *str)
{
	int32 sign = 1 ;
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
		val = val * 10 + c - '0' ;
	}
	return 0;
}

// Searches for a argument and returns the value that is associated with that argument
int COM_CheckParm(uint8 *parm)
{
	for (int32 i = 1; i < argc; i++)
	{
		if (!Q_strcmp(parm, largv[i]))
			return i;
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////
/*
CALLBACK WinMain() => the entry point to a windows application
*/
//////////////////////////////////////////////////////////////////////////
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32 nCmdShow)
{
	largv[0] = "";

	// While there are still valid character to read and 
	// While we have not filled up all the spaces in the args array
	while (*lpCmdLine && (argc < MAX_NUM_ARGVS+1))
	{
		// While the value is a non valid character such as spaces or dashes (CHECK ASCII TABLE FOR 32 and 126)
		while (*lpCmdLine && ((*lpCmdLine <= 32) || (*lpCmdLine > 126)))
		{
			lpCmdLine++;
		}

		// If a value exist
		if (*lpCmdLine)
		{
			// stores the value from the pointer
			largv[argc] = lpCmdLine;

			// increments the argument counter.
			argc++;

			// While the value is still valid (CHECK ASCII TABLE FOR 32 and 126)
			while (*lpCmdLine && ((*lpCmdLine > 32) && (*lpCmdLine <= 126)))
				lpCmdLine++;

			// Check again if there is anything at the cursor
			// If there is, replace the space with a 0, then increment the cursor after the space.
			if (*lpCmdLine)
			{
				*lpCmdLine = 0;
				lpCmdLine++;
			}
		}
	}

	largv[argc] = "";

	int32 test = COM_CheckParm("-setalpha");
	int32 value = Q_atoi(largv[test+1]);
	return 0;
} 