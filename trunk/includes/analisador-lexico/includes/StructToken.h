/***********************************************
 * StructToken.h                               *
 *                                             *
 * Definicao da Estrutura                      *
 * StructToken                                 *
 *                                             *
 * @author: Evandro Couto Mantese              *
 * @author: Marcus Vinicius Ventura Bortolotti *
 * @author: Rafael de Paula Herrera            *
 *                                             *
 ***********************************************/



#ifndef STRUCTTOKEN_H_
#define STRUCTTOKEN_H_

/*
 * Includes do Sistema
 */
#include <iostream>
#include <string>



/*
 * Estrutura Utilizada para armazenamento das informações de cada Token
 */
typedef struct 
{
	std::string
	token;

	std::string
	classificacao;
	
	unsigned int
	linha;
} StructToken;

#endif /*STRUCTTOKEN_H_*/
