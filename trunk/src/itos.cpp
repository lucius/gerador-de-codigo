#include <iostream>
#include <sstream>

std::string
itos( int _inteiro )
{
	std::ostringstream
	_buffer;

	_buffer << _inteiro;

	return _buffer.str();
}
