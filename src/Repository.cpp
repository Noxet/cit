#include "citpch.h"

#include "Repository.h"
#include "FileManager.h"

namespace cit
{
	Repository::Repository(string path) : m_workTree(path)
	{
		m_gitDir = FileManager::joinPaths({ path, ".git" });
		cout << "Checking gitdir: " << m_gitDir << endl;
	}

}