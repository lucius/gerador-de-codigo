/***********************************************
 * AutomatoFD.cpp                              *
 *                                             *
 * Implementacao dos metodos da classe         *
 * AutomatoFD                                  *
 *                                             *
 * @author: Evandro Couto Mantese              *
 * @author: Marcus Vinicius Ventura Bortolotti *
 * @author: Rafael de Paula Herrera            *
 *                                             *
 ***********************************************/


/*
 * Includes do Sistema
 */
#include <assert.h>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <regex.h>
#include <string>

/*
 * Includes do Usuario
 */
#include "./../includes/AutomatoFD.h"
#include "./../includes/ErrosExecucao.h"
#include "./../includes/LogErros.h"
#include "./../includes/StructToken.h"
#include "./../includes/TabelaSimbolos.h"



/**********************
 *  Metodos Publicos  *
 **********************/

/*
 * Recebe por parametro uma lista contendo
 * o codigo-fonte separado por linhas.
 *
 * Limpa a string de buffer do Token
 *
 * Inicia o contador das Linhas
 * e o contador de Tokens
 */
AutomatoFD::AutomatoFD( std::list<std::string> codigoFonte )
{
	this->codigoPascal = codigoFonte;

	this->token.clear( );
	this->numeroLinha = 1;
	this->numeroToken = 1;

	this->estadoS( );
}

/*
 * Retorna os Tokens classificados
 */
const std::map<int, StructToken>
AutomatoFD::getSaidaAutomato( )
{
	return ( this->tokensClassificados );
}



/**********************
 * Metodos Protegidos *
 **********************/

AutomatoFD::~AutomatoFD( )
{
}



/**********************
 *  Metodos Privados  *
 **********************/

/*
 * Valida uma expressao regular em uma string
 */
const unsigned short int
AutomatoFD::validaCaractereREGEX( const char* stringExpressaoRegular, const char* linhaCodigo, std::string transicao )
{
	std::string
	erroExpressaoRegular = "A variavel de expressao regular nao pode ser alocada: Transicao " + transicao;

	regex_t
	expressaoRegular;

	int
	status;

	if ( !this->codigoPascal.empty() )
	{
		/*
		 * Tenta alocar a variavel de expressao regular
		 * Se ocorre algum erro, encerra a execucao
		 */
		if ( regcomp(&expressaoRegular, stringExpressaoRegular, REG_EXTENDED|REG_ICASE|REG_NOSUB) )	throw ( new ErrosExecucao(erroExpressaoRegular) );

		status = regexec(&expressaoRegular, linhaCodigo, 0, (regmatch_t *)NULL, 0);
		regfree( &expressaoRegular );
	}
	/*
	 * Retorna:
	 * 			0 - se nao encontrou ocorrencia da expressao na string
	 * 			1 - se encontrou no mínimo uma ocorrencia
	 */
	return ( !status );
}

/*
 * Concatena um caractere no fim da string
 */
void
AutomatoFD::adicionaCaractereToken( )
{
	if ( this->codigoPascal.begin()->empty() )
	{
		this->codigoPascal.pop_front( );
		++this->numeroLinha;
		this->adicionaTokenArrayAssociativo( );
	}
	else
	{
		/*
		 * Concatena um caractere no atributo token
		 * Remove um caractere do inicio da linha de codigo
		 */
		this->token.push_back( (*this->codigoPascal.begin()).at(0) );
		*this->codigoPascal.begin( ) = this->codigoPascal.begin()->substr(1);

		/*
		 * Se a linha fica vazia, remove-a da
		 * lista de linhas
		 */
		if ( (*this->codigoPascal.begin()).empty() )
		{
			this->codigoPascal.pop_front( );
			++this->numeroLinha;
			this->adicionaTokenArrayAssociativo( );
		}
	}
}

/*
 * Metodo utilizado para a leitura de comentarios
 */
void
AutomatoFD::adicionaCaractereComentario( )
{
	if ( (*this->codigoPascal.begin()).empty() )
	{
		this->codigoPascal.pop_front( );
		++this->numeroLinha;
	}
	else
	{
		this->token.push_back( (*this->codigoPascal.begin()).at(0) );
		*this->codigoPascal.begin( ) = (*this->codigoPascal.begin()).substr(1);

		if ( (*this->codigoPascal.begin()).empty() )
		{
			this->codigoPascal.pop_front( );
			++this->numeroLinha;
		}
	}
}

/*
 * Busca a classificacao de um Token
 * na Tabela de Simbolos
 *
 * Adiciona o token no Array de Tokens
 */
void
AutomatoFD::adicionaTokenArrayAssociativo( )
{
	StructToken
	bufferToken;

	if ( !this->token.empty() )
	{
		bufferToken.token = this->token;

		if ( this->validaCaractereREGEX("^[{]|\\(\\*", this->token.c_str(), "SD") )
		{
			bufferToken.classificacao = "COMENTARIO";
		}
		else
		{
			bufferToken.classificacao = TabelaSimbolos::getInstancia()->procuraSimbolo( this->token );
		}

		bufferToken.linha = this->numeroLinha;

		//std::cout << bufferToken.token << " @ " << bufferToken.classificacao << std::endl;

		tokensClassificados.insert ( std::pair<const int, const StructToken> (this->numeroToken, bufferToken) );

		++this->numeroToken;

		/*
		 * Limpa a linha de buffer do Token
		 */
		this->token.clear();
	}
}

/*
 * Recebe a classificacao de um Token
 * nao-padrao
 *
 * Adiciona o token no Array de Tokens
 */
void
AutomatoFD::adicionaTokenArrayAssociativo( const std::string _classificacao )
{
	StructToken
	bufferToken;

	if ( !this->token.empty() )
	{
		bufferToken.token = this->token;

		bufferToken.classificacao = _classificacao;

		bufferToken.linha = this->numeroLinha;

		//std::cout << bufferToken.token << " @ " << bufferToken.classificacao << std::endl;

		tokensClassificados.insert ( std::pair<const int, const StructToken> (this->numeroToken, bufferToken) );

		++this->numeroToken;

		this->token.clear();
	}
}



/*********************************************
 *********************************************
 **  				Estados  				**
 **					  do					**
 **					Automato 				**
 *********************************************
 *********************************************/

/*
 * Estado Inicial do Automado Finito e Deterministico
 */
void
AutomatoFD::estadoS()
{
	while( !this->codigoPascal.empty() )
	{
		try
		{
			/* Primeira Transicao */
			if ( this->validaCaractereREGEX("^[A-Z]", this->codigoPascal.begin()->c_str(), "SA") )
			{
				this->estadoA( );
			}
			else
			{
				/* Segunda Transicao */
				if ( this->validaCaractereREGEX("^[/|+|*|~|&|||=|;|.|,|-]", this->codigoPascal.begin()->c_str(), "SB") )
				{
					this->estadoB( );
				}
				else
				{
					/* Terceira Transicao */
					if ( this->validaCaractereREGEX("^<", this->codigoPascal.begin()->c_str(), "SC") )
					{
						this->estadoC( );
					}
					else
					{
						/* Quarta Transicao */
						if ( this->validaCaractereREGEX("^>", this->codigoPascal.begin()->c_str(), "SD") )
						{
							this->estadoD( );
						}
						else
						{
							/* Quinta Transicao */
							if ( this->validaCaractereREGEX("^[{]", this->codigoPascal.begin()->c_str(), "SE") )
							{
								this->estadoE( );
							}
							else
							{
								/* Sexta Transicao */
								if ( this->validaCaractereREGEX("^\\(", this->codigoPascal.begin()->c_str(), "SF") )
								{
									this->estadoF( );
								}
								else
								{
									/* Setima Transicao */
									if ( this->validaCaractereREGEX("^\\)", this->codigoPascal.begin()->c_str(), "SG") )
									{
										this->estadoG( );
									}
									else
									{
										/* Oitava Transicao */
										if ( this->validaCaractereREGEX("^[0-9]", this->codigoPascal.begin()->c_str(), "SH") )
										{
											this->estadoH( );
										}

										else
										{
											/* Nona Transicao */
											if ( this->validaCaractereREGEX("^:", this->codigoPascal.begin()->c_str(), "SI") )
											{
												this->estadoI( );
											}
											else
											{
												if ( this->validaCaractereREGEX("^[ |	]", this->codigoPascal.begin()->c_str(), "ESPACO_BRANCO") )
												{
													*this->codigoPascal.begin( ) = (*this->codigoPascal.begin()).substr(1);
												}
												else
												{
													if ( (*this->codigoPascal.begin()).size() == 0 )
													{
														this->codigoPascal.pop_front( );
														++this->numeroLinha;
													}
													else
													{
														/*
														 * Se nao reconhecer um caractere
														 * adiciona um erro no log
														 * e um token invalido
														 */
														LogErros::getInstancia( ).insereErro( this->numeroLinha, ":: " + (*this->codigoPascal.begin()).substr(0,1) + " :: " + "CARACTERE_INVALIDO" );
														this->adicionaCaractereToken( );
														this->adicionaTokenArrayAssociativo( "CARACTERE_INVALIDO" );
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		/*
		 * Se algum erro ocorrer na execucao deste trecho
		 * de codigo, exibe o erro e encerra a execucao
		 */
		catch ( ErrosExecucao* erro )
		{
			std::cout << erro->getErro( ) << std::endl;
		}
	}
}

/*
 * Valida Identificadores
 */
void
AutomatoFD::estadoA( )
{
	this->adicionaCaractereToken( );

	try
	{
		if( this->validaCaractereREGEX("^([A-Z]|[0-9]|_)", (*this->codigoPascal.begin()).c_str(), "AA") )
		{
			this->estadoA( );
		}
		else if( !this->validaCaractereREGEX("^[ |~|&|||.|,|:|;|+|=|>|<|\\(|\\)|*|/|-]", (*this->codigoPascal.begin()).c_str(), "AA") )
		{
			while( !this->validaCaractereREGEX("^[ |~|&|||.|,|:|;|+|=|>|<|\\(|\\)|*|/|-]", (*this->codigoPascal.begin()).c_str(), "AA") )
			{
				this->adicionaCaractereToken( );
			}
			LogErros::getInstancia( ).insereErro( this->numeroLinha, ":: " + this->token + " :: " + "IDENTIFICADOR_INVALIDO" );
			this->adicionaTokenArrayAssociativo( "IDENTIFICADOR_INVALIDO" );
		}
		else
		{
			this->adicionaTokenArrayAssociativo( );
		}
	}
	catch( ErrosExecucao* erro )
	{
		std::cout << erro->getErro( ) << std::endl;
	}
}

void
AutomatoFD::estadoB( )
{
	this->adicionaCaractereToken( );
	this->adicionaTokenArrayAssociativo( );
}

void
AutomatoFD::estadoC( )
{
	this->adicionaCaractereToken( );

	try
	{
		if( this->validaCaractereREGEX("^(>|=)", (*this->codigoPascal.begin()).c_str(), "CJ") )
		{
			this->estadoJ( );
		}
		else
		{
			this->adicionaTokenArrayAssociativo( );
		}
	}
	catch( ErrosExecucao* erro )
	{
		std::cout << erro->getErro( ) << std::endl;
	}
}

void
AutomatoFD::estadoD( )
{
	this->adicionaCaractereToken( );

	try
	{
		if( this->validaCaractereREGEX("^=", (*this->codigoPascal.begin()).c_str(), "DK") )
		{
			this->estadoK( );
		}
		else
		{
			this->adicionaTokenArrayAssociativo( );
		}
	}
	catch( ErrosExecucao* erro )
	{
		std::cout << erro->getErro( ) << std::endl;
	}
}

void
AutomatoFD::estadoE( )
{
	this->adicionaCaractereComentario( );

	while( (this->validaCaractereREGEX("^[^}]", (*this->codigoPascal.begin()).c_str(), "EE")) )
	{
		this->adicionaCaractereComentario( );
	}

	this->estadoL( );
}

void
AutomatoFD::estadoF( )
{
	this->adicionaCaractereToken( );

		try
		{
			if( this->validaCaractereREGEX("^[*]", (*this->codigoPascal.begin()).c_str(), "FM") )
			{
				this->estadoM( );
			}
			else
			{
				this->adicionaTokenArrayAssociativo( );
			}
		}
		catch( ErrosExecucao* erro )
		{
			std::cout << erro->getErro( ) << std::endl;
		}
}

void
AutomatoFD::estadoG( )
{
	this->adicionaCaractereToken( );
	this->adicionaTokenArrayAssociativo( );
}

/*
 * Valida Numeros válidos
 * e Identificadores Invalidos
 */
void
AutomatoFD::estadoH( )
{
	this->adicionaCaractereToken( );

	try
	{
		if( this->validaCaractereREGEX("^[0-9]", (*this->codigoPascal.begin()).c_str(), "HH") )
		{
			this->estadoH( );
		}
		else if( !this->validaCaractereREGEX("^[ |;|+|=|>|<|\\)|*|/|,|-]|^<=|^>=|^<>", (*this->codigoPascal.begin()).c_str(), "HH") )
		{
			while( !this->validaCaractereREGEX("^[ |;|+|=|>|<|\\)|*|/|,|-]|^<=|^>=|^<>", (*this->codigoPascal.begin()).c_str(), "HH") )
			{
				this->adicionaCaractereToken( );
			}
			LogErros::getInstancia( ).insereErro( this->numeroLinha, ":: " + this->token + " :: " + "IDENTIFICADOR_INVALIDO" );
			this->adicionaTokenArrayAssociativo( "IDENTIFICADOR_INVALIDO" );
		}

		this->adicionaTokenArrayAssociativo( "NUMERO" );
	}
	catch( ErrosExecucao* erro )
	{
		std::cout << erro->getErro( ) << std::endl;
	}
}

void
AutomatoFD::estadoI( )
{
	this->adicionaCaractereToken( );

	try
	{
		if( this->validaCaractereREGEX("^[=]", (*this->codigoPascal.begin()).c_str(), "IN") )
		{
			this->estadoN( );
		}
		else
		{
			this->adicionaTokenArrayAssociativo( );
		}
	}
	catch( ErrosExecucao* erro )
	{
		std::cout << erro->getErro( ) << std::endl;
	}
}

void
AutomatoFD::estadoJ( )
{
	this->adicionaCaractereToken( );
	this->adicionaTokenArrayAssociativo( );
}

void
AutomatoFD::estadoK( )
{
	this->adicionaCaractereToken( );
	this->adicionaTokenArrayAssociativo( );
}

void
AutomatoFD::estadoL( )
{
	this->adicionaCaractereComentario( );
	this->adicionaTokenArrayAssociativo( );
}

void
AutomatoFD::estadoM( )
{
	this->adicionaCaractereComentario( );

	while( (this->validaCaractereREGEX("^[^*]", (*this->codigoPascal.begin()).c_str(), "MM")) )
	{
		this->adicionaCaractereComentario( );
	}

	this->estadoO( );
}

void
AutomatoFD::estadoN( )
{
	this->adicionaCaractereToken( );
	this->adicionaTokenArrayAssociativo( );
}

void
AutomatoFD::estadoO( )
{
	this->adicionaCaractereComentario( );

		try
		{
			if( this->validaCaractereREGEX("^[\\)]", (*this->codigoPascal.begin()).c_str(), "OP") )
			{
				this->estadoP( );
			}
			else
			{
				this->estadoM( );
			}
		}
		catch( ErrosExecucao* erro )
		{
			std::cout << erro->getErro( ) << std::endl;
		}
}

void
AutomatoFD::estadoP( )
{
	this->adicionaCaractereComentario( );
	this->adicionaTokenArrayAssociativo( );
}
