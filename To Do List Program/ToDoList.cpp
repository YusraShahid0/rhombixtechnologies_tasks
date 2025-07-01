#include "ToDoList.h"
#include "Helper Functions.cpp"

#include <iostream>
#include <vector>

using namespace std;

//////// PRINCIPAL FUNCTIONS /////////

// DISPLAYS THE OPTIONS FOR THE USER
int menu()
{
    cout << endl
         << endl
         << "Would you like to:" << endl
         << "1. Add a task" << endl
         << "2. Mark a task as completed" << endl
         << "3. View your current tasks" << endl
         << "4. Exit" << endl
         << "Enter you choice:";

    int choice;
    cin >> choice;
    return choice;
}

// ADDS TASK TO THE USER'S TO-DO LIST
void add_task(vector<string> &todo_list)
{
    cout << "Please enter the task." << endl;
    string task;
    cin >> task;

    trim_input(task);

    if (!valid_input)
    {
        cout << "Please enter a valid task." << endl;
        cin >> task;
    }

    todo_list.push_back(task);
    cout << "The task has been added to your to-do list!" << endl;
    return;
}

void mark_as_complete(vector<string> &todo_list)
{
    if (list_is_empty(todo_list))
    {
        cout << "U're worrying too much. There are no tasks to be completed." << endl;
        return;
    }

    cout << "Enter the task number you would like to mark as completed." << endl;

    int num;
    cin >> num;

    int size = todo_list.size();

    if ((size < num) || (size <= 0))
    {
        cout << "Please enter a valid task number." << endl;
        cin >> num;
    }

    string task = todo_list[num - 1];
    todo_list.erase(todo_list.begin() + (num - 1));

    cout << task << " has been marked as completed!" << endl;
}

void view_tasks(vector<string> &todo_list)
{
    if (list_is_empty(todo_list))
    {
        cout << "Oops no! Your to-do list is empty. CoNgRaTuLaTiOnS!!!!" << endl;
        return;
    }

    int size = todo_list.size();

    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << todo_list[i] << endl;
    }
    return;
}