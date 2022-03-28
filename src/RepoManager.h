#pragma once
#include "Repository.h"

namespace cit
{
	class RepoManager
	{
	private:
		vector<shared_ptr<Repository>> m_repos;

	public:
		void create(string path);
	};
}
