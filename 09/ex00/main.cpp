#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc == 1 || !argv[1])
		std::cerr << "Error: could not open file." << std::endl;
	else
		BitcoinExchange	BTC(argv[1]);
	return (0);
}