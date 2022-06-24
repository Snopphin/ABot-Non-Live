#include "pch.h"

namespace FileSystem
{
	size_t CountFiles(const std::string& Path)
	{
		auto dirIter = std::filesystem::directory_iterator(Path);

		size_t fileCount = 0;
		for (const auto& entry : dirIter)
		{
			if (entry.is_regular_file())
			{
				fileCount++;
			}
		}

		return fileCount;
	}
}