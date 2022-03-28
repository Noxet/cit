#include "citpch.h"
#include "RepoManager.h"

#include "FileManager.h"

namespace cit
{
	void cit::RepoManager::create(string path)
	{
		Repository repo = Repository{ path };

		if (!FileManager::isDir(repo.getWorkTree()))
		{
			cout << format("{} is not a directory", repo.getWorkTree()) << endl;
			return;
			// TODO: throw exception
		}
		else if (!FileManager::isEmpty(repo.getWorkTree()))
		{
			cout << format("{} is not empty!", repo.getWorkTree()) << endl;
		}

		// Create necessary directories
		FileManager::create({ repo.getGitDir(), "branches" }, true);
		FileManager::create({ repo.getGitDir(), "objects" }, true);
		FileManager::create({ repo.getGitDir(), "refs", "tags" }, true);
		FileManager::create({ repo.getGitDir(), "refs", "heads" }, true);

		// Create necessary files with content
		FileManager::create({ repo.getGitDir(), "description" }, false, "Unnamed repo, please edit");
		FileManager::create({ repo.getGitDir(), "HEAD" }, false, "ref: refs/heads/master");
		string config = "[core]\nrepositoryformatversion = 0\nfilemode = false\nbare = false";
		FileManager::create({ repo.getGitDir(), "config" }, false, config);

		m_repo = make_shared<Repository>(repo);
	}

	shared_ptr<Repository> RepoManager::findRepo(string path, bool required)
	{
		string currentDir{ path };
		string prevDir{};
		m_repo = nullptr;

		do
		{
			string gitRepo = FileManager::joinPaths({ currentDir, ".git" });
			if (FileManager::isDir(gitRepo))
			{
				// we found a git repo somewhere in the current path
				Repository repo{ currentDir };
				m_repo = make_shared<Repository>(repo);
				break;
			}
			prevDir = currentDir;
			currentDir = FileManager::getParentDir(currentDir);
		} while (prevDir != currentDir);

		if (m_repo == nullptr && required == true)
		{
			throw std::runtime_error("Git repository can not be found");
		}

		return m_repo;
	}
}
