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

		bool
		analise( NoArvoreSintatica* );

		/*
		 * Métodos vazios pois estas verificacoes ja
		 * foram realizadas no 'analisador-sintatico'
		 */

		bool
		verificaDeclaracao( NoArvoreSintatica* );

		bool
		verificaRedeclaracao( NoArvoreSintatica* );

		/*
		 * Fim das verificacoes ja realizadas
		 */

		bool
		verificaAtribuicao( NoArvoreSintatica* );
};


#endif /* ANALISADORSEMANTICO_H_ */
