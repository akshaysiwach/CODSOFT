#include <iostream>
#include <vector>

using namespace std;

class TodoList {
private:
    vector<string> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added: " << task << endl;
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            cout << "Task removed: " << tasks[taskIndex] << endl;
            tasks.erase(tasks.begin() + taskIndex);
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "The to-do list is empty." << endl;
        } else {
            cout << "To-Do List:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i] << endl;
            }
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    while (true) {
        cout << "To-Do List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string task;
                    cout << "Enter the task to add: ";
                    cin.ignore(); // Clear the newline character from the input buffer
                    getline(cin, task);
                    todoList.addTask(task);
                }
                break;
            case 2:
                {
                    int taskIndex;
                    cout << "Enter the task number to remove: ";
                    cin >> taskIndex;
                    todoList.removeTask(taskIndex - 1);
                }
                break;
            case 3:
                todoList.displayTasks();
                break;
            case 4:
                cout << "Exiting the to-do list program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
