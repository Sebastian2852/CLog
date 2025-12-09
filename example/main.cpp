#include "CLog.hpp"

int main()
{
	CLog::Logger myLogger("CoolLogger");
	myLogger.AddSink<CLog::Sink::ConsoleSink>();
	myLogger.AddSink<CLog::Sink::FileSink>("Debug.log");
	myLogger.Print(CLog::LogLevel::Trace, "Hello World!");
	myLogger.Print(CLog::LogLevel::Debug, "Hello World!");
	myLogger.Print(CLog::LogLevel::Info, "Hello World!");
	myLogger.Print(CLog::LogLevel::Warn, "Hello World!");
	myLogger.Print(CLog::LogLevel::Error, "Hello World!");
}