#pragma once

namespace cit
{
	class Config
	{
	private:
		// TODO: make a map to save config data, then print it as string
		string data;

	public:
		void addSection(const string &section);
		void addParam(const string &section, const string &param, const string &value);
	};
}