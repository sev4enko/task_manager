#ifndef CSVHELPER_HPP
#define CSVHELPER_HPP

#include "Task.hpp"
#include <vector>
#include <string>

class CsvHelper {
public:
    static void saveTasksToFile(const std::string& filename, const std::vector<Task>& tasks);
    static std::vector<Task> loadTasksFromFile(const std::string& filename);
};

#endif  // CSVHELPER_HPP

