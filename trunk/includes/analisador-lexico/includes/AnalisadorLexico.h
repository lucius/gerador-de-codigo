/***********************************************
 * AnalisadorLexico.h                          *
 *                                             *
 * Definicao da Classe                         *
 * AnalisadorLexico                            *
 *                                             *
 * @author: Evandro Couto Mantese              *
 * @author: Marcus Vinicius Ventura Bortolotti *
 * @author: Rafael de Paula Herrera            *
 *                                             *
 ***********************************************/



#ifndef ANALISADORLEXICO_H_
#define ANALISADORLEXICO_H_

/*
 * Includes do Sistema
 */
#include <iostream>
#include <list>
#include <map>
#include <string>

/*
 * Includes do Usuario
 */
#include "./AutomatoFD.h"
#include "./StructToken.h"



/*
 * Classe utilizada para gerenciar a execucao do
 * Analisador Lexico
 */
class AnalisadorLexico
{
	public:
		AnalisadorLexico( const std::string, const std::string );

		AnalisadorLexico( const std::string );

		std::map<int, StructToken>
		getMapAnalisadorLexico( );

	protected:
		virtual
		~AnalisadorLexico( );

	private:
		AutomatoFD*
		automato;

		std::list<std::string>
		codigoFonte;

		std::map<int, StructToken>
		saidaAnalisadorLexico;

		void
		carregaCodigo( const std::string );

		void
		salvaLog( const std::string );

		void
		ImprimeLog( );
};

#endif /*ANALISADORLEXICO_H_*/
