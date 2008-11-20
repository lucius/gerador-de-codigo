#ifndef STRUCTHASHPROCEDUREFUNCTION_H_
#define STRUCTHASHPROCEDUREFUNCTION_H_

#include <iostream>
#include <vector>

typedef struct StructHashProcedureFunction
{
	std::string
	identificador;

	std::string
	categoria;

	unsigned int
	nivelLexico;

	std::string
	tipo;

	int
	deslocamento;

	std::string
	retorno;

	unsigned int
	quantidadeParametros;

	std::vector< std::pair<bool, std::string> >
	parametros;
};


#endif /* STRUCTHASHPROCEDUREFUNCTION_H_ */
