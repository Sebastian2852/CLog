#include "Utils.hpp"

namespace CLog::Utils
{
	void ReplaceInString(std::string &fmt, std::string from, std::string to)
	{
		if (from.empty())
			return;

		int pos = 0;
		while ((pos = fmt.find(from, pos)) != std::string::npos)
		{
			fmt.replace(pos, from.length(), to);
			pos += to.length();
		}
	}
}
