/***********************************************
 * TabelaSimbolos.h                            *
 *                                             *
 * Definicao da Classe                         *
 * TabelaSimbolos                              *
 *                                             *
 * @author: Evandro Couto Mantese              *
 * @author: Marcus Vinicius Ventura Bortolotti *
 * @author: Rafael de Paula Herrera            *
 *                                             *
 ***********************************************/



#ifndef TABELADESIMBOLOS_H_
#define TABELADESIMBOLOS_H_

/*
 * Includes do Sistema
 */
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

/*
 * Includes do Usuario
 */
#include "StructSimbolo.h"



/*
 * Classe de Armazenamento das classificacoes gerais dos tokens
 * 
 * Design Pattern Utilizado: Singleton
 */
class TabelaSimbolos
{
	public:
		static TabelaSimbolos*
		getInstancia( );

		const std::string 
		procuraSimbolo( std::string );

	protected:
		TabelaSimbolos( );

		TabelaSimbolos&
        operator=( TabelaSimbolos const& );

		virtual
		~TabelaSimbolos( );

	private:
		static TabelaSimbolos*
		instanciaTabelaSimbolos;

		std::map<std::string, std::string>
		simbolos;

		const std::vector<std::string>
		carregaArquivoConfiguracao( );

		void
		criaTabelaTokens( );
};

#endif /*TABELADESIMBOLOS_H_*/
