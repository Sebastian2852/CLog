#pragma once

#include <iostream>

namespace CLog
{

    enum LogLevel
    {
        Info,
        Debug,
        Warn,
        Error
    };

    class Logger
    {
    public:
        Logger(LogLevel minimumLogLevel = LogLevel::Info)
            : m_MinimumLogLevel(minimumLogLevel)
        {
        }

        void LogMessage(LogLevel level, const std::string &message)
        {
            if (level < m_MinimumLogLevel)
                return;

            std::string prefix;
            switch (level)
            {
            case LogLevel::Info:
                prefix = "[INF]";
                break;
            case LogLevel::Debug:
                prefix = "[DBG]";
                break;
            case LogLevel::Warn:
                prefix = "[WRN]";
                break;
            case LogLevel::Error:
                prefix = "[ERR]";
                break;
            }

            std::string messageToLog = prefix + " " + message;
            std::cout << messageToLog << "\n";
        }

        void Info(const std::string &message)
        {
            LogMessage(LogLevel::Info, message);
        }
        void Debug(const std::string &message)
        {
            LogMessage(LogLevel::Debug, message);
        }
        void Warn(const std::string &message)
        {
            LogMessage(LogLevel::Warn, message);
        }
        void Error(const std::string &message)
        {
            LogMessage(LogLevel::Error, message);
        }

    private:
        LogLevel m_MinimumLogLevel;
    };

}