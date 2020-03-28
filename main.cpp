/*
** EPITECH PROJECT, 2020
** CNA_groundhog_2019
** File description:
** main
*/

#include "groundhog.hpp"

int main(int argc, char **argv)
{
    groundhog myGroundhog;

    if (argc != 2) {
        std::cerr << "Invalid number of argument" << std::endl;
        return 84;
    } else if (std::string(argv[1]) == "-h") {
        myGroundhog.printHelp();
        return 0;
    } else if (atoi(argv[1]) <= 0) {
        std::cerr << "Invalid argument" << std::endl;
        return 84;
    }
    myGroundhog.setPeriod(atoi(argv[1]));
    while (1) {
        myGroundhog.setInput();
        myGroundhog.calculateAverage();
        myGroundhog.calculateDerivate();
        myGroundhog.calculateEvolution();
        myGroundhog.printCalcule();
        myGroundhog.findSwitch();
        std::cout << std::endl;
    }
    return 0;
}