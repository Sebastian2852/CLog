#include "Logger.hpp"

namespace CLog
{

	Logger::Logger()
	{
	}

	Logger::~Logger()
	{
	}

	void Logger::Print(LogLevel level, std::string_view str)
	{
		std::cout << GetColorCodeForLevel(level) << str << "\033[0m\n";
	}

	std::string Logger::GetColorCodeForLevel(LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Info:
			return "\033[94m";
		case LogLevel::Debug:
			return "\033[32m";
		case LogLevel::Warn:
			return "\033[93m";
		case LogLevel::Error:
			return "\033[31m";
		}
		return "\033[0m";
	}
}
