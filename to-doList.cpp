#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void AddTask(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to view tasks
void ViewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "[" << (i + 1) << "] ";
        if (tasks[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void MarkTaskAsCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed: " << tasks[taskIndex - 1].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the list
void RemoveTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        cout << "Task removed: " << tasks[taskIndex - 1].description << endl;
        tasks.erase(tasks.begin() + taskIndex - 1);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;
    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            AddTask(tasks, description);
        } else if (choice == 2) {
            ViewTasks(tasks);
        } else if (choice == 3) {
            int taskIndex;
            cout << "Enter task index to mark as completed: ";
            cin >> taskIndex;
            MarkTaskAsCompleted(tasks, taskIndex);
        } else if (choice == 4) {
            int taskIndex;
            cout << "Enter task index to remove: ";
            cin >> taskIndex;
            RemoveTask(tasks, taskIndex);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

return 0;
}