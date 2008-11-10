/***********************************************
 * StructSimbolo.h                             *
 *                                             *
 * Definicao da Estrutura                      *
 * StructSimbolo                               *
 *                                             *
 * @author: Evandro Couto Mantese              *
 * @author: Marcus Vinicius Ventura Bortolotti *
 * @author: Rafael de Paula Herrera            *
 *                                             *
 ***********************************************/



#ifndef STRUCTSIMBOLO_H_
#define STRUCTSIMBOLO_H_

/*
 * Includes do Sistema
 */
#include <iostream>
#include <string>



/*
 * Estrutura utilizada para armazenar a classificacao geral
 * de cada token
 */
typedef struct
{
		std::string
		nome;

		std::string
		tipo;
} StructSimbolo;

#endif /*STRUCTSIMBOLO_H_*/
