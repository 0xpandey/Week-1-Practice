#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Task {
public:
    string title;
    bool completed;

    Task(string t, bool c = false) {
        title = t;
        completed = c;
    }
};
class ToDoList {
private:
    vector<Task> tasks;
public:
    void loadFromFile() {
        ifstream file("tasks.txt");
        if (!file) return;

        string title;
        bool status;

        while (getline(file, title)) {
            file >> status;
            file.ignore();
            tasks.push_back(Task(title, status));
        }
        file.close();
    }
    void saveToFile() {
        ofstream file("tasks.txt");
        for (auto &task : tasks) {
            file << task.title << endl;
            file << task.completed << endl;
        }
        file.close();
    }
    void addTask() {
        cin.ignore();
        string title;
        cout << "Enter task title: ";
        getline(cin, title);
        tasks.push_back(Task(title));
        cout << "Task added.\n";
    }
    void showTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". "
                 << (tasks[i].completed ? "[✔] " : "[ ] ")
                 << tasks[i].title << endl;
        }
    }
    void markCompleted() {
        showTasks();
        if (tasks.empty()) return;

        int index;
        cout << "Enter task number to mark complete: ";
        cin >> index;

        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
};

int main() {
    ToDoList todo;
    todo.loadFromFile();

    int choice;

    do {
        cout << "\n--- TO-DO LIST ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Save & Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: todo.addTask(); break;
            case 2: todo.showTasks(); break;
            case 3: todo.markCompleted(); break;
            case 4: 
                todo.saveToFile();
                cout << "Tasks saved. Goodbye.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
