#include "citpch.h"

#include "GitObject.h"

namespace cit
{
	GitTag::GitTag(shared_ptr<Repository> repo, const string &data) : GitObject(repo, data)
	{
	}

	string GitTag::serialize() const
	{
		return m_data;
	}

	string GitTag::deserialize(string &data) const
	{
		return string();
	}
}