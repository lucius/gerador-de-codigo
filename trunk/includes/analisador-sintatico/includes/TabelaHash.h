#ifndef TABELAHASH_H_
#define TABELAHASH_H_

#include <ext/hash_map>
#include <map>
#include <iostream>
#include <string>

#include "../includes/FuncaoHash.h"
#include "../includes/ConteudoHash.h"


class TabelaHash : public __gnu_cxx::hash_multimap< std::string, ConteudoHash*, FuncaoHash<std::string> >
{
	public:
		TabelaHash::iterator
		operator[]( std::pair<const std::string, unsigned int> );
};

#endif /* TABELAHASH_H_ */
