#ifndef TIMEUTILS_HPP
#define TIMEUTILS_HPP

#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include <sstream>

/**
 * @brief Sobrecarga do operador << para ler o tempo e otimizar o código
 *
 * @param os fluxo de saída
 * @param time tempo da mensagem
 * @return std::ostream& fluxo de saída
 */
std::ostream &operator<<(std::ostream &os, const std::chrono::system_clock::time_point &time)
{

    std::time_t timestamp = std::chrono::system_clock::to_time_t(time);
    std::string timeStr = std::ctime(&timestamp);

    if (!timeStr.empty() && timeStr[timeStr.length() - 1] == '\n')
    {
        timeStr.erase(timeStr.length() - 1);
    }

    os << timeStr;
    return os;
}
std::istream &operator>>(std::istream &is, std::chrono::system_clock::time_point &time)
{
    std::string timeStr;
    std::getline(is, timeStr);

    std::tm tm = {};
    std::istringstream iss(timeStr);
    iss >> std::get_time(&tm, "%d/%m/%Y %H:%M:%S");

    time = std::chrono::system_clock::from_time_t(std::mktime(&tm));

    return is;
}

#endif