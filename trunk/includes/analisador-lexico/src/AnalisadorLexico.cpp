/***********************************************
 * AnalisadorLexico.cpp                        *
 *                                             *
 * Implementacao dos metodos da classe         *
 * AnalisadorLexico                            *
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
#include <regex.h>
#include <sstream>
#include <string>

/*
 * Includes do Usuario
 */
#include "./../includes/AnalisadorLexico.h"
#include "./../includes/ErrosExecucao.h"
#include "./../includes/StructToken.h"



/**********************
 *  Metodos Publicos  *
 **********************/

/*
 * Construtor utilizado no caso de existir um enderecamento
 * para o log do Analisador Lexico
 */
AnalisadorLexico::AnalisadorLexico( const std::string caminhoCodigo, const std::string caminhoLog )
{
	/*
	 * Tenta executar as acoes necessarias para que a execucao
	 * do Analisador Lexico ocorra com sucesso
	 */
	try
	{
		this->carregaCodigo( caminhoCodigo );

		this->automato = new AutomatoFD( this->codigoFonte );
		this->saidaAnalisadorLexico = this->automato->getSaidaAutomato( );

		this->salvaLog( caminhoLog );
	}
	/*
	 * Se houve algum erro na execucao de qualquer metodo acima
	 * ele e exibido
	 */
	catch ( ErrosExecucao* erro )
	{
		std::cout << erro->getErro( ) << std::endl;
		exit (1);
	}
}

/*
 * Construtor utilizado no caso de nao existir um enderecamento
 * para o log do Analisador Lexico
 */
AnalisadorLexico::AnalisadorLexico( const std::string caminhoCodigo )
{
	/*
	 * Tenta executar as acoes necessarias para que a execucao
	 * do Analisador Lexico ocorra com sucesso
	 */
	try
	{
		this->carregaCodigo( caminhoCodigo );

		this->automato = new AutomatoFD( this->codigoFonte );
		this->saidaAnalisadorLexico = this->automato->getSaidaAutomato( );

		this->ImprimeLog( );
	}
	/*
	 * Se houve algum erro na execucao de qualquer metodo acima
	 * ele e exibido
	 */
	catch ( ErrosExecucao* erro )
	{
		std::cout << erro->getErro( ) << std::endl;
		exit (1);
	}
}

/*
 * Desaloca a instancia da classe AutomatoFD
 */
AnalisadorLexico::~AnalisadorLexico( )
{
	delete this->automato;
}

std::map<int, StructToken>
AnalisadorLexico::getMapAnalisadorLexico( )
{
	return this->saidaAnalisadorLexico;
}


/**********************
 * Metodos Protegidos *
 **********************/

/*
 * Nao existem metodos protegidos
 * nesta classe
 */



/**********************
 *  Metodos Privados  *
 **********************/

/*
 * Carrega o codigo-fonte na memoria
 */
void
AnalisadorLexico::carregaCodigo( const std::string caminho )
{
	std::ifstream
	arquivoCodigo;

	std::string
	bufferLinhaCodigo;

	size_t
	found;

//	int
//	(*pf) (int) = tolower;

	char
	bufferCaractere[1024];

	regex_t
	expressaoRegular;

	/*
	 * Aloca a variavel de expressao regular
	 * Se o formato nao estiver correto, encerra a execucao
	 * Desaloca a variavel de expressao regular
	 */
	if ( regcomp(&expressaoRegular, ".pas$", REG_EXTENDED|REG_ICASE|REG_NOSUB) )	throw ( new ErrosExecucao("A expressao regular nao pode ser alocada") );

	if ( regexec(&expressaoRegular, caminho.c_str(), 0, (regmatch_t *)NULL, 0) ) throw ( new ErrosExecucao("O formato do arquivo nao e valido...") );

	regfree( &expressaoRegular );

	/*
	 * Abre o arquivo do código-fonte
	 * Se houver algum problema na abertura, encerra a execucao
	 * e retorna um erro
	 */
	arquivoCodigo.open( caminho.c_str(), std::ifstream::in );
	if ( arquivoCodigo.bad() ) throw ( new ErrosExecucao("O arquivo de codigo nao pode ser aberto!! Sucesso;;") );

	/*
	 * Move o ponteiro do arquivo para o inicio
	 */
	arquivoCodigo.seekg ( 0, std::ios::beg );

	/*
	 * Limpa o buffer da linha de Código
	 */
	bufferLinhaCodigo.clear( );

	/*
	 * Captura o codigo-fonte, caractere-a-caractere
	 * Elimina os tab's
	 * Separa linha-a-linha e armazena em uma lista de strings
	 */
	while ( arquivoCodigo.good() )
	{
		arquivoCodigo.getline( bufferCaractere, 1024 );
		bufferLinhaCodigo = bufferCaractere;
//		std::cout << bufferLinhaCodigo << " - " << bufferLinhaCodigo.size() << std::endl;

		found = bufferLinhaCodigo.find_first_of( '\t' );
		while( found != std::string::npos )
		{
			bufferLinhaCodigo.erase( found, 1 );
			found = bufferLinhaCodigo.find_first_of( '\t' );
		}

//		std::transform(bufferLinhaCodigo.begin( ), bufferLinhaCodigo.end( ), bufferLinhaCodigo.begin( ), pf);

		if ( bufferLinhaCodigo.size() != 0 )
		{
			this->codigoFonte.push_back( bufferLinhaCodigo + ' ' );
		}
		bufferLinhaCodigo.clear();

	}
	/*
	 * Fecha o arquivo do codigo-fonte
	 */
	arquivoCodigo.close( );
}

void
AnalisadorLexico::salvaLog( const std::string caminhoLog )
{
	std::map<int, StructToken>::iterator
	iteradorLog;

	std::stringstream
	buffer[ this->saidaAnalisadorLexico.size() ];

	std::string
	bufferString;

	unsigned int
	contadorBuffer = 0;

	std::ofstream
	arquivoLog;

	/*
	 * Tenta criar o arquivo de log
	 * se não conseguir para a execucao
	 */
	arquivoLog.open( caminhoLog.c_str(), std::ifstream::out );
	if ( arquivoLog.bad() ) throw ( new ErrosExecucao("O arquivo de log nao pode ser criado!! Sucesso;;") );

	/*
	 * Armazena as entradas do Array associativo formatadas em uma
	 * stream e escreve-as no arquivo
	 */
	for( iteradorLog = this->saidaAnalisadorLexico.begin(); iteradorLog != this->saidaAnalisadorLexico.end(); ++iteradorLog )
	{
		buffer[ contadorBuffer ] << '[' << iteradorLog->first << "] [" << iteradorLog->second.linha << "] [" << iteradorLog->second.token << "] [" << iteradorLog->second.classificacao << ']' << std::endl;

		bufferString = buffer[contadorBuffer].str();

		arquivoLog.write( bufferString.c_str(), bufferString.size() );

		++contadorBuffer;
	}
	arquivoLog.close( );
}

void
AnalisadorLexico::ImprimeLog( )
{
	std::map<int, StructToken>::iterator
	iteradorLog;

	std::stringstream
	buffer[ this->saidaAnalisadorLexico.size() ];

	unsigned int
	contadorBuffer = 0;

	/*
	 * Imprime as entradas do Array Associativo formatadas
	 * na saida padrao
	 */
	for( iteradorLog = this->saidaAnalisadorLexico.begin(); iteradorLog != this->saidaAnalisadorLexico.end(); ++iteradorLog )
	{
		buffer[ contadorBuffer ] << '[' << iteradorLog->first << "] [" << iteradorLog->second.linha << "] [" << iteradorLog->second.token << "] [" << iteradorLog->second.classificacao << ']';
		std::cout << buffer[ contadorBuffer ].str( ) << std::endl;

		++contadorBuffer;
	}
}
