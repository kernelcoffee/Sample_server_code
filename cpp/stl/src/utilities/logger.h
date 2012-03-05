#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

/**
 * LOG_CRIT     This is catastrophic. Basically, the program can not recover
 *              from this. If you're going to log at this level provide
 *              as much information as possible.
 *
 * LOG_ERR      Okay, something bad happened. We can recover from this.
 *              This should be for things like when we cannot create
 *              a socket, or out of memory.
 *
 * LOG_WARNING  There is condition which will change the behaviour of
 *              the program from what is expected. For example, somebody did
 *              not specify a port for a socket.
 *
 * LOG_NOTICE   This is for a special condition. Nothing has gone wrong, but
 *              it is more important than the common LOG_INFO level.
 *              It is used for actions like creating/destroying children,
 *              unauthorized access, signal handling, etc.
 *
 * LOG_INFO     Everything else ends up here. Logging for incoming
 *              connections, denying due to filtering rules, unable to
 *              connect to remote server, etc.
 *
 * LOG_DEBUG    The default debug mode level for developping goodness.
 **/

const static QString DEFAULT_LOG_FILE = "logFile";	///< Log file name
const static QString DEFAULT_LOG_EXT = "log";

enum	logLevel {
	LOG_CRIT,
	LOG_ERR,
	LOG_WARNING,
	LOG_NOTICE,
	LOG_INFO,
	LOG_DEBUG
};

class Logger : public	Singleton<Logger>
{
	friend class Singleton<Logger>;

public:
	static void	log(const string &message, logLevel level = LOG_INFO);
protected:
    Logger();
	~Logger();
private:
	void		update(string msg, logLevel level);
	string		getLogFileName();
	string		getLogPrefix();
	string		getLogHeader();
	string		getLogFilePath();

	string		_logFilePath;
};

#endif // LOGGER_HPP
