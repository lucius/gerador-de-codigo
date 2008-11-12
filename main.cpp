#include <map>

#include "./includes/analisador-lexico/includes/StructToken.h"
#include "./includes/analisador-lexico/includes/AnalisadorLexico.h"
#include "./includes/analisador-lexico/includes/ErrosExecucao.h"
#include "./includes/analisador-lexico/includes/LogErros.h"

#include "./includes/analisador-sintatico/includes/AnalisadorSintatico.h"
#include "./includes/analisador-sintatico/includes/ConteudoHash.h"
#include "./includes/analisador-sintatico/includes/StructHashVariavel.h"

#include "./includes/analisador-semantico/includes/AnalisadorSemantico.h"

#include "./includes/GeradorDeCodigo.h"


int
main(int argc, char* argv[])
{
	/*
	 * Instancia o Analisador Lexico
	 */
	AnalisadorLexico*
	lexico;

	AnalisadorSintatico*
	sintatico;

	AnalisadorSemantico*
	semantico;

	GeradorDeCodigo*
	gerador;

	try
	{
		/*
		 * Verifica se foi especificado o nome do arquivo-fonte
		 */
		if ( argv[1] == NULL ) throw ( new ErrosExecucao("Voce Precisa Definir qual arquivo sera compilado") );
		/*
		 * Verifica se foi especificado o arquivo no qual o log do Analisador Lexico será salvo
		 */
		else if ( argv[2] )
		{
			lexico = new AnalisadorLexico( argv[1], argv[2] );
			if( LogErros::getInstancia( ).getQuantidadeErros() )
			{
				sintatico = new AnalisadorSintatico( lexico->getMapAnalisadorLexico(), argv[2] );
			}
		}
		/*
		 * Se nao foi especificado um nome para o log, o resultado será exibido na saida padrao do sistema
		 */
		else
		{
			lexico = new AnalisadorLexico( argv[1] );
			if( LogErros::getInstancia( ).getQuantidadeErros() )
			{
				sintatico = new AnalisadorSintatico( lexico->getMapAnalisadorLexico() );
			}
		}

		if( LogErros::getInstancia( ).getQuantidadeErros() )
		{
			semantico = new AnalisadorSemantico( sintatico->getSaidaAnalisadorSintatico() );
			gerador = new GeradorDeCodigo( sintatico->getSaidaAnalisadorSintatico() );
		}
	}
	/*
	 * Se ocorrer algum problema durante a execucao do Analisador Lexico, o erro sera exibido
	 */
	catch ( ErrosExecucao* erro )
	{
		std::cout << erro->getErro( );
	}

	/*
	 * Exibe o log de Erros do Analisador
	 */
	LogErros::getInstancia( ).getLog( );

	return (EXIT_SUCCESS);
}
