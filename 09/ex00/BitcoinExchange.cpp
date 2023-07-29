#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) { *this = copy; }
BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy) {
	this->database = copy.database;
	return (*this);
}

BitcoinExchange::BitcoinExchange(char *filename)
{
	if (read_database())
		return ;

	std::ifstream	infile(filename);
	std::string		line;
	std::string		date_line;
	std::string		value_line;
	double			key;
	double			amount;

	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	while (!infile.eof())
	{	
		std::getline(infile, line);
		if (infile.eof() && line.length() == 0)
			break ;
		if (check_format(line) || line.length() == 0)
			continue;
		date_line = line.substr(0, line.find('|'));
		value_line = line.substr(line.find('|') + 1, line.length() - line.find('|') - 1);
		if (check_date(date_line) || check_value(value_line))
			continue;
		key = get_key(date_line);
		amount = atof(value_line.c_str());
		std::map<double, double>::iterator it = this->database.begin();
		while (it != this->database.end())
		{
			if (key >= it->first)
				++it;
			else
				break ;
		}
		--it;
		std::cout << date_line << "=> " << amount << " = " << std::setprecision(10) << it->second * amount << std::endl;
	}
	infile.close();
}

int		BitcoinExchange::check_format(std::string line)
{
	// ignoring the first line (if it exists)
	if (line == "date | value")
		return (1);
	// check for unknown characters
	if (line.find_first_not_of("0123456789|-+. \r\t\b\f") != std::string::npos) {
		std::cerr<< "Error: bad input => " << line << std::endl;
		return (1);
	}
	// check if the partition between date and value exists
	if (line.find_first_of("|") == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (1);
	}
	return (0);
}

int		BitcoinExchange::check_value(std::string value_line)
{
	size_t	pos;
	// check if value is empty
	if (value_line.find_first_not_of(" \r\t\b\f") == std::string::npos) {
		std::cerr << "Error: empty value" << std::endl;
		return (1);
	}
	// check for invalid characters
	if (value_line.find_first_not_of("-0123456789. \r\t\b\f") != std::string::npos) {
		std::cerr << "Error: invalid value" << std::endl;
		return (1);
	}
	// check for invalid character layout
	pos = value_line.find_first_of("-0123456789.");
	if (value_line.find_first_not_of("-0123456789.", pos + 1) != std::string::npos) {
		std::cerr << "Error: invalid value" << std::endl;
		return (1);
	}
	// check if there are any numbers
	if (value_line.find_first_of("0123456789") == std::string::npos) {
		std::cerr << "Error: invalid value" << std::endl;
		return (1);
	}
	// ckeck for multiple '-'
	pos = value_line.find_first_of("-");
	if (pos != std::string::npos)
	{
		if (value_line.find_first_of("-", pos + 1) != std::string::npos) {
			std::cerr << "Error: invalid value" << std::endl;
			return (1);
		}
	}
	// ckeck for multiple '.'
	pos = value_line.find_first_of(".");
	if (pos != std::string::npos)
	{
		if (value_line.find_first_of(".", pos + 1) != std::string::npos) {
			std::cerr << "Error: invalid value" << std::endl;
			return (1);
		}
	}
	// check if value is in range [ 0 ; 1000 ]
	double	val = atof(value_line.c_str());
	if (val < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (val > 1000)  {
		std::cerr << "Error: too large a number." << std::endl;
		return (1);
	}
	return (0);
}

int		BitcoinExchange::check_date(std::string date_line)
{
	struct tm	tm;
	int			year;
	int			month;
	int			day;

	if (!strptime(date_line.c_str(), "%Y-%m-%d", &tm)) {
		std::cout << "Error : invalid date" << std::endl;
		return (1);
	}
	year = tm.tm_year + 1900;
	month = tm.tm_mon + 1;
	day = tm.tm_mday;
	if (year < 2009 || (year == 2009 && month == 1 && day == 1)) {
		std::cout << "Error : invalid date" << std::endl;
		return (1);
	} 
	if (month < 1 || month > 12 || day < 1 || day > 31) {
		std::cout << "Error : invalid date" << std::endl;
		return (1);
	}
	if (month == 2) {
		if (check_leap(year)) {
			if (day > 29) {
				std::cout << "Error : invalid date" << std::endl;
				return (1);
			}
		} else {
			if (day > 28) {
				std::cout << "Error : invalid date" << std::endl;
				return (1);
			}
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			std::cout << "Error : invalid date" << std::endl;
			return (1);
		}
	}
	// check after date
	size_t	pos;
	pos = date_line.find_first_of("-");
	pos = date_line.find_first_of("-", pos + 1);
	if (date_line.find_first_not_of(" \r\t\b\f", pos + 3) != std::string::npos){
		std::cout << "Error : invalid date" << std::endl;
		return (1);
	}
 	return (0);
}

bool	BitcoinExchange::check_leap(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

double	BitcoinExchange::get_key(std::string date_line)
{
	std::string		tmp;
	double			result = 0;

	tmp = date_line.substr(0, date_line.find_first_of("-"));
	result += atof(tmp.c_str()) * 365;

	tmp = date_line.substr(date_line.find_first_of("-") + 1, date_line.find_last_of("-") - 1 -date_line.find_first_of("-"));
	result += atof(tmp.c_str()) * 30 - 30;
	
	tmp = date_line.substr(date_line.find_last_of("-") + 1, date_line.length() - (date_line.find_last_of("-") + 1));
	result += atof(tmp.c_str());

	return (result);
}

int	BitcoinExchange::read_database(void)
{
	std::ifstream	infile("data.csv");
	std::string		value;

	if (!infile.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	while (!infile.eof())
	{
		double	key = 0;

		std::getline(infile, value, '-');
		key += atof(value.c_str()) * 365;

		std::getline(infile, value, '-');
		key += atof(value.c_str()) * 30 - 30;

		std::getline(infile, value, ',');
		key += atof(value.c_str());

		std::getline(infile, value);

		this->database[key] = atof(value.c_str());
	}
	infile.close();
	return(0);
}
