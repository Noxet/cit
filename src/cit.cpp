#include "citpch.h"

#include "FileManager.h"
#include "ObjectManager.h"
#include "RepoManager.h"
#include "Repository.h"

#include "zlib.h"

using namespace cit;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Usage: cit <option>" << endl;
		return 1;
	}

	FileManager::create({ "test", "windows", "strings" });
	//cit::Repository repo(".");
	RepoManager rm;

	const string command = argv[1];
	if (command == "init")
	{
		if (argc < 3)
		{
			cout << "Usage: cit init <path>";
			return 1;
		}

		const string initPath = argv[2];

		rm.create(initPath);
	}
	else if (command == "status")
	{
		try
		{
			auto repo = rm.findRepo();
			cout << "work tree: " << repo->getWorkTree() << "\tgit dir: " << repo->getGitDir() << endl;

			string hash = argv[2];
			auto obj = ObjectManager::readObject(repo, hash);
			cout << "obj data: " << obj->serialize() << endl;
		} catch (const std::exception &e)
		{
			cout << "Error: " << e.what() << endl;
		}

		
	}
}
