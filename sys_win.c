#include <windows.h>

// DEFINES A CONSTANT VALUE FOR THE NUMBER OF ARGUMENTS
#define MAX_NUM_ARGVS 50

// Keeps count of the number or arguments parsed.
int argc = 1;

// The character array pointer
char *largv[MAX_NUM_ARGVS];

// Searches for a argument anf returns the value that is associated with that argument
int COM_CheckParm(char *parm)
{
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(parm, largv[i]))
			return i;
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////
/*
CALLBACK WinMain() => the entry point to a windows application
*/
//////////////////////////////////////////////////////////////////////////
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	largv[0] = "";

	// While there are still valid character to read and 
	// While we have not filled up all the spaces in the args array
	while (*lpCmdLine && (argc < MAX_NUM_ARGVS))
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

	int test = COM_CheckParm("-setalpha");
	int value = (int)(*largv[3]);
	return 0;
}