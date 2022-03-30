#include "citpch.h"

#include "ObjectManager.h"
#include "FileManager.h"

#include <sstream>

namespace cit
{

	shared_ptr<GitObject> ObjectManager::readObject(shared_ptr<Repository> repo, const string &hash)
	{
		const string objPath = FileManager::joinPaths({ repo->getGitDir(), "objects", hash.substr(0, 2), hash.substr(2) });
		const string objRaw = FileManager::readObject(objPath);

		const auto fmtIdx = objRaw.find(' ');
		const string objType = objRaw.substr(0, fmtIdx);

		// find size (in ASCII) and convert to integer
		const auto sizeIdx = objRaw.find('\0', fmtIdx);
		const string objSizeStr = objRaw.substr(fmtIdx, sizeIdx - fmtIdx);
		stringstream ss(objSizeStr);
		size_t objSize;
		ss >> objSize;

		// Check that the encoded length matches the length of the actual file (minus header and null byte)
		if (objSize != objRaw.size() - sizeIdx - 1)
		{
			const string errMsg = format("Malformed object {}: bad length", hash);
			throw std::runtime_error(errMsg);
		}

		string objData = objRaw.substr(sizeIdx + 1); // skip null byte that terminates the length param

		if (objType == "commit")	return make_shared<GitCommit>(repo, objData);
		if (objType == "tree")		return make_shared<GitTree>(repo, objData);
		if (objType == "tag")		return make_shared<GitTag>(repo, objData);
		if (objType == "blob")		return make_shared<GitBlob>(repo, objData);
	}
	
}