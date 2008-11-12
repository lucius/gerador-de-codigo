#ifndef GERADORDECODIGO_H_
#define GERADORDECODIGO_H_

#include <iostream>
#include <list>
#include <queue>
#include <sstream>

#include "./analisador-sintatico/includes/ConteudoHash.h"
#include "./analisador-sintatico/includes/NoArvoreSintatica.h"
#include "./analisador-sintatico/includes/TabelaHash.h"

class GeradorDeCodigo
{
	public:
		GeradorDeCodigo( std::pair<TabelaHash*, NoArvoreSintatica*> );

		virtual
		~GeradorDeCodigo( );
	protected:

	private:
		TabelaHash
		hash;

		NoArvoreSintatica*
		raiz;

		NoArvoreSintatica*
		noCorrente;

		std::string
		nomePrograma;

		std::stringstream
		bufferComandos;

		std::list<std::string>
		pilhaComandos;

		void
		salvaCodigoMepa( );

		void
		iniciaGeracaoDeCodigo( );

		void
		declaracaoDeVariaveis( NoArvoreSintatica* );

		void
		empilhaComando( std::string );

		void
		desempilhaComando( );

		void
		CRCT( int );

		void
		CRVL( int, int );

		void
		SOMA( );

		void
		SUBT( );

		void
		MULT( );

		void
		DIVI( );

		void
		CMIG( );

		void
		CMMA( );

		void
		CMME( );

		void
		CMAG( );

		void
		CMEG( );

		void
		CMDG( );

		void
		CONJ( );

		void
		DISJ( );

		void
		NEGA( );

		void
		INVR( );

		void
		ARMZ( int, int );

		void
		LEIT( );

		void
		IMPR( );

		void
		NADA( );

		void
		DSVS( std::string );

		void
		DSVF( std::string );

		void
		INPP( );

		void
		AMEM( int );

		void
		DMEM( int );

		void
		PARA( );

		void
		CHPR( std::string );

		void
		ENPR( int );

		void
		RTPR( int, int );

		void
		CRVI( int, int );

		void
		ARMI( int, int );

		void
		CREN( int, int );
};

#endif /* GERADORDECODIGO_H_ */
