#include "citpch.h"

#include "GitObject.h"

namespace cit
{
	GitTree::GitTree(shared_ptr<Repository> repo, const string &data) : GitObject(repo, data)
	{
	}

	string GitTree::serialize() const
	{
		return m_data;
	}

	string GitTree::deserialize(string &data) const
	{
		return string();
	}
}