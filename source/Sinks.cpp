#include "Sinks.hpp"
#include "Utils.hpp"

#include <iostream>

namespace CLog::Sink
{
	void ConsoleSink::Print(LogMessage &message)
	{
		std::string mut = message.Format; // Copy the string so we dont modify it for other sinks
		Utils::ReplaceInString(mut, "%{COLOR_START}", Utils::GetColorCodeForLevel(message.Level));
		Utils::ReplaceInString(mut, "%{MSG}", message.Message);
		Utils::ReplaceInString(mut, "%{NAME}", message.LoggerName);
		Utils::ReplaceInString(mut, "%{PREFIX}", Utils::GetPrefixForLevel(message.Level));
		mut += "\033[0m\n";
		std::cout << mut;
	}

	FileSink::FileSink(const std::string &filename)
	{
		m_File = std::ofstream(filename, std::ios::app);
	}

	FileSink::~FileSink()
	{
		m_File.close();
	}

	void FileSink::Print(LogMessage &message)
	{
		std::string mut = message.Message; // Copy the string so we dont modify it for other sinks
		Utils::ReplaceInString(mut, "%{COLOR_START}", "");
		Utils::ReplaceInString(mut, "%{PREFIX}", Utils::GetPrefixForLevel(message.Level));
		Utils::ReplaceInString(mut, "%{MSG}", message.Message);
		Utils::ReplaceInString(mut, "%{NAME}", message.LoggerName);
		m_File << mut + "\n";
	};
}
