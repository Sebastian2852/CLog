#pragma once

#include <fstream>
#include <iostream>
#include <string>

namespace CLog
{
    namespace Sinks
    {
        class BaseSink
        {
        public:
            virtual ~BaseSink() = default;
            virtual void log(const std::string &message) = 0;
        };

        class ConsoleSink : public BaseSink
        {
        public:
            void log(const std::string &message) override
            {
                std::cout << message;
            };
        };

        class FileSink : public BaseSink
        {
        public:
            FileSink(const std::string &filename)
            {
                m_File = std::ofstream(filename, std::ios::app);
            }

            ~FileSink()
            {
                m_File.close();
            }

            void log(const std::string &message) override
            {
                m_File << message;
            };

        private:
            std::ofstream m_File;
        };
    }
}