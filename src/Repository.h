#pragma once

#include <string>

namespace cit
{
	using std::string;


	class Repository
	{
	public:
		Repository(string path);

	private:
		string m_workTree{};
		string m_gitDir{};

	public:
		string getWorkTree() const { return m_workTree; }
		string getGitDir() const { return m_gitDir; }
	};
}