#ifndef NOARVORESINTATICA_H_
#define NOARVORESINTATICA_H_

#include <iostream>
#include <string>
#include <vector>



class NoArvoreSintatica
{
	public:
		NoArvoreSintatica( const std::string, const int, const bool );

		virtual
		~NoArvoreSintatica( );

		/*
		 * Metodos Get
		 */
		const std::string
		getDescricao( );

		const int
		getNivelLexico( );

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
		setIsTerminal( const bool );

		void
		insereFilho( const std::string, const int, const bool );

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

		bool
		isTerminal;

		std::vector<NoArvoreSintatica*>
		filhos;
};

#endif /* NOARVORESINTATICA_H_ */
