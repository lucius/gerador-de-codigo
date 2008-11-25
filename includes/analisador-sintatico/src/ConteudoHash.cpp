#include <iostream>
#include <string>

#include "../includes/ConteudoHash.h"
#include "../includes/StructHashParametrosFormais.h"
#include "../includes/StructHashProcedureFunction.h"
#include "../includes/StructHashVariavel.h"



ConteudoHash::ConteudoHash( std::string _identificador, std::string _categoria, unsigned short int _nivelLexico, std::string _tipo, int _deslocamento )
{
	this->procedureFunction = NULL;
	this->parametrosFormais = NULL;

	this->variavel = new StructHashVariavel;

	this->variavel->identificador = _identificador;
	this->variavel->categoria = _categoria;
	this->variavel->nivelLexico = _nivelLexico;
	this->variavel->tipo = _tipo;
	this->variavel->deslocamento = _deslocamento;
}

ConteudoHash::ConteudoHash( std::string _identificador, std::string _categoria, unsigned short int _nivelLexico, std::string _tipo, int _deslocamento, bool _passagem )
{
	this->variavel = NULL;
	this->procedureFunction = NULL;

	this->parametrosFormais = new StructHashParametrosFormais;

	this->parametrosFormais->identificador = _identificador;
	this->parametrosFormais->categoria = _categoria;
	this->parametrosFormais->nivelLexico = _nivelLexico;
	this->parametrosFormais->tipo = _tipo;
	this->parametrosFormais->deslocamento = _deslocamento;
	this->parametrosFormais->passagem = _passagem;
}

ConteudoHash::ConteudoHash( std::string _identificador, std::string _categoria, unsigned short int _nivelLexico, std::string _tipo, int _deslocamento,  std::string _retorno, unsigned short int _quantidadeParametros )
{
	this->variavel = NULL;
	this->parametrosFormais = NULL;

	this->procedureFunction = new StructHashProcedureFunction;

	this->procedureFunction->identificador = _identificador;
	this->procedureFunction->categoria = _categoria;
	this->procedureFunction->nivelLexico = _nivelLexico;
	this->procedureFunction->tipo = _tipo;
	this->procedureFunction->deslocamento = _deslocamento;
	this->procedureFunction->retorno = _retorno;
	this->procedureFunction->quantidadeParametros = _quantidadeParametros;
}

std::string
ConteudoHash::getConteudo( )
{
	if( this->variavel != NULL )
	{
		return "variavel";
	}
	else if( this->procedureFunction != NULL )
	{
		return "procedimento|funcao";
	}
	else if( this->parametrosFormais != NULL )
	{
		return "parametrosFormais";
	}

	return "ERRO";
}


std::string
ConteudoHash::getTipo( )
{
	if( this->variavel != NULL )
	{
		return this->variavel->tipo;
	}
	else if( this->parametrosFormais != NULL )
	{
		return this->parametrosFormais->tipo;
	}
	else if( this->procedureFunction != NULL )
	{
		return this->procedureFunction->retorno;
	}

	return "ERRO";
}
