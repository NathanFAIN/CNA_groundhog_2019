/*
** EPITECH PROJECT, 2020
** CNA_groundhog_2019
** File description:
** groundhog
*/

#include "groundhog.hpp"

groundhog::groundhog(void)
{
    this->_period = 1;
    this->_input = 0.1f;
    this->_average = 0.f;
    this->_evolution = 0.f;
    this->_derivate = 0.f;
    this->_nbSwitch = 0;
    this->_incrase = true;
    std::cout << std::setprecision(3);
}

groundhog::~groundhog(void)
{
}

std::vector<long double> groundhog::getArray(void) const
{
    return this->_array;
}

void groundhog::setPeriod(const size_t &period)
{
    this->_period = period;
}

size_t groundhog::getPeriod(void) const
{
    return this->_period;
}

void groundhog::setInput(void)
{
    std::string input;

    // if (std::cin.eof())
    //     exit(0);
    std::cin >> input;
    if (input == "STOP") {
        exit(0);
    } else if (!atof(input.c_str())) {
        std::cerr << "Invalid value" << std::endl;
        exit(84);
    }
    this->_input = atof(input.c_str());
    this->_array.push_back(this->_input);
}

long double groundhog::getInput(void) const
{
    return this->_input;
}

void groundhog::calculateAverage(void)
{
    this->_average = 0.f;
    if (this->_array.size() > this->_period) {
        for (size_t index = this->_array.size() - this->_period; index != this->_array.size(); index++) {
            if (this->_array[index] - this->_array[index - 1] > 0) {
                this->_average += (this->_array[index] - this->_array[index - 1]) / this->_period;
            }
        }
    }
}

long double groundhog::getAverage(void) const
{
    return this->_average;
}

void groundhog::calculateEvolution(void)
{
    this->_evolution = 0.f;
    if (this->_array.size() > this->_period) {
        this->_evolution = std::round((this->_array[this->_array.size() - 1] * 100 / this->_array[this->_array.size() - 1 - this->_period]) - 100);
    }
}

long double groundhog::getEvolution(void) const
{
    return this->_evolution;
}

void groundhog::calculateDerivate(void)
{
    long double average = 0.f;

    this->_derivate = 0.f;
    if (this->_array.size() >= this->_period) {
        for (size_t index = 0; index != this->_period; index++)
            average += this->_array[this->_array.size() - index - 1] / this->_period;
        for (size_t index = 0; index != this->_period; index++)
            this->_derivate += pow((this->_array[this->_array.size() - index - 1] - average), 2) / this->_period;
        this->_derivate = sqrt(this->_derivate);
    }
}

long double groundhog::getDerivate(void) const
{
    return this->_derivate;
}

void groundhog::printCalcule(void) const
{
    if (this->_array.size() > this->_period) {
        std::cout << "g=" << this->_average;
        std::cout << "\tr=" << this->_evolution << "%";
        std::cout << "\t";
    } else {
        std::cout << "g=nan\tr=nan%\t";
    }
    if (this->_array.size() >= this->_period) {
        std::cout << "s=" << this->_derivate;
    } else {
        std::cout << "s=nan";
    }
}

void groundhog::findSwitch(void)
{
        if (this->_array.size() > this->_period && this->_array.size() > this->_period + 1 && !this->_incrase && (this->_array[this->_array.size() - 1] * 100 / this->_array[this->_array.size() - 1 - this->_period]) - 100 > 0) {
            this->_nbSwitch++;
            std::cout << "\ta switch occurs";
        }
        else if (this->_array.size() > this->_period && this->_array.size() > this->_period + 1 && this->_incrase && (this->_array[this->_array.size() - 1] * 100 / this->_array[this->_array.size() - 1 - this->_period]) - 100 < 0) {
            this->_nbSwitch++;
            std::cout << "\ta switch occurs";
        }
        if (this->_array.size() > this->_period && (this->_array[this->_array.size() - 1] * 100 / this->_array[this->_array.size() - 1 - this->_period]) - 100 > 0)
            this->_incrase = true;
        else if (this->_array.size() > this->_period && (this->_array[this->_array.size() - 1] * 100 / this->_array[this->_array.size() - 1 - this->_period]) - 100 < 0)
            this->_incrase = false;
}

void groundhog::printHelp(void) const
{
    std::cout << "SYNOPSIS" << std::endl;
    std::cout << "\t./groundhog period" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tperiod\t\tthe number of days defining a period" << std::endl;
}