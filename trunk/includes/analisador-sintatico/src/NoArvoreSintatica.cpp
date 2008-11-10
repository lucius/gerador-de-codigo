#include <iostream>
#include <string>
#include <vector>

#include "../includes/NoArvoreSintatica.h"



NoArvoreSintatica::NoArvoreSintatica( std::string _descricao, int _nivelLexico, bool _isTerminal = false )
{
	this->setDescricao( _descricao );
	this->setNivelLexico( _nivelLexico );
	this->setIsTerminal( _isTerminal );
}

NoArvoreSintatica::~NoArvoreSintatica( )
{

}

const std::string
NoArvoreSintatica::getDescricao( )
{
	return this->descricao;
}

const int
NoArvoreSintatica::getNivelLexico( )
{
	return this->nivelLexico;
}

const bool
NoArvoreSintatica::getIsTerminal( )
{
	return this->isTerminal;
}

void
NoArvoreSintatica::setDescricao( const std::string _descricao )
{
	this->descricao = _descricao;
}

void
NoArvoreSintatica::setNivelLexico( const int _nivelLexico )
{
	this->nivelLexico = _nivelLexico;
}

void
NoArvoreSintatica::setIsTerminal( const bool _isTerminal )
{
	this->isTerminal = _isTerminal;
}

void
NoArvoreSintatica::insereFilho( std::string _descricao, int _nivelLexico, bool _isTerminal = true )
{
	NoArvoreSintatica*
	_noInsercao = new NoArvoreSintatica( _descricao, _nivelLexico, _isTerminal );

	this->filhos.push_back( _noInsercao );
}

void
NoArvoreSintatica::insereFilho( NoArvoreSintatica* _noInsercao )
{
	if( _noInsercao != NULL )
	{
		this->filhos.push_back( _noInsercao );
	}
}

std::vector<NoArvoreSintatica*>&
NoArvoreSintatica::getFilhos( )
{
	return this->filhos;
}
