#include "logger.hpp"

static const QString	logLevel_str[] = {
	"CRITICAL",
	"ERROR",
	"WARNING",
	"NOTICE",
	"INFO",
	"DEBUG"
};

Logger::Logger()
{
  // Create or open log file
}

Logger::~Logger()
{
}

void	Logger::log(const string &message, logLevel level)
{
	Logger::instance()->update(message, level);
}

void	Logger::update(string msg, logLevel level)
{
	string	logMessage;

	logMessage = getLogPrefix();
	logMessage += logLevel_str[level] + " : " + msg + "\n";

	//qDebug() << logLevel_str[level] << " : " << msg;
	//	_logFile->write(logMessage.toAscii());
	//_logFile->flush();
}

std::string	Logger::getLogFileName()
{
  return DEFAULT_LOG_DIR + "/" + DEFAULT_LOG_FILE + "_" + QDateTime::currentDateTime().toString("yyyyMMdd") + "." + DEFAULT_LOG_EXT;
  return "";
}

std::string	Logger::getLogPrefix()
{
	return "<" + QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd-hh:mm:ss") + "> : ";
}

std::string	Logger::getLogHeader()
{
	return "\n# -- Starting new session --";
}
