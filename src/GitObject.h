#pragma once

#include "Repository.h"

namespace cit
{
	class GitObject
	{
	protected:
		shared_ptr<Repository> m_repo;
		string m_data;

	public:
		GitObject(shared_ptr<Repository> repo, const string &data = "");

		virtual string serialize() const = 0;
		virtual string deserialize(string &data) const = 0;
	};


	class GitCommit : public GitObject
	{
	public:
		GitCommit(shared_ptr<Repository> repo, const string &data = "");

		virtual string serialize() const override;
		virtual string deserialize(string &data) const override;
	};


	class GitTree : public GitObject
	{
	public:
		GitTree(shared_ptr<Repository> repo, const string &data = "");

		virtual string serialize() const override;
		virtual string deserialize(string &data) const override;
	};


	class GitTag : public GitObject
	{
	public:
		GitTag(shared_ptr<Repository> repo, const string &data = "");

		virtual string serialize() const override;
		virtual string deserialize(string &data) const override;
	};


	class GitBlob : public GitObject
	{
	public:
		GitBlob(shared_ptr<Repository> repo, const string &data = "");

		virtual string serialize() const override;
		virtual string deserialize(string &data) const override;
	};
}
