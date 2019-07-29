#ifndef DIGITAL_SIGNATURE_H
#define DIGITAL_SIGNATURE_H
#include <stdint.h>
#include "Defines.h"

typedef struct DigitalSignatureHeader
{
	uint16_t signature[2];
	uint16_t size;
}DigitalSignatureHeader;

typedef struct DigitalSignatureData
{
	byte *data;
}DigitalSignatureData;

typedef struct DigitalSignatureInfo
{
	DigitalSignatureHeader dsh;
	DigitalSignatureData dsd;
}DigitalSignatureInfo;

#endif
