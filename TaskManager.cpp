#include "TaskManager.hpp"
#include "CsvHelper.hpp"
#include <algorithm>
#include <iostream>

void TaskManager::addTask(const std::string& title, const std::string& description, const std::string& deadline) {
    tasks.emplace_back(title, description, deadline);
}

void TaskManager::editTask(int index, const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline) {
    if (index >= 0 && index < tasks.size()) {
        Task& task = tasks[index];
        task = Task(newTitle, newDescription, newDeadline);
    }
}

void TaskManager::deleteTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

void TaskManager::markTaskAsCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        Task& task = tasks[index];
        task.markAsCompleted();
    }
}

void TaskManager::sortTasksByDeadline() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getDeadline() < b.getDeadline();
    });
}

void TaskManager::sortTasksByStatus() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.isCompleted() && !b.isCompleted();
    });
}

std::vector<Task> TaskManager::searchTasks(const std::string& keyword) {
    std::vector<Task> results;
    for (const auto& task : tasks) {
        if (task.getTitle().find(keyword) != std::string::npos || task.getDescription().find(keyword) != std::string::npos) {
            results.push_back(task);
        }
    }
    return results;
}

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

void TaskManager::saveTasksToFile(const std::string& filename) {
    CsvHelper::saveTasksToFile(filename, tasks);
}

void TaskManager::loadTasksFromFile(const std::string& filename) {
    tasks = CsvHelper::loadTasksFromFile(filename);
}
