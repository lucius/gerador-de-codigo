/***********************************************
 * ErrosExecucao.cpp                           *
 *                                             *
 * Implementacao dos metodos da classe         *
 * ErrosExecucao                               *
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
#include <string>

/*
 * Includes do Usuario
 */
#include "./../includes/ErrosExecucao.h"



/*
 * Recebe um erro como parametro
 * e armazena-o no atributo
 * "erro"
 */
ErrosExecucao::ErrosExecucao( std::string _erro )
{
	this->erro = _erro;
}

/*
 * Retorna a mensagem de erro
 */
const std::string
ErrosExecucao::getErro( )
{
	return this->erro;
}

ErrosExecucao::~ErrosExecucao( )
{
}
