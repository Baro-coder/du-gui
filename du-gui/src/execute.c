#include "execute.h"

FILE *execute_cmd(char *flags)
{
	// Create command
	char* cmd = (char*) malloc(CMD_BUFFER_SIZE * sizeof(char));
	memset(cmd, 0, CMD_BUFFER_SIZE);
	sprintf(cmd, "du %s", flags);

	// Execute command and return outstream reference
	printf(" [*] Core :: Executing command: %s\n", cmd);
	FILE *stream = popen(cmd, "r");

	if (stream == NULL)
	{
		printf(" [!] Core :: Command : Error : Invalid command: %s\n", cmd);
		return NULL;
	}

	return stream;
}