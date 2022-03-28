#pragma once
#include "Repository.h"

namespace cit
{
	class RepoManager
	{
	private:
		shared_ptr<Repository> m_repo;

	public:
		void create(string path);
		shared_ptr<Repository> findRepo(string path = ".", bool required = true);
	};
}
