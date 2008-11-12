#include <fstream>
#include <iostream>

#include "../includes/analisador-lexico/includes/ErrosExecucao.h"
#include "../includes/analisador-lexico/includes/LogErros.h"

#include "../includes/GeradorDeCodigo.h"

std::string
itos( int _inteiro )
{
	std::ostringstream
	_buffer;

	_buffer << _inteiro;

	return _buffer.str();
}


GeradorDeCodigo::GeradorDeCodigo( std::pair<TabelaHash*, NoArvoreSintatica*> _saidaAnalisadorSintatico )
{
	this->hash = *(_saidaAnalisadorSintatico.first);
	this->raiz = _saidaAnalisadorSintatico.second;

	this->noCorrente = this->raiz;

	this->iniciaGeracaoDeCodigo( );

	this->salvaCodigoMepa( );
}

GeradorDeCodigo::~GeradorDeCodigo( )
{

}

void
GeradorDeCodigo::salvaCodigoMepa( )
{
	std::ofstream
	_arquivoMepa;

	std::string
	_caminhoCodigo = "../execMepa/" + this->nomePrograma + ".mep";

	std::cout << _caminhoCodigo;

	std::string
	_stringBufferComandos;

	_arquivoMepa.open( _caminhoCodigo.c_str(), std::ifstream::out );

	if ( _arquivoMepa.bad() ) throw ( new ErrosExecucao("O arquivo de log nao pode ser aberto!! Sucesso;;") );

	_stringBufferComandos = this->bufferComandos.str( );

	_arquivoMepa.write( _stringBufferComandos.c_str(), _stringBufferComandos.size() );

	_arquivoMepa.close( );
}


void
GeradorDeCodigo::iniciaGeracaoDeCodigo( )
{
	std::vector<NoArvoreSintatica*>
	_filhos = this->noCorrente->getFilhos( );

	std::vector<NoArvoreSintatica*>::iterator
	_iteradorFilhos;

	this->nomePrograma = _filhos[1]->getFilhos( )[0]->getDescricao( );

	this->INPP( );

	this->empilhaComando( "PARA" );

	for( _iteradorFilhos = _filhos.begin(); _iteradorFilhos != _filhos.end(); ++_iteradorFilhos )
	{
		if( (*_iteradorFilhos)->getDescricao() == "<PARTE_DECLARACOES_VARIAVEIS>" )
		{
				this->noCorrente = (*_iteradorFilhos);
		}
	}

	this->declaracaoDeVariaveis( _filhos[_filhos.size()-2]->getFilhos()[0] );

	while( !this->pilhaComandos.empty() )
	{
		this->desempilhaComando( );
	}

}

void
GeradorDeCodigo::declaracaoDeVariaveis( NoArvoreSintatica* _parteDeclaracaoVariaveis )
{
	std::vector<NoArvoreSintatica*>
	_filhos = _parteDeclaracaoVariaveis->getFilhos( );

	unsigned int
	_quantidadeVariaveis = 0;

	unsigned int
	_contador;

	for( _contador = 1; _contador < _filhos.size(); _contador += 2 )
	{
		_quantidadeVariaveis += ( _filhos[_contador]->getFilhos()[0]->getFilhos().size() + 1 ) / 2;
	}

	this->AMEM( _quantidadeVariaveis );

	this->empilhaComando( "DMEM " + itos(_quantidadeVariaveis) );
}

void
GeradorDeCodigo::empilhaComando( std::string _comando )
{
	this->pilhaComandos.push_back( _comando );
}

void
GeradorDeCodigo::desempilhaComando( )
{
	this->bufferComandos << *(this->pilhaComandos.rbegin() ) << std::endl;
	this->pilhaComandos.pop_back( );
}

void
GeradorDeCodigo::CRCT( int K )
{
	this->bufferComandos << "CRCT " << K << std::endl;
}

void
GeradorDeCodigo::CRVL( int k, int n )
{
	this->bufferComandos << "CRVL " << k << " " << n << std::endl;
}

void
GeradorDeCodigo::SOMA( )
{
	this->bufferComandos << "SOMA" << std::endl;
}

void
GeradorDeCodigo::SUBT( )
{
	this->bufferComandos << "SUBT" << std::endl;
}

void
GeradorDeCodigo::MULT( )
{
	this->bufferComandos << "MULT" << std::endl;
}

void
GeradorDeCodigo::DIVI( )
{
	this->bufferComandos << "DIVI" << std::endl;
}

void
GeradorDeCodigo::CMIG( )
{
	this->bufferComandos << "CMIG" << std::endl;
}

void
GeradorDeCodigo::CMMA( )
{
	this->bufferComandos << "CMMA" << std::endl;
}

void
GeradorDeCodigo::CMME( )
{
	this->bufferComandos << "CMME" << std::endl;
}


void
GeradorDeCodigo::CMAG( )
{
	this->bufferComandos << "CMAG" << std::endl;
}

void
GeradorDeCodigo::CMEG( )
{
	this->bufferComandos << "CMEG" << std::endl;
}

void
GeradorDeCodigo::CMDG( )
{
	this->bufferComandos << "CMDG" << std::endl;
}

void
GeradorDeCodigo::CONJ( )
{
	this->bufferComandos << "CONJ" << std::endl;
}

void
GeradorDeCodigo::DISJ( )
{
	this->bufferComandos << "DISJ" << std::endl;
}

void
GeradorDeCodigo::NEGA( )
{
	this->bufferComandos << "NEGA" << std::endl;
}

void
GeradorDeCodigo::INVR( )
{
	this->bufferComandos << "INVR" << std::endl;
}


void
GeradorDeCodigo::ARMZ( int k, int n )
{
	this->bufferComandos << "ARMZ" << k << " " << n << std::endl;
}

void
GeradorDeCodigo::LEIT( )
{
	this->bufferComandos << "LEIT" << std::endl;
}

void
GeradorDeCodigo::IMPR( )
{
	this->bufferComandos << "IMPR" << std::endl;
}

void
GeradorDeCodigo::NADA( )
{
	this->bufferComandos << "NADA" << std::endl;
}

void
GeradorDeCodigo::DSVS( std::string label )
{
	this->bufferComandos << "DSVS " << label << std::endl;
}

void
GeradorDeCodigo::DSVF( std::string label )
{
	this->bufferComandos << "DSVF " << label << std::endl;
}

void
GeradorDeCodigo::INPP( )
{
	this->bufferComandos << "INPP" << std::endl;
}

void
GeradorDeCodigo::AMEM( int m )
{
	this->bufferComandos << "AMEM " << m << std::endl;
}

void
GeradorDeCodigo::DMEM( int n )
{
	this->bufferComandos << "DMEM " << n << std::endl;
}

void
GeradorDeCodigo::PARA( )
{
	this->bufferComandos << "PARA" << std::endl;
}

void
GeradorDeCodigo::CHPR( std::string label )
{
	this->bufferComandos << "CHPR " << label << std::endl;
}

void
GeradorDeCodigo::ENPR( int k )
{
	this->bufferComandos << "ENPR " << k << std::endl;
}

void
GeradorDeCodigo::RTPR( int k, int n )
{
	this->bufferComandos << "RTPR " << k << " " << n << std::endl;
}


void
GeradorDeCodigo::CRVI( int k, int n )
{
	this->bufferComandos << "CRVI " << k << " " << n << std::endl;
}

void
GeradorDeCodigo::ARMI( int k, int n )
{
	this->bufferComandos << "ARMI " << k << " " << n << std::endl;
}

void
GeradorDeCodigo::CREN( int k, int n )
{
	this->bufferComandos << "CREN " << k << " " << n << std::endl;
}
