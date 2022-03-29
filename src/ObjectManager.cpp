#include "citpch.h"

#include "ObjectManager.h"
#include "FileManager.h"

namespace cit
{
	shared_ptr<GitObject> ObjectManager::readObject(shared_ptr<Repository> repo, string &hash)
	{
		string objPath = FileManager::joinPaths({ repo->getGitDir(), "objects", hash.substr(0, 2), hash.substr(2) });
	}
}