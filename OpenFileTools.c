#include "OpenFileTools.h"

FILE* OpenFile()
{
	FILE *f;
	f = fopen("test.zip", "rb");
	if (f == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	return f;
}


void CloseFile(FILE* f)
{
	fclose(f);
}