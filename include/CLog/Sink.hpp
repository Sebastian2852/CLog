#pragma once

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
    }
}