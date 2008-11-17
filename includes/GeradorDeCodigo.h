#ifndef GERADORDECODIGO_H_
#define GERADORDECODIGO_H_

#include <iostream>
#include <list>
#include <map>
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

		std::string
		nomePrograma;

		std::stringstream
		bufferComandos;

		std::list<std::string>
		pilhaComandos;

		unsigned int
		nivelLexicoAtual;

		/*
		 * Labels de Desvio Incondicional
		 */
		std::map<std::string, std::string>
		indexLabel;

		unsigned int
		contadorLabel;

		std::vector<std::string>
		ultimosLabelsInseridos;

		/*
		 * Labels de Comandos Repetitivos
		 */
		unsigned int
		contadorLabelCR;

		std::vector<std::string>
		ultimosLabelsInseridosCR;

		/*
		 * Labels de Comandos Repetitivos
		 */
		unsigned int
		contadorLabelCC;

		std::vector<std::string>
		ultimosLabelsInseridosCC;

		void
		salvaCodigoMepa( );

		void
		iniciaGeracaoDeCodigo( );

		void
		bloco( NoArvoreSintatica* );

		void
		declaracaoDeRotulos( NoArvoreSintatica* );

		void
		declaracaoDeVariaveis( NoArvoreSintatica* );

		void
		declaracaoDeSubrotinas( NoArvoreSintatica* );

		void
		comandoComposto( NoArvoreSintatica* );

		void
		comando( NoArvoreSintatica* );

		void
		comandoSemRotulo( NoArvoreSintatica* );

		void
		comandoRepetitivo( NoArvoreSintatica* );

		void
		comandoCondicional( NoArvoreSintatica* );

		void
		desvios( NoArvoreSintatica* );

		void
		comandoLeitura( NoArvoreSintatica* );

		void
		comandoEscrita( NoArvoreSintatica* );

		void
		atribuicao( NoArvoreSintatica* );

		void
		chamadaFuncao( NoArvoreSintatica* );

		void
		chamadaProcedimento( NoArvoreSintatica* );

		void
		expressao( NoArvoreSintatica* );

		void
		relacao( NoArvoreSintatica* );

		void
		expressaoSimples( NoArvoreSintatica* );

		void
		termo( NoArvoreSintatica* );

		void
		fator( NoArvoreSintatica* );

		void
		empilhaComando( std::string );

		void
		desempilhaComando( );

		void
		atribuiLabel( std::string );

		void
		insereLabelNada( );

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
