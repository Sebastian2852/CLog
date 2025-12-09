#include "Logger.hpp"
#include "Utils.hpp"

#include <iostream>

namespace CLog
{
	Logger::Logger(std::string name, std::string format)
		: m_Name(name), m_LogFormat(format)
	{
	}

	Logger::~Logger()
	{
	}

	void Logger::Print(LogLevel level, std::string str)
	{
		std::string logMessage = m_LogFormat;

		LogMessage msg;
		msg.Format = m_LogFormat;
		msg.LoggerName = m_Name;
		msg.Level = level;
		msg.Message = str;

		for (auto sink : m_Sinks)
		{
			sink->Print(msg);
		}
	}
}
