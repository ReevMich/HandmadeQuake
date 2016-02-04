#pragma once

// DEFINES A CONSTANT VALUE FOR THE NUMBER OF ARGUMENTS
#define MAX_NUM_ARGVS 50

// Keeps count of the number or arguments parsed.
extern int32  com_argc ;

// The character array pointer
extern uint8 *com_argv[MAX_NUM_ARGVS + 1];

// Parses the runtime command line
void COM_ParseCommandLine(uint8 *lpCmdLine);

// Searches for a argument and returns the value that is associated with that argument
int32 COM_CheckParm(uint8 *parm);