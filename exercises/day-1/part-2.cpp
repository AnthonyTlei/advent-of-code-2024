#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

int main()
{
    std::ifstream inputFile("./data/day-1/input.log");
    if (!inputFile)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::unordered_map<int, int> leftCountMap;
    std::unordered_map<int, int> rightCountMap;

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream lineStream(line);
        int leftValue, rightValue;

        if (lineStream >> leftValue >> rightValue)
        {
            leftCountMap[leftValue]++;
            rightCountMap[rightValue]++;
        }
        else
        {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    inputFile.close();

    int similarityScore = 0;
    for (const auto &[left, leftCount] : leftCountMap)
    {
        similarityScore += left * rightCountMap[left] * leftCount;
    }

    std::cout << "Similarity Score: " << similarityScore << std::endl;

    return 0;
}