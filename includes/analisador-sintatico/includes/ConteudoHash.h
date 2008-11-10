#ifndef CONTEUDOHASH_H_
#define CONTEUDOHASH_H_

#include <iostream>
#include <string>

#include "../includes/StructHashVariavel.h"
#include "../includes/StructHashProcedureFunction.h"
#include "../includes/StructHashParametrosFormais.h"



class ConteudoHash
{
	public:
		ConteudoHash( std::string, std::string, unsigned short int, std::string, int );

		ConteudoHash( std::string, std::string, unsigned short int, std::string, int, bool );

		ConteudoHash( std::string, std::string, unsigned short int, std::string, int, std::string, unsigned short int );

		std::string
		getConteudo( );

		std::string
		getTipo( );

		StructHashVariavel*
		variavel;

		StructHashProcedureFunction*
		procedureFunction;

		StructHashParametrosFormais*
		parametrosFormais;

	protected:

	private:
};

#endif /* CONTEUDOHASH_H_ */
