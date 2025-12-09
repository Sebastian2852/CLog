#include "Sinks.hpp"

#include <iostream>

namespace CLog::Sink
{
	void ConsoleSink::print(std::string &str)
	{
		std::cout << str;
	}

	FileSink::FileSink(const std::string &filename)
	{
		m_File = std::ofstream(filename, std::ios::app);
	}

	FileSink::~FileSink()
	{
		m_File.close();
	}

	void FileSink::print(std::string &str)
	{
		m_File << str;
	};
}
