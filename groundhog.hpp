/*
** EPITECH PROJECT, 2020
** CNA_groundhog_2019
** File description:
** groundhog
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numeric>

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

class groundhog {
    public:
        groundhog();
        ~groundhog();
        std::vector<long double> getArray(void) const;
        void setPeriod(const size_t &period);
        size_t getPeriod(void) const;
        void setInput(void);
        long double getInput(void) const;
        void calculateAverage(void);
        long double getAverage(void) const;
        void calculateEvolution(void);
        long double getEvolution(void) const;
        void calculateDerivate(void);
        long double getDerivate(void) const;
        void printCalcule(void) const;
        void findSwitch(void);
        size_t getNbSwitch(void) const;
        void setNbSwitch(size_t &nbSwitch);
        void printHelp(void) const;
    private:
        std::vector<long double> _array;
        size_t _period;
        long double _input;
        long double _average;
        long double _evolution;
        long double _derivate;
        bool _incrase;
        size_t _nbSwitch;
};

#endif /* !GROUNDHOG_HPP_ */
