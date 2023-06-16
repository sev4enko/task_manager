#include "TaskManager.hpp"
#include "CsvHelper.hpp"
#include <algorithm>
#include <iostream>

/**

@brief Добавляет новую задачу в список задач.
@param task Задача для добавления.
*/
void TaskManager::addTask(const std::string& title, const std::string& description, const std::string& deadline) {
    tasks.emplace_back(title, description, deadline);
}

/**

@brief Редактирует задачу по ее индексу.
@param index Индекс задачи для редактирования.
@param title Новое название задачи.
@param description Новое описание задачи.
@param deadline Новый дедлайн задачи.
*/
void TaskManager::editTask(int index, const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline) {
    if (index >= 0 && index < tasks.size()) {
        Task& task = tasks[index];
        task = Task(newTitle, newDescription, newDeadline);
    }
}

/**

@brief Удаляет задачу по ее индексу.
@param index Индекс задачи для удаления.
*/
void TaskManager::deleteTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

/**

@brief Отмечает задачу как выполненную по ее индексу.
@param index Индекс задачи для отметки выполнения.
*/
void TaskManager::markTaskAsCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        Task& task = tasks[index];
        task.markAsCompleted();
    }
}

/**

@brief Сортирует список задач по дедлайну.
*/
void TaskManager::sortTasksByDeadline() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getDeadline() < b.getDeadline();
    });
}

/**

@brief Сортирует список задач по статусу выполнения.
*/
void TaskManager::sortTasksByStatus() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.isCompleted() && !b.isCompleted();
    });
}

/**

@brief Ищет задачи по названию или описанию.
@param keyword Ключевое слово для поиска.
@return Вектор найденных задач.
*/
std::vector<Task> TaskManager::searchTasks(const std::string& keyword) {
    std::vector<Task> results;
    for (const auto& task : tasks) {
        if (task.getTitle().find(keyword) != std::string::npos || task.getDescription().find(keyword) != std::string::npos) {
            results.push_back(task);
        }
    }
    return results;
}

/**

@brief Отображает информацию о задаче.
@param task Задача для отображения.
*/
void TaskManager::displayTasks() {
    if (tasks.empty()) {
        std::cout << "Список задач пуст.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            const Task& task = tasks[i];
            std::cout << "Задача " << i + 1 << ":\n";
            std::cout << "Название: " << task.getTitle() << "\n";
            std::cout << "Описание: " << task.getDescription() << "\n";
            std::cout << "Дедлайн: " << task.getDeadline() << "\n";
            std::cout << "Статус: " << (task.isCompleted() ? "Выполнена" : "Открыта") << "\n";
            std::cout << "-------------------------------------------\n";
        }
    }
}

/**

@brief Сохраняет список задач в файл.
@param filename Имя файла для сохранения.
@return true, если сохранение прошло успешно, false в противном случае.
*/
void TaskManager::saveTasksToFile(const std::string& filename) {
    CsvHelper::saveTasksToFile(filename, tasks);
}

/**

@brief Загружает список задач из файла.
@param filename Имя файла для загрузки.
@return true, если загрузка прошла успешно, false в противном случае.
*/
void TaskManager::loadTasksFromFile(const std::string& filename) {
    tasks = CsvHelper::loadTasksFromFile(filename);
}
