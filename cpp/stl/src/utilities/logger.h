#ifndef __LOGMANAGER_HEADER_H__
#define __LOGMANAGER_HEADER_H__

#include "singleton.h"

#include <string>
#include <fstream>

#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#else
#define LOG_CRIT    2
#define LOG_ERR     3
#define LOG_WARNING 4
#define LOG_NOTICE  5
#define LOG_INFO    6
#define LOG_DEBUG   7
#endif

#define LOG_CONN    8

/**
 * This is the logging Class for maintenance, debug, etc.
 * it is able to display messages on console output and in a log file
 * set by the configuration file.
 **/

class Logger : public Singleton<Logger>
{
    friend class Singleton<Logger>;

public:
  static void log(const std::string &message, int level = LOG_INFO);
  static void debug(const std::string &message, int level = LOG_DEBUG);
  static void setToDebug(bool debug);

protected:
    Logger();
    ~Logger();
private:
  void		 initLogFile();
  int            updateLog(std::string msg, int level);
  std::string    logHeader() const;
  std::string    logFileName() const;
  
  std::ofstream   _logFile;
  bool            _debug;
};
#endif /*__LOGMANAGER_HEADER_H__*/
