#include "logger.h"
#include "settings.h"

#include <iostream>

/**
 * used for indentification into the log file
 **/

static const char* syslog_level[] = {
    NULL,
    NULL,
    "CRITICAL",
    "ERROR",
    "WARNING",
    "NOTICE",
    "INFO",
    "DEBUG",
    "CONNECT"
    };

Logger::Logger()
{
}

Logger::~Logger()
{
  this->_logFile.close();
}

void Logger::log(const std::string &message, int level)
{
    if (level <= Settings::instance()->getLogLevel())
      {
	if (Settings::instance()->isVerbose())
	  std::cout << syslog_level[level] << " : " << message << std::endl;
	Logger::instance()->updateLog(message, level);
      }
}

void	Logger::initLogFile()
{
  Settings* params = Settings::instance();

  this->_logFile.open(params->getLogFile().c_str());
  this->_logFile << logHeader() << std::endl;
  this->_logFile << params->getLogFile() << std::endl;
}

int Logger::updateLog(std::string msg, int level)
{
  if (this->_logFile.is_open())
    this->_logFile << syslog_level[level] << " : " << msg << std::endl;
  else
    Logger::instance()->initLogFile();
  return 0;
}

std::string Logger::logHeader() const
{
  return "# ";
}
