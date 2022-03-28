#include "citpch.h"

#include "FileManager.h"
#include "RepoManager.h"
#include "Repository.h"


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Usage: cit <option>" << endl;
		return 1;
	}

	cit::FileManager::create({ "test", "windows", "strings" });
	//cit::Repository repo(".");
	cit::RepoManager rm;

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
}
