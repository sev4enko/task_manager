#include "Task.hpp"

Task::Task(const std::string& title, const std::string& description, const std::string& deadline)
        : title(title), description(description), deadline(deadline), completed(false) {}

std::string Task::getTitle() const {
    return title;
}

std::string Task::getDescription() const {
    return description;
}

std::string Task::getDeadline() const {
    return deadline;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::markAsCompleted() {
    completed = true;
}

