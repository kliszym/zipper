#include "FileHeaderDescriptors.h"

void FileHeaderInitialize(FileHeaderInfo *info)
{
	info->fhd.fileName = (byte*)malloc((uint32_t)(info->fh.fileName_len + 1) * sizeof(byte));
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

void SetEndName(FileHeaderInfo *info)
{
	info->fhd.fileName[info->fh.fileName_len] = '\0';
}

char CheckSignature(FileHeaderInfo *info)
{
	return info->fh.signature[1] * 0x10000 + info->fh.signature[0] == local_file_header_signature;
}

void ReadFileInfo(FILE *f, FileHeaderInfo *info)
{
	Read(f, &info->fh, sizeof(FileHeader));
	FileHeaderInitialize(info);

	if (!CheckSignature(info))
	{
		perror("Wrong file format.\n");
		exit(EXIT_FAILURE);
	}

	Read(f, info->fhd.fileName, info->fh.fileName_len);
	SetEndName(info);
	Read(f, info->fhd.extras, info->fh.extras_len);
}

char CheckEncription(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x4) == 0x4;
}

void GoNextHeader(FILE* f, FileHeaderInfo *info)
{
	fseek(f, info->fh.comp_size[1] * 0x10000 + info->fh.comp_size[0], SEEK_CUR);
}
