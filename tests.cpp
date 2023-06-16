/**
 * @file tests.cpp
 *
 * @brief Файл, содержащий тесты для класса TaskManager.
 */

#include "TaskManager.hpp"
#include <cassert>

/**
 * @brief Тест на добавление задачи.
 */
void testAddTask() {
    TaskManager taskManager;

    // Добавляем задачу
    taskManager.addTask("Задача 1", "Описание задачи 1", "2023-06-30");

    // Получаем все задачи
    std::vector<Task>& tasks = taskManager.getTasks();

    // Проверяем, что задача была успешно добавлена
    assert(tasks.size() == 1);
    assert(tasks[0].getTitle() == "Задача 1");
    assert(tasks[0].getDescription() == "Описание задачи 1");
    assert(tasks[0].getDeadline() == "2023-06-30");
}

/**
 * @brief Тест на редактирование задачи.
 */
void testEditTask() {
    TaskManager taskManager;

    // Добавляем задачу
    taskManager.addTask("Задача 1", "Описание задачи 1", "2023-06-30");

    // Редактируем задачу
    taskManager.editTask(0, "Новая задача", "Новое описание", "2023-07-01");

    // Получаем все задачи
    std::vector<Task>& tasks = taskManager.getTasks();

    // Проверяем, что задача была успешно отредактирована
    assert(tasks[0].getTitle() == "Новая задача");
    assert(tasks[0].getDescription() == "Новое описание");
    assert(tasks[0].getDeadline() == "2023-07-01");
}

/**
 * @brief Тест на удаление задачи.
 */
void testDeleteTask() {
    TaskManager taskManager;

    // Добавляем задачу
    taskManager.addTask("Задача 1", "Описание задачи 1", "2023-06-30");

    // Удаляем задачу
    taskManager.deleteTask(0);

    // Получаем все задачи
    std::vector<Task>& tasks = taskManager.getTasks();

    // Проверяем, что задача была успешно удалена
    assert(tasks.empty());
}

/**
 * @brief Тест на отметку задачи как выполненной.
 */
void testMarkTaskAsCompleted() {
    TaskManager taskManager;

    // Добавляем задачу
    taskManager.addTask("Задача 1", "Описание задачи 1", "2023-06-30");

    // Отмечаем задачу как выполненную
    taskManager.markTaskAsCompleted(0);

    // Получаем все задачи
    std::vector<Task>& tasks = taskManager.getTasks();

    // Проверяем, что задача была отмечена как выполненная
    assert(tasks[0].isCompleted());
}

/**
 * @brief Тест на сортировку задач по дедлайну.
 */
void testSortTasksByDeadline() {
    TaskManager taskManager;

    // Добавляем несколько задач
    taskManager.addTask("Задача 1", "Описание задачи 1", "2023-06-30");
    taskManager.addTask("Задача 2", "Описание задачи 2", "2023-06-15");
    taskManager.addTask("Задача 3", "Описание задачи 3", "2023-07-10");

    // Сортируем задачи по дедлайну
    taskManager.sortTasksByDeadline();

    // Получаем все задачи
    std::vector<Task>& tasks = taskManager.getTasks();

    // Проверяем, что задачи отсортированы в правильном порядке
    assert(tasks[0].getTitle() == "Задача 2");
    assert(tasks[1].getTitle() == "Задача 1");
    assert(tasks[2].getTitle() == "Задача 3");
}

//int main() {
  //  testAddTask();
    //testEditTask();
    //testDeleteTask();
    //testMarkTaskAsCompleted();
    //testSortTasksByDeadline();

    //return 0;
//}
