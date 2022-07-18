#include "pch.h"

namespace FileSystem
{
	size_t CountFiles(const std::string& Path)
	{
		fast_io::dir_file dirIter(Path);

		size_t fileCount = 0;

		for (const auto& entry : fast_io::recursive(fast_io::at(dirIter)))
		{
			fileCount++;
		}

		return fileCount;
	}
}