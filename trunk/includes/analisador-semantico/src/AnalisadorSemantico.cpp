#include <iostream>
#include <vector>

#include "../includes/AnalisadorSemantico.h"

AnalisadorSemantico::AnalisadorSemantico( std::pair<TabelaHash*, NoArvoreSintatica*> _saidaAnalisadorSintatico )
{
	this->hash = *(_saidaAnalisadorSintatico.first);
	this->raiz = _saidaAnalisadorSintatico.second;

	this->nivelLexicoAtual = 0;

	this->analise( this->raiz );
}

AnalisadorSemantico::~AnalisadorSemantico( )
{
}

bool
AnalisadorSemantico::analise( NoArvoreSintatica* _analise )
{
	size_t
	_quantidadeFilhos = _analise->getFilhos( ).size( );

	size_t
	_contador;

	std::vector<NoArvoreSintatica*>
	_filhos = _analise->getFilhos( );

	std::string
	_descricao;

	for( _contador = 0; _contador < _quantidadeFilhos; ++_contador )
	{
		_descricao = _filhos[_contador]->getDescricao( );

		if( _descricao == "<ATRIBUICAO>" )
		{
			this->verificaAtribuicao( _filhos[_contador] );
		}
		else
		{
			this->analise( _filhos[_contador] );
		}
	}
	return true;
}

bool
AnalisadorSemantico::verificaDeclaracao( NoArvoreSintatica* )
{
	return true;
}

bool
AnalisadorSemantico::verificaRedeclaracao( NoArvoreSintatica* )
{
	return true;
}

bool
AnalisadorSemantico::verificaAtribuicao( NoArvoreSintatica* _atribuicao )
{
	std::string
	_tipoVariavel;

	std::string
	_nomeVariavel;

	if( _atribuicao->getFilhos()[0]->getDescricao() == "<VARIAVEL>" )
	{
		_nomeVariavel = _atribuicao->getFilhos()[0]->getFilhos()[0]->getFilhos()[0]->getDescricao();
		_tipoVariavel = this->hash[std::pair<const std::string, const unsigned int>(_nomeVariavel, this->nivelLexicoAtual)]->second->getTipo( );
		std::cout << _tipoVariavel;
	}

	return true;
}





















