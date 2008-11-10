/***********************************************
 * LogErros.h                                  *
 *                                             *
 * Definicao da Classe                         *
 * LogErros                                    *
 *                                             *
 * @author: Evandro Couto Mantese              *
 * @author: Marcus Vinicius Ventura Bortolotti *
 * @author: Rafael de Paula Herrera            *
 *                                             *
 ***********************************************/



#ifndef LOGERROS_H_
#define LOGERROS_H_

/*
 * Includes do Sistema
 */
#include <iostream>
#include <string>
#include <queue>



/*
 * Classe Utilizada para armazenar os erros encontrados no codigo-fonte
 * e posteriormente exibi-los
 *
 * Design Pattern Utilizado: Singleton
 */
class LogErros
{
	public:
		static LogErros&
		getInstancia( );

		void
		insereErro( const unsigned int, const std::string );

		void
		getLog( );

	protected:
		LogErros( );

		virtual
		~LogErros( );

	private:
		static std::queue<std::string>
		erros;
};

#endif /*LOGERROS_H_*/
