/*********************************************************************
 *           Copyright (C) 2017 mwl4 - All rights reserved           *
 *********************************************************************
 * File       : sysfs_file.cpp
 * Project    : ConverterPIX
 * Developers : Michal Wojtowicz (mwl450@gmail.com)
 			  : Piotr Krupa (piotrkrupa06@gmail.com)
 *********************************************************************/

#include <prerequisites.h>

#include "sysfs_file.h"

SysFsFile::SysFsFile()
{
}

SysFsFile::~SysFsFile()
{
	if (m_fp)
	{
		::fclose(m_fp);
	}
}

size_t SysFsFile::write(const void *buffer, size_t elementSize, size_t elementCount)
{
	return ::fwrite(buffer, elementSize, elementCount, m_fp);
}

size_t SysFsFile::read(void *buffer, size_t elementSize, size_t elementCount)
{
	return ::fread(buffer, elementSize, elementCount, m_fp);
}

size_t SysFsFile::getSize() const
{
	long current = ::ftell(m_fp);
	::fseek(m_fp, 0, SEEK_END);
	size_t result = (size_t)::ftell(m_fp);
	::fseek(m_fp, current, SEEK_SET);
	return result;
}

const char *SysFsFile::getLine(String &out)
{
	char buffer[1024] = { 0 };
	const char *result = ::fgets(buffer, sizeof(buffer), m_fp);
	if (result)
	{
		out = buffer;
		return out.c_str();
	}
	out = "";
	return nullptr;
}

int SysFsFile::seek(uint32_t offset, Attrib attr)
{
	return ::fseek(m_fp, offset, attr);
}

void SysFsFile::rewind()
{
	::rewind(m_fp);
}

size_t SysFsFile::tell()
{
	return (size_t)::ftell(m_fp);
}

/* eof */
