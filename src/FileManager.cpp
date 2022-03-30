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
		FILE *file;
		fopen_s(&file, filename.c_str(), "rb");

		if (!file)
		{
			stringstream ss;
			ss << "Could not open zip-file: " << filename;
			throw std::runtime_error(ss.str());
		}

		z_stream stream;
		stream.zalloc = Z_NULL;
		stream.zfree = Z_NULL;
		stream.opaque = Z_NULL;
		stream.avail_in = 0;
		stream.next_in = Z_NULL;
		int ret = inflateInit(&stream);
		if (ret != Z_OK)
		{
			throw std::runtime_error("Failed to initialize zlib stream");
		}

		unsigned char *in = new unsigned char[OBJ_CHUNK];
		unsigned char *out = new unsigned char[OBJ_CHUNK];

		string objData;

		// decompress until deflate stream ends or EOF
		do
		{
			stream.avail_in = static_cast<uInt>(fread(in, 1, OBJ_CHUNK, file));
			if (ferror(file))
			{
				(void)inflateEnd(&stream);
				delete[] in;
				delete[] out;
				throw std::runtime_error("Got ferror on file");
			}

			if (stream.avail_in == 0) break;
			stream.next_in = in;

			do
			{
				stream.avail_out = OBJ_CHUNK;
				stream.next_out = out;

				ret = inflate(&stream, Z_NO_FLUSH);
				if (ret == Z_STREAM_ERROR)
				{
					delete[] in;
					delete[] out;
					throw std::runtime_error("inflate got stream error");
				}

				switch (ret)
				{
					case Z_NEED_DICT:
						ret = Z_DATA_ERROR;
						[[fallthrough]];
					case Z_DATA_ERROR:
						[[fallthrough]];
					case Z_MEM_ERROR:
						(void)inflateEnd(&stream);
						delete[] in;
						delete[] out;
						throw std::runtime_error("inflate got MEM ERROR");
				}

				const unsigned have = OBJ_CHUNK - stream.avail_out;
				const string current((char *) out, have);

				objData += current;
			} while (stream.avail_out == 0);
		} while (ret != Z_STREAM_END);

		delete[] in;
		delete[] out;
		return objData;
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
