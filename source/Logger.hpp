#pragma once

#include <string>
#include <vector>
#include <memory>

#include "fmt/format.h"

#include "LogLevel.hpp"
#include "Sinks.hpp"

namespace CLog
{
	constexpr std::string_view DefaultFormat = "%{COLOR_START}[%{PREFIX}] [%{NAME}] %{MSG}";

	class Logger
	{
	public:
		Logger(std::string name = "", std::string format = std::string(DefaultFormat));
		~Logger();

		template <typename... Args>
		void Print(LogLevel level, fmt::format_string<Args...> format, Args &&...args)
		{
			std::string logMessage = m_LogFormat;

			LogMessage msg;
			msg.Format = m_LogFormat;
			msg.LoggerName = m_Name;
			msg.Level = level;
			msg.Message = fmt::format(format, std::forward<Args>(args)...);

			for (auto sink : m_Sinks)
			{
				sink->Print(msg);
			}
		}

		template <typename T, typename... Args>
		void AddSink(Args &&...args)
		{
			m_Sinks.emplace_back(std::make_shared<T>(std::forward<Args>(args)...));
		}

		template <typename... Args>
		void Trace(fmt::format_string<Args...> format, Args &&...args) { Print(LogLevel::Trace, format, std::forward<Args>(args)...); }
		template <typename... Args>
		void Info(fmt::format_string<Args...> format, Args &&...args) { Print(LogLevel::Info, format, std::forward<Args>(args)...); }
		template <typename... Args>
		void Debug(fmt::format_string<Args...> format, Args &&...args) { Print(LogLevel::Debug, format, std::forward<Args>(args)...); }
		template <typename... Args>
		void Warn(fmt::format_string<Args...> format, Args &&...args) { Print(LogLevel::Warn, format, std::forward<Args>(args)...); }
		template <typename... Args>
		void Error(fmt::format_string<Args...> format, Args &&...args) { Print(LogLevel::Error, format, std::forward<Args>(args)...); }

	private:
		std::string m_Name;
		std::string m_LogFormat;
		std::vector<std::shared_ptr<Sink::BaseSink>> m_Sinks;
	};

}