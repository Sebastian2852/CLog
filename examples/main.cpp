// Basic example which shows off the primary features of CLog

#include <CLog/CLog.hpp>

int main()
{
    CLog::Logger myLogger;
    myLogger.AddSink<CLog::Sinks::ConsoleSink>();
    myLogger.AddSink<CLog::Sinks::FileSink>("latest.log");
    myLogger.Info("Hello World!");
    myLogger.Debug("Hello World!");
    myLogger.Warn("Hello World!");
    myLogger.Error("Hello World!");
}