#include "citpch.h"
#include "GitObject.h"

namespace cit
{
	GitObject::GitObject(shared_ptr<Repository> repo, const string &data) : m_repo(repo), m_data(data)
	{
	}
}
