#include "citpch.h"

#include "GitObject.h"

namespace cit
{
	GitCommit::GitCommit(shared_ptr<Repository> repo, const string& data) : GitObject(repo, data)
	{
	}

	string GitCommit::serialize() const
	{
		return m_data;
	}

	string GitCommit::deserialize(string &data) const
	{
		return string();
	}
}