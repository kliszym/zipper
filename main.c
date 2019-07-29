#include "FileHeaderDescriptors.h"
#include "OpenFileTools.h"

int main()
{
	FILE* f;
	FileHeaderInfo info;

	f = OpenFile();

	while (1)
	{
		ReadFileInfo(f, &info);
		printf("%s%s", info.fhd.fileName, "\n");

		FileHeaderDeinitialize(&info);
		GoNextHeader(f, &info);
	}
	
	CloseFile(f);
	return 0;
}