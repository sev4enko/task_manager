#ifndef CSVHELPER_HPP
#define CSVHELPER_HPP

#include "Task.hpp"
#include <vector>
#include <string>

/**

@class CsvHelper
@brief Класс, предоставляющий функциональность для чтения и записи CSV файлов.
Класс CsvHelper содержит методы для чтения данных из CSV файла и записи данных в CSV файл.
*/
class CsvHelper {
public:
    static void saveTasksToFile(const std::string& filename, const std::vector<Task>& tasks);
    static std::vector<Task> loadTasksFromFile(const std::string& filename);
};

#endif  // CSVHELPER_HPP

