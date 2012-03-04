#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include "../singleton.h"

class	Settings : public Singleton<Settings>
{
public:
  void	init(int, char**);
  void	usage(int, char**);
private:
  
};

#endif
