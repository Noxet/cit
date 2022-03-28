#include "citpch.h"

#include "FileManager.h"

#include <filesystem>
#include <fstream>

namespace cit
{
	namespace fs = std::filesystem;


	void FileManager::create(const vector<string> &path, bool isDir, const string &data)
	{
		const string filePath = joinPaths(path);
		if (isDir)
		{
			fs::create_directories(filePath);
		}
		else
		{
			ofstream os;
			os.open(filePath);
			os << data << endl;
			os.close();
		}
	}

	bool FileManager::isDir(const string &path)
	{
		return fs::is_directory(path);
	}

	bool FileManager::isFile(const string &path)
	{
		return fs::exists(path);
	}

	bool FileManager::isEmpty(const string &path)
	{
		return fs::is_empty(path);
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
	string FileManager::normalizeString(const string &str)
	{
		fs::path normStr{ str };
		return normStr.make_preferred().string();
	}
}
