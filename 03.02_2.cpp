#include <iostream>
using namespace std;

constexpr int MAX_TASKS = 100; // Максимальное количество задач

struct Task {
    std::string name;
    std::string description;
    // Дополнительные поля задачи...
};

Task tasks[MAX_TASKS]; // Массив для хранения задач
int taskCount = 0; // Счетчик задач

enum Action {
    ADD_TASK = 1,
    DELETE_TASK,
    UPDATE_TASK,
    DISPLAY_TASKS,
    EXIT
};

// Функция для добавления новой задачи
void addTask(Task* tasks, int& numTasks) {
    if (numTasks >= 10) {
        cout << "Невозможно добавить новую задачу. Максимальное количество задач достигнуто." << endl;
        return;
    }

    cout << "Введите название задачи: ";
    cin >> tasks[numTasks].name;

    cout << "Введите описание задачи: ";
    cin >> tasks[numTasks].description;

    numTasks++;
}

// Функция для удаления существующей задачи
void deleteTask(Task* tasks, int& numTasks) {
    int taskIndex;

    if (numTasks == 0) {
        cout << "Нет доступных задач для удаления." << endl;
        return;
    }

    cout << "Введите индекс задачи, которую нужно удалить (от 0 до " << numTasks - 1 << "): ";
    cin >> taskIndex;

    if (taskIndex < 0 || taskIndex >= numTasks) {
        cout << "Введен неверный индекс задачи." << endl;
        return;
    }

    for (int i = taskIndex; i < numTasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    numTasks--;
}

// Функция для обновления информации о задаче
void updateTask(Task* tasks, int& numTasks) {
    int taskIndex;

    if (numTasks == 0) {
        cout << "Нет доступных задач для обновления." << endl;
        return;
    }

    cout << "Введите индекс задачи, которую нужно обновить (от 0 до " << numTasks - 1 << "): ";
    cin >> taskIndex;

    if (taskIndex < 0 || taskIndex >= numTasks) {
        cout << "Введен неверный индекс задачи." << endl;
        return;
    }

    cout << "Введите новое название задачи: ";
    cin >> tasks[taskIndex].name;

    cout << "Введите новое описание задачи: ";
    cin >> tasks[taskIndex].description;
}

// Функция для отображения информации обо всех задачах
void displayTasks(Task* tasks, int& numTasks) {
    if (numTasks == 0) {
        cout << "Нет доступных задач для отображения." << endl;
        return;
    }

    cout << "Список задач:" << endl;
    for (int i = 0; i < numTasks; i++) {
        cout << "Задача " << i + 1 << ":" << endl;
        cout << "Название: " << tasks[i].name << endl;
        cout << "Описание: " << tasks[i].description << endl;
    }
}

//
//void addTask() {
//    if (taskCount == MAX_TASKS) {
//        std::cout << "Достигнуто максимальное количество задач." << std::endl;
//    }
//
//    Task newTask;
//    std::cout << "Введите название задачи: ";
//    std::cin >> newTask.name;
//    std::cout << "Введите описание задачи: ";
//    std::cin >> newTask.description;
//    tasks[taskCount++] = newTask;
//    std::cout << "Задача успешно добавлена." << std::endl;
//}
//
//void deleteTask() {
//    int index;
//    std::cout << "Введите индекс задачи для удаления: ";
//    std::cin >> index;
//    if (index >= 0 && index < taskCount) {
//        for (int i = index; i < taskCount - 1; i++) {
//            tasks[i] = tasks[i + 1];
//        }
//        taskCount--;
//        std::cout << "Задача успешно удалена." << std::endl;
//    }
//    else {
//        std::cout << "Недопустимый индекс задачи." << std::endl;
//    }
//}
//void updateTask() {
//    int index;
//    std::cout << "Введите индекс задачи для обновления: ";
//    std::cin >> index;
//    if (index >= 0 && index < taskCount) {
//        Task& task = tasks[index];
//        std::cout << "Введите новое название задачи: ";
//        std::cin >> task.name;
//        std::cout << "Введите новое описание задачи: ";
//        std::cin >> task.description;
//        // Обновление дополнительных полей задачи...
//        std::cout << "Задача успешно обновлена." << std::endl;
//    }
//    else {
//        std::cout << "Недопустимый индекс задачи." << std::endl;
//    }
//}
//
//void displayTasks() {
//    if (taskCount == 0) {
//        std::cout << "Нет актуальных задач." << std::endl;
//    }
//    else {
//        std::cout << "Список задач:" << std::endl;
//        for (int i = 0; i < taskCount; i++) {
//            Task& task = tasks[i];
//            std::cout << "Название: " << task.name << std::endl;
//            std::cout << "Описание: " << task.description << std::endl;
//            std::cout << std::endl;
//        }
//    }
//}

int main() {
    Task tasks[10];
    int numTasks = 0;

    void (*funcPtr[])(Task*, int&) = { addTask, deleteTask, updateTask, displayTasks };

    int choice;

    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить задачу" << endl;
        cout << "2. Удалить задачу" << endl;
        cout << "3. Обновить задачу" << endl;
        cout << "4. Отобразить задачи" << endl;
        cout << "5. Выход" << endl;
        cout << "Введите номер действия: ";
        cin >> choice;

        if (choice == 5) {
            break;
        }

        // Выполнение соответствующей функции в зависимости от выбранного действия пользователя
        if (choice >= 1 && choice <= 4) {
            (*funcPtr[choice - 1])(tasks, numTasks);
        }
        else {
            cout << "Введен неверный номер действия." << endl;
        }

        cout << endl;
    }


    /*int selectedAction = 0;

    while (true) {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Добавить задачу" << std::endl;
        std::cout << "2. Удалить задачу" << std::endl;
        std::cout << "3. Обновить задачу" << std::endl;
        std::cout << "4. Показать все задачи" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выбор: ";
        std::cin >> selectedAction;

        switch (selectedAction) {
        case ADD_TASK:
            addTask();
            break;
        case DELETE_TASK:
            deleteTask();
            break;
        case UPDATE_TASK:
            updateTask();
            break;
        case DISPLAY_TASKS:
            displayTasks();
            break;
        case EXIT:
            return 0;
        default:
            std::cout << "Недопустимый выбор. Попробуйте снова." << std::endl;
            break;
        }

        std::cout << std::endl;
    }*/

    return 0;
}