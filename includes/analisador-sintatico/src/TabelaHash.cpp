#include "../includes/TabelaHash.h"

TabelaHash::iterator
TabelaHash::operator[]( std::pair<const std::string, unsigned int> _elemento )
{
	TabelaHash::iterator
	_iterador = this->find( _elemento.first );

	size_t
	_quantidade;

	_quantidade = this->count( _elemento.first );

	if( _quantidade == 1 )
	{
		if( _iterador->second->getConteudo() == "variavel" )
		{
			if( _iterador->second->variavel->nivelLexico == _elemento.second )
			{
				return _iterador;
			}
		}
		else if( _iterador->second->getConteudo() == "parametrosFormais" )
		{
			if( _iterador->second->parametrosFormais->nivelLexico == _elemento.second )
			{
				return _iterador;
			}
		}
		else if( _iterador->second->getConteudo() == "procedimento|funcao" )
		{
			if( _iterador->second->procedureFunction->nivelLexico == _elemento.second )
			{
				return _iterador;
			}
		}
	}
	else if( _quantidade > 1 )
	{
		for( ; _iterador != this->end(); ++_iterador)
		{
			if( _iterador->second->getConteudo() == "variavel" )
			{
				if( _iterador->second->variavel->nivelLexico == _elemento.second )
				{
					return _iterador;
				}
			}
			else if( _iterador->second->getConteudo() == "parametrosFormais" )
			{
				if( _iterador->second->parametrosFormais->nivelLexico == _elemento.second )
				{
					return _iterador;
				}
			}
			else if( _iterador->second->getConteudo() == "procedimento|funcao" )
			{
				if( _iterador->second->procedureFunction->nivelLexico == _elemento.second )
				{
					return _iterador;
				}
			}
		}
	}

	return this->end();
}
