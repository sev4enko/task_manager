#include "CsvHelper.hpp"
#include <fstream>

void CsvHelper::saveTasksToFile(const std::string& filename, const std::vector<Task>& tasks) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Task& task : tasks) {
            file << task.getTitle() << "," << task.getDescription() << "," << task.getDeadline() << "," << task.isCompleted() << "\n";
        }
        file.close();
    }
}

std::vector<Task> CsvHelper::loadTasksFromFile(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string title, description, deadline;
            bool completed;
            size_t comma1 = line.find(',');
            size_t comma2 = line.find(',', comma1 + 1);
            size_t comma3 = line.find(',', comma2 + 1);

            title = line.substr(0, comma1);
            description = line.substr(comma1 + 1, comma2 - comma1 - 1);
            deadline = line.substr(comma2 + 1, comma3 - comma2 - 1);
            completed = (line.substr(comma3 + 1) == "1");

            tasks.emplace_back(title, description, deadline);
            if (completed) {
                tasks.back().markAsCompleted();
            }
        }
        file.close();
    }
    return tasks;
}

