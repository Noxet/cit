#include "citpch.h"

#include "Repository.h"
#include "FileManager.h"

namespace cit
{
	using std::string;
	using std::cout;
	using std::endl;

	Repository::Repository(string path) : m_workTree(path)
	{
		m_gitDir = FileManager::joinPaths({ path, ".git" });
		cout << "Checking gitdir: " << m_gitDir << endl;

		if (!FileManager::isDir(m_gitDir))
		{
			std::cout << "Not a git repo!" << std::endl;
			// TODO: throw exception
		}


	}

}