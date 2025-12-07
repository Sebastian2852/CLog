#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "LogMessage.hpp"

namespace CLog
{
    namespace Sinks
    {
        class BaseSink
        {
        public:
            virtual ~BaseSink() = default;
            virtual void Log(const LogMessage &message) = 0;
        };

        class ConsoleSink : public BaseSink
        {
        public:
            void Log(const LogMessage &message) override
            {
                std::string prefix = Utils::GetPrefixForLevel(message.Level);
                std::string colorCode = Utils::GetColorCodeForLevel(message.Level);

                std::string newString = message.Text;
                Utils::ReplaceAllInString(newString, "{PREFIX}", prefix);
                Utils::ReplaceAllInString(newString, "{COLOR_START}", "\033[" + colorCode + "m");
                Utils::ReplaceAllInString(newString, "{COLOR_END}", "\033[0m");
                std::cout << newString;
            };
        };

        class FileSink : public BaseSink
        {
        public:
            FileSink(const std::string &filename)
            {
                m_File = std::ofstream(filename, std::ios::out);
            }

            ~FileSink()
            {
                m_File.close();
            }

            void Log(const LogMessage &message) override
            {
                std::string prefix = Utils::GetPrefixForLevel(message.Level);

                std::string newString = message.Text;
                Utils::ReplaceAllInString(newString, "{PREFIX}", prefix);
                Utils::ReplaceAllInString(newString, "{COLOR_START}", "");
                Utils::ReplaceAllInString(newString, "{COLOR_END}", "");
                m_File << newString;
            };

        private:
            std::ofstream m_File;
        };
    }
}