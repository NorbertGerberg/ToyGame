/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#ifndef EDR_HPP
#define EDR_HPP
#include "Types.hpp"
#include <vector>
#include <fstream>
#include <libzip/zip.h>

namespace EDR
{
	strg				GetString(strg file, strg token, const bool binary = false);
	real6				GetNumber(strg file, strg token, const bool binary = false);
	int					GetInt(strg file, strg token, const bool binary = false);
	bool				GetBool(strg file, strg token, const bool binary = false);
	const uint			SetValue(strg file, strg value, const bool binary = false);
	const uint			ChangeValue(strg file, strg token, strg value, const bool binary = false);
	void				CreateDirectoryExt(const char* dir);
	void				DeleteDirectory(const char* dir);
	void				WriteFile(const char* dir, strg content);
	void				WriteBinary(const char* dir, strg content);
	void				ConvertToBinary(strg& text);
	void				ConvertToText(strg& binary);
	strg				GetContext(strg filePath, const bool binary = false);
	void				RemoveFile(const char* filePath);
	bool				FileExists(const char* path);
	std::vector<strg>	GetFilesInDir(strg dir, const int nt);

	strg				GetStringG(strg file, strg token, strg group, const bool binary = false);
	real6				GetNumberG(strg file, strg token, strg group, const bool binary = false);
	int					GetIntG(strg file, strg token, strg group, const bool binary = false);
	bool				GetBoolG(strg file, strg token, strg group, const bool binary = false);

	strg				GetStringGI(strg file, strg token, strg group, const bool binary = false);
	real6				GetNumberGI(strg file, strg token, strg group, const bool binary = false);
	int					GetIntGI(strg file, strg token, strg group, const bool binary = false);
	bool				GetBoolGI(strg file, strg token, strg group, const bool binary = false);

	strg				GetStringSG(strg file, strg token, strg group, strg groupS, const bool binary = false);
	real6				GetNumberSG(strg file, strg token, strg group, strg groupS, const bool binary = false);
	int					GetIntSG(strg file, strg token, strg group, strg groupS, const bool binary = false);
	bool				GetBoolSG(strg file, strg token, strg group, strg groupS, const bool binary = false);

	strg				GetStringSGI(strg file, strg token, strg group, strg groupS, const bool binary = false);
	real6				GetNumberSGI(strg file, strg token, strg group, strg groupS, const bool binary = false);
	int					GetIntSGI(strg file, strg token, strg group, strg groupS, const bool binary = false);
	bool				GetBoolSGI(strg file, strg token, strg group, strg groupS, const bool binary = false);

	uint				GroupItemAmount(strg file, strg group, const bool binary = false);
	uint				GroupItemAmountI(strg file, strg group, const bool binary = false);
	strg				GroupItemName(strg file, strg group, uint place, const bool binary = false);
	strg				GroupItemNameI(strg file, strg group, uint place, const bool binary = false);

	strg				GetStringI(strg text, strg token, const bool binary = false);
	real6				GetNumberI(strg text, strg token, const bool binary = false);
	int					GetIntI(strg text, strg token, const bool binary = false);
	bool				GetBoolI(strg text, strg token, const bool binary = false);
	strg				ChangeValueI(strg text, strg token, strg value, const bool binary = false);

	struct ZSTAT
	{
		ZSTAT(char* _c, zip_uint16_t _size)
		{
			c = _c;
			size = _size;
		}
		char* c;
		zip_uint64_t size;
	};

	zip*				OpenZIPArchive(const char* directory);
	zip*				CreateZIPArchive(const char* directory);
	ZSTAT				GetZIPFileContents(zip* z, const char* name);
	void				CopyZIPFileContents(zip* z, const char* name, const char* newPath, const bool isBinary = false);
	strg				CopyZIPFileContents(zip* z, const char* name);
	zip*				CloseZIPArchive(zip* z);
	void				AddFileToZIP(zip* z, const char* filename, const char* content);
	void				CopyFileToZIP(zip* z, const char* filename, const char* filepath);
	void				RemoveFileFromZIP(zip* z, const char* filename);
};
#endif