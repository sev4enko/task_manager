#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include "Task.hpp"
#include <vector>
#include <string>

/**

@class TaskManager
@brief Класс, управляющий задачами.
Класс TaskManager предоставляет функциональность для добавления, редактирования,
удаления, отметки выполнения, сортировки, поиска, сохранения и загрузки задач.
*/
class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& title, const std::string& description, const std::string& deadline);
    void editTask(int index, const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline);
    void deleteTask(int index);
    void markTaskAsCompleted(int index);
    void sortTasksByDeadline();
    void sortTasksByStatus();
    std::vector<Task> searchTasks(const std::string& keyword);
    void displayTasks();
    void saveTasksToFile(const std::string& filename);
    void loadTasksFromFile(const std::string& filename);
};

#endif  // TASKMANAGER_HPP
