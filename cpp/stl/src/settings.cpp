#include "settings.h"

#include <iostream>

void	Settings::init(int argc, char* argv[])
{
  int	opt;

  while ((opt = getopt(argc, argv, "h")) != -1)
    {
      switch (opt)
	{
	case 'h':
	  usage(argc, argv);
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
}
