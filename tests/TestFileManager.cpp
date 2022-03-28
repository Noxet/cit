#include "citpch.h"

#include "gtest/gtest.h"
#include "FileManager.h"
#include "Repository.h"

#include <filesystem>

using namespace std;
using namespace cit;

namespace fs = std::filesystem;

TEST(TestFileManager, BasicTest)
{
	Repository repo("test");
	string parent = FileManager::getParentDir(".");
	cout << "parent dir: " << parent << endl;

	//RepoManager rm;
	EXPECT_EQ(parent, "test/..");
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}