#ifndef ANALISADORSEMANTICO_H_
#define ANALISADORSEMANTICO_H_

#include <iostream>

#include "../../analisador-sintatico/includes/ConteudoHash.h"
#include "../../analisador-sintatico/includes/NoArvoreSintatica.h"
#include "../../analisador-sintatico/includes/TabelaHash.h"

class AnalisadorSemantico
{
	public:
		AnalisadorSemantico( std::pair<TabelaHash*, NoArvoreSintatica*> );

		virtual
		~AnalisadorSemantico( );

	protected:

	private:
		TabelaHash
		hash;

		NoArvoreSintatica*
		raiz;

		NoArvoreSintatica*
		noCorrente;

		unsigned int
		nivelLexicoAtual;

		void
		analise( );

		/*
		 * Métodos vazios pois estas verificacoes ja
		 * foram realizadas no 'analisador-sintatico'
		 */

		void
		verificaDeclaracao( NoArvoreSintatica* );

		void
		verificaRedeclaracao( NoArvoreSintatica* );

		/*
		 * Fim das verificacoes ja realizadas
		 */

		void
		bloco( NoArvoreSintatica* );

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
		comandoLeitura( NoArvoreSintatica* );

		void
		atribuicao( NoArvoreSintatica* );

		std::string
		chamadaFuncao( NoArvoreSintatica* );

		std::string
		chamadaProcedimento( NoArvoreSintatica* );

		std::string
		expressao( NoArvoreSintatica* );

		std::string
		relacao( NoArvoreSintatica* );

		std::string
		expressaoSimples( NoArvoreSintatica* );

		std::string
		termo( NoArvoreSintatica* );

		std::string
		fator( NoArvoreSintatica* );
};


#endif /* ANALISADORSEMANTICO_H_ */
