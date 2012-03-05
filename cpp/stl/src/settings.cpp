#include "settings.h"
#include "utilities/logger.h"

#include <iostream>

Settings::Settings()
{
  _verbose = false;
  _debug = false;
  _logLevel = LOG_INFO;
}

void	Settings::init(int argc, char* argv[])
{
  int	opt;

  while ((opt = getopt(argc, argv, "hvc:")) != -1)
    {
      switch (opt)
	{
	case 'h':
	  usage(argc, argv);
	  break;
	case 'v':
	  _verbose = true;
	  break;
	case 'g':
	  _debug = true;
	  break;
	default:
	  usage(argc, argv);
	  ;
	}
    }
}

void	Settings::usage(int argc, char* argv[])
{
  std::cout << "Usage : " << argv[0] << "[h]" << std::endl;
  std::cout << "-h : show help." << std::endl;
  std::cout << "-v : verbose mode." << std::endl;
  std::cout << "-g : debug mode." << std::endl;
}

bool	Settings::isVerbose() const
{
  return _verbose;
}

bool	Settings::isDebug() const
{
  return _debug;
}

std::string	Settings::getConfFile() const
{
  return _confFile;
}

std::string	Settings::getLogFile() const
{
  return _logFile;
}

int		Settings::getLogLevel() const
{
  return _logLevel;
}
