#include "FileHeaderDescriptors.h"


int main()
{
	FileHeaderInfo info;
	ReadFileInfo(&info);
	if (info.fh.signature[0] == 0x4b50
		&& info.fh.signature[1] == 0x0403)
	{
		printf("%s", "signature correct\n");
	}
	printf("\n");
	printf("%s%s", info.fhd.fileName, "\n");
	FileHeaderDeinitialize(info);

	return 0;
}