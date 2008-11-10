/***********************************************
 * ErrosExecucao.h                             *
 *                                             *
 * Definicao da Classe                         *
 * ErrosExecucao                               *
 *                                             *
 * @author: Evandro Couto Mantese              *
 * @author: Marcus Vinicius Ventura Bortolotti *
 * @author: Rafael de Paula Herrera            *
 *                                             *
 ***********************************************/


#ifndef ERROSEXECUCAO_H_
#define ERROSEXECUCAO_H_

/*
 * Includes do Sistema
 */
#include <iostream>
#include <string>



/*
 * Classe para tratamento de possiveis excecoes
 * em tempo de execucao
 */ 
class ErrosExecucao
{
	public:
		ErrosExecucao( std::string );

		const std::string
		getErro( );

	protected:
		virtual
		~ErrosExecucao( );

	private:
		std::string
		erro;
};

#endif /*ERROSEXECUCAO_H_*/
