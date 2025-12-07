// An example for having a custom sink which just prints out the messages
// with no prefixes or colors

#include <CLog/CLog.hpp>

class CustomSink : public CLog::Sinks::BaseSink
{
public:
    void Log(const CLog::LogMessage &message) override
    {
        std::string newString = message.Text;
        CLog::Utils::ReplaceAllInString(newString, "{PREFIX}", "");
        CLog::Utils::ReplaceAllInString(newString, "{COLOR_START}", "");
        CLog::Utils::ReplaceAllInString(newString, "{COLOR_END}", "");
        std::cout << newString;
    };
};

int main()
{
    CLog::Logger myLogger("{COLOR_START}[{PREFIX}] {MESSAGE}{COLOR_END}");
    myLogger.AddSink<CustomSink>();
    myLogger.Info("Hello World!");
    myLogger.Debug("Hello World!");
    myLogger.Warn("Hello World!");
    myLogger.Error("Hello World!");
}