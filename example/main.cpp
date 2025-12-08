#include "CLog.hpp"

int main()
{
	CLog::Logger myLogger("CoolLogger");
	myLogger.Print(CLog::LogLevel::Trace, "Hello World!");
	myLogger.Print(CLog::LogLevel::Debug, "Hello World!");
	myLogger.Print(CLog::LogLevel::Info, "Hello World!");
	myLogger.Print(CLog::LogLevel::Warn, "Hello World!");
	myLogger.Print(CLog::LogLevel::Error, "Hello World!");
}