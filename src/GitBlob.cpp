#include "citpch.h"

#include "GitObject.h"

namespace cit
{
	GitBlob::GitBlob(shared_ptr<Repository> repo, const string &data) : GitObject(repo, data)
	{
	}

	string GitBlob::serialize() const
	{
		return m_data;
	}

	string GitBlob::deserialize(string &data) const
	{
		return string();
	}
}