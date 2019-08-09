#ifndef DEFINES_H
#define DEFINES_H

typedef unsigned char byte;

enum{
	signature_file_header = 0x04034b50,
	signature_archive_data = 0x08064b50,
	signature_central_directory = 0x02014b50,
	signature_digital_structure = 0x05054b50,
	signature_zip64_end_of_central_dir = 0x06064b50,
	signature_zip64_end_of_central_dir_locator = 0x07064b50,
	signature_end_of_central_dir = 0x06054b50
};

#endif
