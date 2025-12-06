#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include "Utils.hpp"

namespace CLog
{

    enum LogLevel
    {
        Info,
        Debug,
        Warn,
        Error
    };

    struct LogMessage
    {
        LogMessage(const std::string &text, LogLevel level)
            : Text(text), Level(level)
        {
        }

        std::string Text;
        LogLevel Level;
    };

    class Logger
    {
    public:
        Logger(std::string format, LogLevel minimumLogLevel = LogLevel::Info)
            : m_MinimumLogLevel(minimumLogLevel), m_Format(format)
        {
            m_Thread = std::thread([this]()
                                   { this->sinkLoop(); });
        }

        ~Logger()
        {
            m_Running = false;
            if (m_Thread.joinable())
                m_Thread.join();
        }

        void LogMessage(LogLevel level, const std::string &message)
        {
            if (level < m_MinimumLogLevel)
                return;

            std::string mutString = m_Format;
            Utils::ReplaceAllInString(mutString, "{MESSAGE}", message);

            std::string messageToLog = mutString + "\n";
            m_MessageBuffer.emplace_back(CLog::LogMessage(messageToLog, level));
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
        bool m_Running = true;
        LogLevel m_MinimumLogLevel;
        std::vector<CLog::LogMessage> m_MessageBuffer;
        std::thread m_Thread;
        std::string m_Format;

        void sinkBuffer()
        {
            if (m_MessageBuffer.size() == 0)
                return;

            for (CLog::LogMessage &message : m_MessageBuffer)
            {
                std::string prefix = "";
                switch (message.Level)
                {
                case LogLevel::Info:
                    prefix = "INFO";
                    break;
                case LogLevel::Debug:
                    prefix = "DEBUG";
                    break;
                case LogLevel::Warn:
                    prefix = "WARNING";
                    break;
                case LogLevel::Error:
                    prefix = "ERROR";
                    break;
                }

                std::string colorCode = "0";
                switch (message.Level)
                {
                case LogLevel::Info:
                    colorCode = "94";
                    break;
                case LogLevel::Debug:
                    colorCode = "32";
                    break;
                case LogLevel::Warn:
                    colorCode = "93";
                    break;
                case LogLevel::Error:
                    colorCode = "31";
                    break;
                }

                Utils::ReplaceAllInString(message.Text, "{PREFIX}", prefix);
                Utils::ReplaceAllInString(message.Text, "{COLOR_START}", "\033[" + colorCode + "m");
                Utils::ReplaceAllInString(message.Text, "{COLOR_END}", "\033[0m");
                std::cout << message.Text;
            }

            std::cout << std::endl;
            m_MessageBuffer.clear();
        }

        void sinkLoop()
        {
            while (m_Running)
            {
                sinkBuffer();
            }

            if (m_MessageBuffer.size() > 0)
                sinkBuffer();
        }
    };

}