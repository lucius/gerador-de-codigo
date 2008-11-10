/***********************************************
 * LogErros.cpp                                *
 *                                             *
 * Implementacao dos metodos da classe         *
 * LogErros                                    *
 *                                             *
 * @author: Evandro Couto Mantese              *
 * @author: Marcus Vinicius Ventura Bortolotti *
 * @author: Rafael de Paula Herrera            *
 *                                             *
 ***********************************************/


/*
 * Includes do Sistema
 */
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

/*
 * Includes do Usuario
 */
#include "./../includes/LogErros.h"



/*
 * inicializa o atributo fila
 * do log de erros
 */
std::queue<std::string>
LogErros::erros;



/**********************
 *  Metodos Publicos  *
 **********************/

/*
 * Retorna a instancia do Log de Erros
 */
LogErros&
LogErros::getInstancia( )
{
	static LogErros
	log;

	return log;
}

/*
 * Inclusao de Erros
 */
void
LogErros::insereErro( const unsigned int numeroLinha, const std::string erro )
{
	std::stringstream
	linhaErro;

	/*
	 * Formata o erro
	 */
	linhaErro << "[Linha " << numeroLinha << "] - " << erro;

	/*
	 * Enfileira o erro
	 */
	LogErros::erros.push( linhaErro.str() );
}

/*
 * Retorna os erros e retira-os da fila
 * se ela nao estiver vazia
 */
void
LogErros::getLog( )
{
	if ( !LogErros::erros.empty() )
	{
		while ( !LogErros::erros.empty() )
		{
			std::cout << LogErros::erros.front() << std::endl;
			LogErros::erros.pop( );
		}
	}
	else
	{
		std::cout << "Nao foram encontrados erros..." << std::endl << std::endl;
	}
}



/**********************
 * Metodos Protegidos *
 **********************/

LogErros::LogErros( )
{
}

LogErros::~LogErros( )
{
}



/**********************
 *  Metodos Privados  *
 **********************/

/*
 * Nao existem metodos privados
 * nesta classe
 */
