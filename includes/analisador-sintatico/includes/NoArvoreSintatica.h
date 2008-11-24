#ifndef NOARVORESINTATICA_H_
#define NOARVORESINTATICA_H_

#include <iostream>
#include <string>
#include <vector>



class NoArvoreSintatica
{
	public:
		NoArvoreSintatica( const std::string, const int, const bool, const unsigned int );

		virtual
		~NoArvoreSintatica( );

		/*
		 * Metodos Get
		 */
		const std::string
		getDescricao( );

		const int
		getNivelLexico( );

		const int
		getLinha( );

		const bool
		getIsTerminal( );

		/*
		 * Metodos Set
		 */
		void
		setDescricao( const std::string );

		void
		setNivelLexico( const int );

		void
		setLinha( const unsigned int );

		void
		setIsTerminal( const bool );

		void
		insereFilho( const std::string, const int, const bool, const unsigned int );

		void
		insereFilho( NoArvoreSintatica* );

		std::vector<NoArvoreSintatica*>&
		getFilhos( );

	protected:

	private:
		std::string
		descricao;

		int
		nivelLexico;

		unsigned int
		linha;

		bool
		isTerminal;

		std::vector<NoArvoreSintatica*>
		filhos;
};

#endif /* NOARVORESINTATICA_H_ */
