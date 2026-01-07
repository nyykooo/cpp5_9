#include "BitcoinExchange.hpp"

// #### LIFE CYCLE ####

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _db(copy._db) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
    {
        this->_db = copy._db;
    }
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::string dataBase)
{
    std::ifstream db;
    db.open(dataBase.c_str());

    if (!db.is_open())
        throw std::runtime_error("Error: fail to open data base file");
    
    std::string line;
    std::getline(db, line); // skips first line headers -> (date,exchange_rate)

    while (std::getline(db, line))
    {
        size_t separator = line.find(',');

        if (separator == std::string::npos)
            continue; // entender o que isso faz (porque pular para a proxima e nao retornar erro??)

        _db[line.substr(0, separator)] = atof(line.substr(separator + 1).c_str());
    }
    db.close();
}

// #### RUN ####

void BitcoinExchange::run(std::string fileName)
{
    std::ifstream file;
    file.open(fileName.c_str());
    if (!file)
        throw std::runtime_error("Error: fail to open input file");
    std::string line;
    std::getline(file, line); // skips input file headers -> (date | value)
    if (line != "date | value")
        throw std::runtime_error("Error: invalid input file."); // para a execucao por isso throw

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        size_t separator = line.find('|');
        if (separator  == std::string::npos)
        {
            printError("Error: bad input => " + line);
            continue;
        }

        std::string date = line.substr(0, separator - 1); // aqui usa-se o -1 para pular o espaco entre a data e o '|'
        if (!parseDate(date))
        {
            printError("Error: bad input => " + date); 
            continue;
        }

        float value = atof(line.substr(separator + 1).c_str());
        if (!parseValue(value))
            continue;

        printSuccess(date, value);
    }
}

void BitcoinExchange::printError(std::string message)
{
    std::cout << message << std::endl;
}

void BitcoinExchange::printSuccess(std::string date, float value)
{
    // lower_bound usa o binary search para localizar o elemento
    // isso garante que se nao houver um match exato o valor sera da data mais proxima (usando a data inferior)
    std::map<std::string, float>::iterator it = _db.lower_bound(date);

    if (it != _db.end() && it->first == date)
        std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
    else
    {
        if (it == _db.begin()) // _db.begin() localiza antes do primeiro elemento de _db
            std::cout << "Error: bad input => " << date << " (too early)" << std::endl;
        else
        {
            it--;
            std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
        }
    }
}

bool BitcoinExchange::parseDate(std::string date)
{
    // first validate date length and format YYYY-MM-DD (length == 10 && date[4]/date[7] == '-')
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009) // ano de surgimento do BTC
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    if (month == 2) // verifica anos bissextos -> multiplos de 4 que nao sao multiplos de 100 MAS inclui os multiplos de 400
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap && day > 29)
            return false;
        if (!isLeap && day > 28)
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) // verifica se o dia esta dentro dos limites dos meses que tem apenas 30 dias
    {
        if (day > 30)
            return false;
    }

    return true;
}

bool BitcoinExchange::parseValue(float value)
{
    if (value < 0)
    {
        printError("Error: not a positive number.");
        return false;
    }
    if (value > 1000)
    {
        printError("Error: too large a number.");
        return false;
    }
    return true;
}
