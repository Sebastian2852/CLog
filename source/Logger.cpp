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
}
