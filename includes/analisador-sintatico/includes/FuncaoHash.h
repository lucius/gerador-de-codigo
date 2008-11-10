#ifndef FUNCAOHASH_H_
#define FUNCAOHASH_H_

#include <ext/hash_map>
#include <iostream>



#define TAMANHO_HASH 211
#define CONSTANTE_ALFA 7

template<class T> class FuncaoHash : public __gnu_cxx::hash< T >
{
	public:
		FuncaoHash( ) {};

		std::size_t operator( )( std::string cadeiaEntrada ) const
		{
			unsigned long int
			h = 0;

			std::string::iterator
			caractere;

			for( caractere = cadeiaEntrada.begin(); caractere != cadeiaEntrada.end(); ++caractere )
			{
				h = ( h * CONSTANTE_ALFA ) + ( int )*caractere;
			}
			h = h % TAMANHO_HASH;

			return h;
		}
};

#endif /* FUNCAOHASH_H_ */
