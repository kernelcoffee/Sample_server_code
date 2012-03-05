#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include "utilities/singleton.h"
#include <string>

class	Settings : public Singleton<Settings>
{
  friend class Singleton<Settings>;

public:
  Settings();
  void	init(int, char**);
  void	usage(int, char**);
  bool	isVerbose(void) const;
  bool	isDebug(void) const;
  std::string	getConfFile(void) const;
  std::string	getLogFile(void) const;
  int		getLogLevel(void) const;
private:
  bool		_verbose;
  bool		_debug;
  std::string	_confFile;
  std::string	_logFile;
  int		_logLevel;
};

#endif
