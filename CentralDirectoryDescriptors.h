#ifndef CENTRAL_DIRECTORY_DESCRIPTORS_H
#define CENTRAL_DIRECTORY_DESCRIPTORS_H
#include <stdint.h>
#include "Defines.h"

	typedef struct CentralDirectoryHeader
	{
		uint16_t signature[2];
		uint16_t versionMade;
		uint16_t versionNeed;
		uint16_t flags;
		uint16_t comp_method;
		uint16_t time;
		uint16_t date;
		uint16_t crc_32[2];
		uint16_t comp_size[2];
		uint16_t size[2];
		uint16_t fileName_len;
		uint16_t extra_len;
		uint16_t comment_len;
		uint16_t discNumber;
		uint16_t fileAttributess_internal;
		uint16_t fileAttributes_external[2];
		uint16_t headerOffset[2];
	}FileDirectoryHeader;

	typedef struct CentralDirectoryData
	{
		byte *fileName;
		byte *extra;
		byte *comment;
	}CentralDirectoryData;

	typedef struct CentralDirectoryInfo
	{
		CentralDirectoryHeader cdh;
		CentralDirectoryData cdd;
	}CentralDirectoryInfo;

#endif