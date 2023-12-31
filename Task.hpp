#ifndef TASK_HPP
#define TASK_HPP

#include <string>

/**

@class Task
@brief Класс, представляющий задачу.
Класс Task содержит информацию о задаче, включая название, описание, дедлайн и статус выполнения.
*/
class Task {
private:
    std::string title;
    std::string description;
    std::string deadline;
    bool completed;

public:
    Task(const std::string& title, const std::string& description, const std::string& deadline);

    std::string getTitle() const;
    std::string getDescription() const;
    std::string getDeadline() const;
    bool isCompleted() const;
    void markAsCompleted();
};

#endif  // TASK_HPP
