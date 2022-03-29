#include "citpch.h"

#include "FileManager.h"

#include <filesystem>
#include <fstream>
#include <sstream>

#include <zlib.h>

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

	string FileManager::readObject(const string &filename)
	{
		const gzFile file = gzopen(filename.c_str(), "rb");
		if (file == nullptr)
		{
			stringstream ss;
			ss << "Could not open zip-file: " << filename;
			throw std::runtime_error(ss.str());
		}

		string data{};
		char buf[256];
		int numRead{ 0 };

		while ((numRead = gzread(file, buf, sizeof(buf))) > 0)
		{
			// append only the "numRead" characters
			data.append(buf, numRead);
		}

		gzclose(file);

		return data;
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

	string FileManager::getParentDir(const string &path)
	{
		string parent = joinPaths({ path, ".." });
		fs::path absPath = fs::absolute(parent);
		return absPath.string();
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
