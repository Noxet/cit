#pragma once

#include <string>
#include <vector>

namespace cit
{
	class FileManager
	{
	private:
		static const int OBJ_CHUNK = 256 * 1024;

	public:
		static void create(const vector<string> &path, const bool isDir = false, const string &data = "");
		static string readObject(const string &filename);

		static bool isDir(const string &path);
		static bool isFile(const string &path);
		static bool isEmpty(const string &path);
		static string getParentDir(const string &path);

		static string joinPaths(const vector<string> &paths);
		static string normalizeString(const string &str);
	};
}