#include <iostream>
#include <sstream>

#include "../includes/stoi.h"

int
stoi( std::string _string )
{
	if( _string == "true" )
	{
		return 1;
	}
	else if( _string == "false" )
	{
		return 0;
	}
	else
	{
		return ::atoi( _string.c_str() );
	}
}
