#ifndef FILE_HEADER_DESCRIPTORS_H
#define FILE_HEADER_DESCRIPTORS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned char byte;

typedef struct FileHeader
{
	uint16_t signature[2];
	uint16_t version;
	uint16_t flags;
	uint16_t comp_method;
	uint16_t time;
	uint16_t date;
	uint16_t crc_32[2];
	uint16_t comp_size[2];
	uint16_t size[2];
	uint16_t fileName_len;
	uint16_t extras_len;
}
FileHeader;

typedef struct FileHeaderData
{
	byte *fileName;
	byte *extras;
}
FileHeaderData;

typedef struct FileHeaderInfo
{
	FileHeader fh;
	FileHeaderData fhd;
}
FileHeaderInfo;

typedef struct DataDescriptor
{
	uint32_t crc_32;
	uint32_t comp_size;
	uint32_t size;
}
DataDescriptor;

void FileHeaderInitialize(FileHeaderInfo *info);
void FileHeaderDeinitialize(FileHeaderInfo *info);
void Read(FILE *f, void *info, int size);
void SetEndName(FileHeaderInfo *info);
char CheckSignature(FileHeaderInfo *info);
void ReadFileInfo(FILE *f, FileHeaderInfo *info);

char CheckEncription(FileHeaderInfo *info);
void GoNextHeader(FILE* f, FileHeaderInfo *info);

#endif
