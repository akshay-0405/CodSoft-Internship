#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList
{
private:
    vector<string> tasks;

public:
    void addTask(const string &task)
    {
        tasks.push_back(task);
        cout << "----------------------------------------\n";
        cout << "Task added: " << task << '\n';
    }

    void viewTasks() const
    {
        cout << "----------------------------------------\n";
        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << i + 1 << ". " << tasks[i] << '\n';
        }
    }

    void deleteTask(size_t index)
    {
        if (index >= 1 && index <= tasks.size())
        {
            cout << "----------------------------------------\n";
            cout << "Task deleted: " << tasks[index - 1] << '\n';
            tasks.erase(tasks.begin() + index - 1);
        }
        else
        {
            cout << "Invalid index. No task deleted.\n";
        }
    }
};

int main()
{
    ToDoList toDoList;
    int choice;

    do
    {
        cout << "\n-+-+-+-+-+ To-Do List Manager +-+-+-+-+-\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cin.ignore();
            string task;
            cout << "----------------------------------------\n";
            cout << "Enter the task: ";
            getline(cin, task);
            toDoList.addTask(task);
            break;
        }
        case 2:
            toDoList.viewTasks();
            break;
        case 3:
        {
            size_t index;
            cout << "----------------------------------------\n";
            cout << "Enter the task index to delete: ";
            cin >> index;
            toDoList.deleteTask(index);
            break;
        }
        case 4:
            cout << "----------------------------------------\n";
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "----------------------------------------\n";
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
