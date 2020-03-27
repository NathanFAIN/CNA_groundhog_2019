/*
** EPITECH PROJECT, 2020
** CNA_groundhog_2019
** File description:
** main
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <numeric>

void debug()
{
    std::cout << "SYNOPSIS" << std::endl;
    std::cout << "\t./groundhog period" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tperiod\t\tthe number of days defining a period" << std::endl;
}

long double derivate(std::vector<long double> memory, size_t period)
{
    long double ans = 0.f;
    long double average = 0.f;

    if (memory.size() >= period) {
        for (size_t index = 0; index != period; index++)
            average += memory[memory.size() - index - 1] / period;
        for (size_t index = 0; index != period; index++)
            ans += pow((memory[memory.size() - index - 1] - average), 2) / period;
    }
    return sqrt(ans);
}

long double average(std::vector<long double> memory, size_t period)
{
    long double ans = 0.f;

    if (memory.size() > period) {
        for (size_t counter = memory.size() - period; counter != memory.size(); counter++) {
            if (memory[counter] - memory[counter - 1] > 0) {
                ans += (memory[counter] - memory[counter - 1]) / period;
            }
        }
    }
    return ans;
}

void loop(int period)
{
    std::vector<long double> memory;
    std::string str = "0.1";
    bool incrase = true;
    int nbSwitch = 0;

    std::cout << std::setprecision(3);
    while (1) {
        std::cin >> str;
        if (str == "STOP")
            exit(0);
        else if (!atof(str.c_str())) {
            std::cerr << "Invalid value" << std::endl;
            exit(84);
        }
        memory.push_back(atof(str.c_str()));
        if (memory.size() > period) {
            std::cout << "g=" << average(memory, period);
            std::cout << "\tr=" << std::round((memory[memory.size() - 1] * 100 / memory[memory.size() - 1 - period]) - 100) << "%";
            std::cout << "\t";
        }
        else
            std::cout << "g=nan\tr=nan%\t";
        if (memory.size() >= period)
            std::cout << "s=" << derivate(memory, period);
        else
            std::cout << "s=nan";
        if (memory.size() > period && memory.size() > period + 1 && !incrase && (memory[memory.size() - 1] * 100 / memory[memory.size() - 1 - period]) - 100 > 0) {
            nbSwitch++;
            std::cout << "\ta switch occurs";
        }
        else if (memory.size() > period && memory.size() > period + 1 && incrase && (memory[memory.size() - 1] * 100 / memory[memory.size() - 1 - period]) - 100 < 0) {
            nbSwitch++;
            std::cout << "\ta switch occurs";
        }
        if (memory.size() > period && (memory[memory.size() - 1] * 100 / memory[memory.size() - 1 - period]) - 100 > 0)
            incrase = true;
        else if (memory.size() > period && (memory[memory.size() - 1] * 100 / memory[memory.size() - 1 - period]) - 100 < 0)
            incrase = false;
        std::cout << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Invalid number of argument" << std::endl;
        return 84;
    }
    else if (std::string(argv[1]) == "-h")
        debug();
    else if (atoi(argv[1]) <= 0) {
        std::cerr << "Invalid argument" << std::endl;
        return 84;
    }
    else
        loop(atoi(argv[1]));
    return 0;
}