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
		printf("%s %X %d %s", info.fhd.fileName, info.fh.flags, info.fh.comp_method, "\n");
	//	printf("%d%s", info.fh.comp_method, "\n");
		//to jest 8

		FileHeaderDeinitialize(&info);
		GoNextHeader(f, &info);
	}
	
	CloseFile(f);
	return 0;
}