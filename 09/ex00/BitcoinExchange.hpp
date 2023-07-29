#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RESET          "\033[0m"
# define GREY           "\033[0m\033[90m"
# define RED            "\033[0m\033[91m"
# define GREEN          "\033[0m\033[92m"
# define YELLOW         "\033[0m\033[93m"
# define BLUE           "\033[0m\033[94m"
# define MAGENTA        "\033[0m\033[95m"
# define CYAN           "\033[0m\033[96m"
# define WHITE          "\033[0m\033[97m"

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <map>
# include <stdlib.h>
# include <time.h>

class BitcoinExchange
{
private:
	std::map<double, double>	database;

	int		read_database(void);
	int		check_format(std::string line);
	int		check_date(std::string date_line);
	int		check_value(std::string value_line);
	bool	check_leap(int year);
	double	get_key(std::string date_line);

public:
	BitcoinExchange(void);
	BitcoinExchange(char *filename);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange(void);

	BitcoinExchange	&operator=(const BitcoinExchange &copy);
};

#endif