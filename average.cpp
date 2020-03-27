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

// float average(std::vector<float> memory)
// {
//     float ans = 0.f;

//     for (size_t index = 0; index != memory.size() - 1; index++) {
//         ans += memory[index + 1] - memory[index];
//     }
//     // float ans = std::accumulate(memory.begin(), memory.end(), 0.0 / memory.size());
//     return ans;
// }

// long double average(std::vector<long double> memory, size_t period)
// {
//     long double ans = 0.f;

//     if (memory.size() > period) {
//         for (size_t counter = memory.size() - period; counter != memory.size(); counter++) {
//             if (memory[counter] - memory[counter - 1] > 0) {
//                 ans += (memory[counter] - memory[counter - 1]) / period;
//             }
//         }
//     }
//     return ans;
// }

long double derivate(std::vector<long double> memory, size_t period)
{
    long double derivate;

    for (size_t index = 1; index < memory.size() - 1; index++){
        g[index]=(y[index + 1] - y[index-1]) / 2;
}

}


int main(void)
{
    std::vector<long double> memory;
    std::string str;

    while (1) {
        std::cin >> str;
        if (str == "exit")
            return (0);
        memory.push_back(atof(str.c_str()));
        std::cout << derivate(memory, 7) << std::endl;
    }
    return (0);
}