#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

int main()
{
    std::ifstream inputFile("./data/day-1/input.log");
    if (!inputFile)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<int> leftColumn;
    std::vector<int> rightColumn;

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream lineStream(line);
        int leftValue, rightValue;

        if (lineStream >> leftValue >> rightValue)
        {
            leftColumn.push_back(leftValue);
            rightColumn.push_back(rightValue);
        }
        else
        {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    inputFile.close();

    std::sort(leftColumn.begin(), leftColumn.end());
    std::sort(rightColumn.begin(), rightColumn.end());

    int total_distance = 0;

    for (int i = 0; i < leftColumn.size(); i++)
    {
        int distance = std::abs(leftColumn[i] - rightColumn[i]);
        total_distance += distance;
    }

    std::cout << "Total Distance: " << total_distance << std::endl;

    return 0;
}