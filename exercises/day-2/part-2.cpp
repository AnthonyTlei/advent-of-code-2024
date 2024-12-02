#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

bool is_report_safe(const std::vector<int> &report)
{
    if (report.size() < 2)
    {
        return true;
    }

    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 1; i < report.size(); ++i)
    {
        int diff = report[i] - report[i - 1];

        if (std::abs(diff) < 1 || std::abs(diff) > 3)
        {
            return false;
        }

        if (diff > 0)
        {
            decreasing = false;
        }
        else if (diff < 0)
        {
            increasing = false;
        }

        if (!increasing && !decreasing)
        {
            return false;
        }
    }

    return increasing || decreasing;
}

bool is_report_safe_with_dampener(const std::vector<int> &report)
{
    if (is_report_safe(report))
    {
        return true;
    }

    for (size_t i = 0; i < report.size(); ++i)
    {
        std::vector<int> modified_report = report;
        modified_report.erase(modified_report.begin() + i);

        if (is_report_safe(modified_report))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::ifstream inputFile("./data/day-2/input.log");
    if (!inputFile)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    int total_safe_reports = 0;

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream lineStream(line);
        std::vector<int> report;

        int level;
        while (lineStream >> level)
        {
            report.emplace_back(level);
        }

        if (is_report_safe_with_dampener(report))
        {
            ++total_safe_reports;
        }
    }

    inputFile.close();

    std::cout << "Total Safe Reports: " << total_safe_reports << std::endl;

    return 0;
}