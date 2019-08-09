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
	return info->fh.signature[1] * 0x10000 + info->fh.signature[0] == signature_file_header;
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

char CheckBit1(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x2) == 0x2;
}

char CheckBit2(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x4) == 0x4;
}

char CheckEncryption(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x1) == 0x1;
}

char CheckCompresion(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x8) == 0x8;
}

char CheckDeflation(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x10) == 0x10;
}

char CheckPatch(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x20) == 0x20;
}

char CheckStrongEncryption(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x40) == 0x40;
}

char CheckEFS(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x800) == 0x800;
}

char CheckCentralDirEncryption(FileHeaderInfo *info)
{
	return (info->fh.flags & 0x2000) == 0x2000;
}

void GoNextHeader(FILE* f, FileHeaderInfo *info)
{
	fseek(f, info->fh.comp_size[1] * 0x10000 + info->fh.comp_size[0], SEEK_CUR);
}
