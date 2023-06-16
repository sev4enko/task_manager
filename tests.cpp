#include "TaskManager.hpp"
#include <iostream>

/**

@brief Тест функции добавления задачи.
*/
void testAddTask() {
    TaskManager taskManager;

    // Добавление задачи
    taskManager.addTask("Задача 1", "Описание задачи 1", "2023-06-30");

    // Проверка, что задача была добавлена
    std::vector<Task> tasks = taskManager.getTasks();
    if (tasks.size() == 1 && tasks[0].getTitle() == "Задача 1" && tasks[0].getDescription() == "Описание задачи 1" && tasks[0].getDeadline() == "2023-06-30") {
        std::cout << "Тест добавления задачи пройден.\n";
    } else {
        std::cout << "Тест добавления задачи не пройден.\n";
    }
}

/**

@brief Тест функции удаления задачи.
*/
void testDeleteTask() {
    TaskManager taskManager;

    // Добавление задачи
    taskManager.addTask("Задача 1", "Описание задачи 1", "2023-06-30");

    // Удаление задачи
    taskManager.deleteTask(0);

    // Проверка, что задача была удалена
    std::vector<Task> tasks = taskManager.getTasks();
    if (tasks.empty()) {
        std::cout << "Тест удаления задачи пройден.\n";
    } else {
        std::cout << "Тест удаления задачи не пройден.\n";
    }
}

/**

@brief Тест функции отметки выполнения задачи.
*/
void testMarkTaskAsCompleted() {
    TaskManager taskManager;

    // Добавление задачи
    taskManager.addTask("Задача 1", "Описание задачи 1", "2023-06-30");

    // Отметка задачи как выполненной
    taskManager.markTaskAsCompleted(0);

    // Проверка, что задача была отмечена как выполненная
    std::vector<Task> tasks = taskManager.getTasks();
    if (!tasks.empty() && tasks[0].isCompleted()) {
        std::cout << "Тест отметки выполнения задачи пройден.\n";
    } else {
        std::cout << "Тест отметки выполнения задачи не пройден.\n";
    }
}

/**

@brief Главная функция тестов.
@return Код возврата.
*/
int main() {
    testAddTask();
    testDeleteTask();
    testMarkTaskAsCompleted();

    return 0;
}

