#pragma once

#include "Repository.h"

namespace cit
{
	class GitObject
	{
	private:
		shared_ptr<Repository> m_repo;

	public:
		GitObject(shared_ptr<Repository> repo);

		virtual string serialize() const = 0;
		virtual string deserialize(string &data) const = 0;
	};
}
