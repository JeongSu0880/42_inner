#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
	private:
		const static std::string DEBUG;
		const static std::string INFO;
		const static std::string WARNING;
		const static std::string ERROR;
		const static int	NUMER_OF_LEVELS;

		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		Harl();
		~Harl();

		void	complain(std::string level);

};

#endif