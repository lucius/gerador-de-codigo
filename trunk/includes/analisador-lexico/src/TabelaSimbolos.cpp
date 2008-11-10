/***********************************************
 * TabelaSimbolos.cpp                          *
 *                                             *
 * Implementacao dos metodos da classe         *
 * TabelaSimbolos                              *
 *                                             *
 * @author: Evandro Couto Mantese              *
 * @author: Marcus Vinicius Ventura Bortolotti *
 * @author: Rafael de Paula Herrera            *
 *                                             *
 ***********************************************/


/*
 * Includes do Sistema
 */
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

/*
 * Includes do Usuario
 */
#include "./../includes/ErrosExecucao.h"
#include "./../includes/StructSimbolo.h"
#include "./../includes/TabelaSimbolos.h"



/*
 * Inicializa o atributo
 * da instancia da Tabela de Simbolos
 */
TabelaSimbolos*
TabelaSimbolos::instanciaTabelaSimbolos = 0;



/**********************
 *  Metodos Publicos  *
 **********************/

/*
 * Se a classe nao foi instanciada nenhuma vez,
 * ela e instanciada
 *
 * Retorna a intancia
 * da propria classe
 */
TabelaSimbolos*
TabelaSimbolos::getInstancia( )
{
	if ( TabelaSimbolos::instanciaTabelaSimbolos == NULL)
	{
		TabelaSimbolos::instanciaTabelaSimbolos = new TabelaSimbolos( );
    }

	return TabelaSimbolos::instanciaTabelaSimbolos;
}

/*
 * Recebe o Token Procurado e retorna,
 * se encontrar, sua classificacao.
 *
 * Senao retorna "IDENTIFICADOR"
 * como padrão.
 */
const std::string
TabelaSimbolos::procuraSimbolo( std::string tokenProcurado )
{
	std::map<std::string, std::string>::iterator
	iteradorBusca;

	iteradorBusca = TabelaSimbolos::instanciaTabelaSimbolos->simbolos.find( tokenProcurado );

	if ( iteradorBusca != TabelaSimbolos::instanciaTabelaSimbolos->simbolos.end() )
	{
		return iteradorBusca->second;
	}
	else
	{
		return "IDENTIFICADOR";
	}
}



/**********************
 * Metodos Protegidos *
 **********************/

/*
 * Construtor
 */
TabelaSimbolos::TabelaSimbolos( )
{
	this->criaTabelaTokens( );
}

TabelaSimbolos::~TabelaSimbolos( )
{

}



/**********************
 *  Metodos Privados  *
 **********************/

/*
 * Carrega o Arquivo de Configuracoes para a memoria
 */
const std::vector<std::string>
TabelaSimbolos::carregaArquivoConfiguracao( )
{
	std::ifstream
	arquivoConfiguracao ( "../data/pascal.conf", std::ifstream::in );

	std::string
	_buffer;

	std::vector<std::string>
	primeiroParser;

	/*
	 * Tenta abrir o arquivo de Configuracoes.
	 * Se nao for possivel finaliza a execucao.
	 */
	if ( !arquivoConfiguracao.good() ) throw ( new ErrosExecucao("O arquivo de Configuracoes nao pode ser aberto! Sucesso;;") );
	/*
	 * Move o ponteiro do arquivo
	 * para o inicio
	 */
	arquivoConfiguracao.seekg( 0, std::ios::beg );

	/*
	 * Carrega o arquivo linha-a-linha
	 */
	while ( !arquivoConfiguracao.eof() )
	{
		arquivoConfiguracao >> _buffer;
		primeiroParser.push_back( _buffer );
	}

	/*
	 * Fecha o arquivo de configuracoes
	 */
	arquivoConfiguracao.close( );

	/*
	 * Retorna o vetor contendo as linhas
	 * do arquivo de configuracoes
	 */
	return primeiroParser;
}

/*
 * Inicia um Array Associando
 * um token a sua classificacao
 */
void
TabelaSimbolos::criaTabelaTokens( )
{
	size_t
	posicao;

	std::vector<std::string>::iterator
	iteradorPrimeiroParser;

	const std::string
	caracterProcurado = "@";

	std::string
	tipoTemporario;

	std::vector<std::string>
	PrimeiroParser;
	PrimeiroParser = this->carregaArquivoConfiguracao( );

	/*
	 * Classifica os tokens
	 * iterando o vetor onde estao armazenados
	 * e insere-os no Array Associativo
	 */
	for (iteradorPrimeiroParser = PrimeiroParser.begin(); iteradorPrimeiroParser != PrimeiroParser.end(); ++iteradorPrimeiroParser)
	{
		posicao = iteradorPrimeiroParser->find( caracterProcurado );

		if ( posicao != std::string::npos )
		{
			tipoTemporario = iteradorPrimeiroParser->substr( posicao+1, iteradorPrimeiroParser->size() );
			++iteradorPrimeiroParser;
		}

		this->simbolos.insert ( std::pair<const std::string, const std::string> (*iteradorPrimeiroParser, tipoTemporario) );
	}
}
