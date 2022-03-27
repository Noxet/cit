#include "citpch.h"
#include "RepoManager.h"

namespace cit
{
	void cit::RepoManager::create(string path)
	{
		m_repo = Repository{ path };
	}
}
