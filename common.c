#include "quakedef.h" 
 
int32 com_argc = 1;
uint8 *com_argv[MAX_NUM_ARGVS + 1];


void COM_ParseCommandLine(uint8 *lpCmdLine)
{
	com_argv[0] = "";

	// While there are still valid character to read and 
	// While we have not filled up all the spaces in the args array
	while (*lpCmdLine && (com_argc < MAX_NUM_ARGVS + 1))
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
			com_argv[com_argc] = lpCmdLine;

			// increments the argument counter.
			com_argc++;

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

}


int32 COM_CheckParm(uint8 *parm)
{
	for (int32 i = 1; i < com_argc; i++)
	{
		if (!Q_strcmp(parm, com_argv[i]))
			return i;
	}

	return 0;
}