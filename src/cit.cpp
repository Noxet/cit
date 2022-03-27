#include "citpch.h"

#include "FileManager.h"
#include "Repository.h"


int main()
{
	cit::FileManager::create({ "test", "windows", "strings" });
	cit::Repository repo(".");
}
