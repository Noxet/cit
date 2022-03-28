#include "citpch.h"

#include "FileManager.h"
#include "RepoManager.h"
#include "Repository.h"


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Usage: cit <option>" << endl;
		return 0;
	}

	cit::FileManager::create({ "test", "windows", "strings" });
	//cit::Repository repo(".");
	cit::RepoManager rm;
	rm.create(argv[1]);
}
