/**

@file Task.cpp
@brief Реализация класса Task.
*/
#include "Task.hpp"

/**

@brief Конструктор с параметрами.
@param title Название задачи.
@param description Описание задачи.
@param deadline Дедлайн задачи.
*/
Task::Task(const std::string& title, const std::string& description, const std::string& deadline)
        : title(title), description(description), deadline(deadline), completed(false) {}

/**

@brief Возвращает название задачи.
@return Название задачи.
*/
std::string Task::getTitle() const {
    return title;
}

/**

@brief Возвращает описание задачи.
@return Описание задачи.
*/
std::string Task::getDescription() const {
    return description;
}

/**

@brief Возвращает дедлайн задачи.
@return Дедлайн задачи.
*/
std::string Task::getDeadline() const {
    return deadline;
}

/**

@brief Устанавливает статус выполнения задачи.
@param completed Флаг выполнения задачи.
*/
bool Task::isCompleted() const {
    return completed;
}

/**

@brief Проверяет, выполнена ли задача.
@return true, если задача выполнена, false в противном случае.
*/
void Task::markAsCompleted() {
    completed = true;
}

