#include "citpch.h"
#include "GitObject.h"

namespace cit
{
	GitObject::GitObject(shared_ptr<Repository> repo) : m_repo(repo)
	{
	}
}
