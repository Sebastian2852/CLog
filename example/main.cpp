#include "CLog.hpp"

int main()
{
	// Basic logger
	{
		CLog::Logger myLogger("Basic Logger");
		myLogger.AddSink<CLog::Sink::ConsoleSink>();
		myLogger.AddSink<CLog::Sink::FileSink>("BasicLogger.log");
		myLogger.Trace("Hello World!");
		myLogger.Debug("Hello World!");
		myLogger.Info("Hello World!");
		myLogger.Warn("Hello World!");
		myLogger.Error("Hello World!");
	}

	// Custom formatted logger
	{
		CLog::Logger myLogger("Custom Format Logger", "%{NAME} - %{PREFIX}: %{COLOR_START}%{MSG}");
		myLogger.AddSink<CLog::Sink::ConsoleSink>();
		myLogger.AddSink<CLog::Sink::FileSink>("CustomFormattedLogger.log");
		myLogger.Trace("Hello World!");
		myLogger.Debug("Hello World!");
		myLogger.Info("Hello World!");
		myLogger.Warn("Hello World!");
		myLogger.Error("Hello World!");
	}
}