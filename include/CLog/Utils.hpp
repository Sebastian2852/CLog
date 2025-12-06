#pragma once

#include <string>

namespace CLog
{
    namespace Utils
    {
        inline void ReplaceAllInString(std::string &s, const std::string &from, const std::string &to)
        {
            if (from.empty())
                return;

            int pos = 0;
            while ((pos = s.find(from, pos)) != std::string::npos)
            {
                s.replace(pos, from.length(), to);
                pos += to.length();
            }
        }
    }
}
