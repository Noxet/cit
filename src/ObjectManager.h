#pragma once
#include "GitObject.h"

namespace cit
{
	class ObjectManager
	{
	public:
		static shared_ptr<GitObject> readObject(shared_ptr<Repository> repo, const string &hash);
	};
}