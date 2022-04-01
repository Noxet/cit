#pragma once
#include <args.hxx>

#include "RepoManager.h"
#include "ObjectManager.h"

namespace cit
{
	struct CitCommand
	{
		static args::ArgumentParser parser;
		static args::Group commands;
		static args::Command status;
		static args::Command catFile;

		static args::Group arguments;
		static args::ValueFlag<std::string> gitdir;
		static args::HelpFlag h;
		static args::PositionalList<std::string> pathsList;
	};


	void catFileCmd(args::Subparser &parser)
	{
		args::Positional<string> type(parser, "TYPE", "Object type");
		args::Positional<string> object(parser, "OBJECT", "Object");
		parser.Parse();

		RepoManager rm;

		if (object)
		{
			cout << "TYPE: " << args::get(type) << endl;
			cout << "OBJ: " << args::get(object) << endl;
			auto repo = rm.findRepo();
			auto obj = ObjectManager::readObject(repo, args::get(object));
			cout << "obj data: " << obj->serialize() << endl;
		}
	}


	args::ArgumentParser CitCommand::parser("Commands parser");
	args::Group CitCommand::commands(parser, "commands");
	args::Command CitCommand::status(commands, "status", "show repository status");
	args::Command CitCommand::catFile(commands, "cat-file", "print the content of a git object", &catFileCmd);

	args::Group CitCommand::arguments(parser, "arguments", args::Group::Validators::DontCare, args::Options::Global);
	args::ValueFlag<std::string> CitCommand::gitdir(arguments, "path", "", { "git-dir" });
	args::HelpFlag CitCommand::h(arguments, "help", "help", { 'h', "help" });
	args::PositionalList<std::string> CitCommand::pathsList(arguments, "paths", "files to commit");
}
