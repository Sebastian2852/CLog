#pragma once

#include <string>
#include <fstream>

namespace CLog::Sink
{

	class BaseSink
	{
	public:
		BaseSink()
		{
		}

		~BaseSink() = default;

		virtual void print(std::string &str) = 0;
	};

	class ConsoleSink : public BaseSink
	{
	public:
		void print(std::string &str) override;
	};

	class FileSink : public BaseSink
	{
	public:
		FileSink(const std::string &filename);
		~FileSink();

		void print(std::string &str) override;

	private:
		std::ofstream m_File;
	};
}