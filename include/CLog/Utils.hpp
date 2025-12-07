#pragma once

#include <string>

#include "LogMessage.hpp"

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

        inline std::string GetColorCodeForLevel(LogLevel level)
        {
            switch (level)
            {
            case LogLevel::Info:
                return "94";
            case LogLevel::Debug:
                return "32";
            case LogLevel::Warn:
                return "93";
            case LogLevel::Error:
                return "31";
            }
            return "0";
        }

        inline std::string GetPrefixForLevel(LogLevel level)
        {
            switch (level)
            {
            case LogLevel::Info:
                return "INFO";
            case LogLevel::Debug:
                return "DEBUG";
            case LogLevel::Warn:
                return "WARNING";
            case LogLevel::Error:
                return "ERROR";
            }
            return "";
        }
    }
}
