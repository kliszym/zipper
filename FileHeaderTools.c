#include "FileHeaderDescriptors.h"

void FileHeaderInitialize(FileHeaderInfo *info)
{
	info->fhd.fileName = (byte*)malloc((uint32_t)(info->fh.fileName_len) * sizeof(byte));
	info->fhd.extras = (byte*)malloc((uint32_t)info->fh.extras_len * sizeof(byte));
}

void FileHeaderDeinitialize(FileHeaderInfo *info)
{
	free(info->fhd.fileName);
	free(info->fhd.extras);
}

void Read(FILE *f, void *info, int size)
{
	fread(info, size, 1, f);
}

void ReadFileInfo(FileHeaderInfo *info)
{
	FILE *f;
	f = fopen("test.docx", "rb");
	if (f == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	Read(f, &info->fh, sizeof(FileHeader));
	FileHeaderInitialize(info);

	Read(f, info->fhd.fileName, info->fh.fileName_len);
	Read(f, info->fhd.extras, info->fh.extras_len);
	//do sth

	fclose(f);
}
