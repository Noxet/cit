#include "citpch.h"

#include "FileManager.h"

#include <filesystem>

namespace cit
{
	namespace fs = std::filesystem;


	void FileManager::create(const vector<string> &path, bool isDir)
	{
		const string filePath = joinPaths(path);
		if (isDir)
		{
			fs::create_directories(filePath);
		}
		else
		{
			
		}
	}

	bool FileManager::isDir(const string path)
	{
		return fs::is_directory(path);
	}

	bool FileManager::isFile(const string path)
	{
		return fs::exists(path);
	}

	string FileManager::joinPaths(const vector<string> &paths)
	{
		fs::path locPath;
		for (const auto &p : paths)
		{
			locPath.append(p);
		}
		return locPath.string();
	}
}
