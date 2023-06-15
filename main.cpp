#include "TaskManager.hpp"
#include <iostream>
#include <limits>

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Добавить задачу\n";
        std::cout << "2. Редактировать задачу\n";
        std::cout << "3. Удалить задачу\n";
        std::cout << "4. Отметить выполнение задачи\n";
        std::cout << "5. Сортировать задачи по дедлайну\n";
        std::cout << "6. Сортировать задачи по статусу\n";
        std::cout << "7. Поиск задачи\n";
        std::cout << "8. Показать список задач\n";
        std::cout << "9. Сохранить список задач в файл\n";
        std::cout << "10. Загрузить список задач из файла\n";
        std::cout << "0. Выйти из программы\n";
        std::cout << "Введите номер действия: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string title, description, deadline;
                std::cout << "Введите название задачи: ";
                std::getline(std::cin, title);
                std::cout << "Введите описание задачи: ";
                std::getline(std::cin, description);
                std::cout << "Введите дедлайн задачи: ";
                std::getline(std::cin, deadline);

                taskManager.addTask(title, description, deadline);
                std::cout << "Задача успешно добавлена.\n";
                break;
            }
            case 2: {
                int index;
                std::cout << "Введите индекс задачи для редактирования: ";
                std::cin >> index;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::string newTitle, newDescription, newDeadline;
                std::cout << "Введите новое название задачи: ";
                std::getline(std::cin, newTitle);
                std::cout << "Введите новое описание задачи: ";
                std::getline(std::cin, newDescription);
                std::cout << "Введите новый дедлайн задачи: ";
                std::getline(std::cin, newDeadline);

                taskManager.editTask(index - 1, newTitle, newDescription, newDeadline);
                std::cout << "Задача успешно отредактирована.\n";
                break;
            }
            case 3: {
                int index;
                std::cout << "Введите индекс задачи для удаления: ";
                std::cin >> index;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                taskManager.deleteTask(index - 1);
                std::cout << "Задача успешно удалена.\n";
                break;
            }
            case 4: {
                int index;
                std::cout << "Введите индекс задачи для отметки выполнения: ";
                std::cin >> index;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                taskManager.markTaskAsCompleted(index - 1);
                std::cout << "Задача успешно отмечена как выполненная.\n";
                break;
            }
            case 5:
                taskManager.sortTasksByDeadline();
                std::cout << "Список задач отсортирован по дедлайну.\n";
                break;
            case 6:
                taskManager.sortTasksByStatus();
                std::cout << "Список задач отсортирован по статусу.\n";
                break;
            case 7: {
                std::string keyword;
                std::cout << "Введите ключевое слово для поиска: ";
                std::getline(std::cin, keyword);

                std::vector<Task> searchResults = taskManager.searchTasks(keyword);
                if (searchResults.empty()) {
                    std::cout << "По заданному ключевому слову не найдено задач.\n";
                } else {
                    std::cout << "Результаты поиска:\n";
                    for (const Task& task : searchResults) {
                        std::cout << "Название: " << task.getTitle() << "\n";
                        std::cout << "Описание: " << task.getDescription() << "\n";
                        std::cout << "Дедлайн: " << task.getDeadline() << "\n";
                        std::cout << "Статус: " << (task.isCompleted() ? "Выполнена" : "Открыта") << "\n";
                        std::cout << "-------------------------------------------\n";
                    }
                }
                break;
            }
            case 8:
                taskManager.displayTasks();
                break;
            case 9: {
                std::string filename;
                std::cout << "Введите имя файла для сохранения: ";
                std::getline(std::cin, filename);

                taskManager.saveTasksToFile(filename);
                std::cout << "Список задач успешно сохранен в файле.\n";
                break;
            }
            case 10: {
                std::string filename;
                std::cout << "Введите имя файла для загрузки: ";
                std::getline(std::cin, filename);

                taskManager.loadTasksFromFile(filename);
                std::cout << "Список задач успешно загружен из файла.\n";
                break;
            }
            case 0:
                std::cout << "До свидания!\n";
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }

        std::cout << std::endl;
    }
}

