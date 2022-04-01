#include "citpch.h"

#include "CitCommand.h"
#include "FileManager.h"
#include "ObjectManager.h"
#include "RepoManager.h"
#include "Repository.h"

using namespace cit;


int main(int argc, char *argv[])
{
	RepoManager rm;

	try
	{
		CitCommand::parser.ParseCLI(argc, argv);
	}
	catch (args::Help)
	{
		cout << CitCommand::parser;
	}
	catch (args::Error &e)
	{
		std::cerr << e.what() << endl << CitCommand::parser;
		return 1;
	}

	if (CitCommand::status)
	{
		const auto repo = rm.findRepo();
		cout << "work tree: " << repo->getWorkTree() << "\tgit dir: " << repo->getGitDir() << endl;
	}


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
	else if (command == "cat-file")
	{

	}
}
