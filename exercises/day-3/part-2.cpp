#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

const std::string parseMemory()
{
    std::ifstream inputFile("./data/day-3/input.log");
    if (!inputFile)
    {
        std::cerr << "Error opening file" << std::endl;
        return "";
    }

    std::ostringstream buffer;
    buffer << inputFile.rdbuf();

    return buffer.str();
}

const std::vector<std::string> extractMultiplications(const std::string &memory, const std::string &pattern)
{
    std::vector<std::string> multiplications;
    std::regex re(pattern);
    std::sregex_iterator it(memory.begin(), memory.end(), re);
    std::sregex_iterator end;

    while (it != end)
    {
        std::smatch match = *it;
        multiplications.push_back(match.str(0));
        ++it;
    }

    return multiplications;
}

int multiply(const std::vector<std::string> &multiplications, const std::string &pattern)
{
    int total = 0;
    bool is_paused = false;
    std::regex extractPattern(pattern);
    for (const std::string &mulStr : multiplications)
    {
        if (mulStr == "don't()")
        {
            is_paused = true;
        }

        if (mulStr == "do()")
        {
            is_paused = false;
        }

        if (is_paused)
        {
            continue;
        }

        std::smatch match;
        if (std::regex_search(mulStr, match, extractPattern))
        {
            int x = std::stoi(match[1]);
            int y = std::stoi(match[2]);
            int product = x * y;
            total += product;
        }
    }

    return total;
}

int main()
{
    std::string memory = parseMemory();
    std::string pattern = R"(mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\))";

    std::vector<std::string> multiplications = extractMultiplications(memory, pattern);
    std::string extractionPattern = R"(\((\d+),(\d+)\))";

    int total = multiply(multiplications, extractionPattern);

    std::cout << "Total: " << total << std::endl;

    return 0;
}