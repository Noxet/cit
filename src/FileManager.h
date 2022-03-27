#pragma once

#include <string>
#include <vector>

namespace cit
{
	using std::string;
	using std::vector;


	class FileManager
	{
	public:
		static void create(const vector<string> &path, bool isDir = false);

		static bool isDir(const string path);
		static bool isFile(const string path);

		static string joinPaths(const vector<string> &paths);
	};
}