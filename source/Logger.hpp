#pragma once

#include <string>
#include <iostream>
#include "LogLevel.hpp"

namespace CLog
{

	class Logger
	{
	public:
		Logger();
		~Logger();
		void Print(LogLevel level, std::string_view str);

	private:
		std::string GetColorCodeForLevel(LogLevel level);
	};

}