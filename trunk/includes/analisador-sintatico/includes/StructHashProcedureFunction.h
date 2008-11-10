#ifndef STRUCTHASHPROCEDUREFUNCTION_H_
#define STRUCTHASHPROCEDUREFUNCTION_H_

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
};


#endif /* STRUCTHASHPROCEDUREFUNCTION_H_ */
