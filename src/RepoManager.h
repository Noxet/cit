#pragma once
#include "Repository.h"

namespace cit
{
	class RepoManager
	{
	private:
		Repository m_repo;

	public:
		void create(string path);
	};
}
