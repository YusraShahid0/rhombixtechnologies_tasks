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
    //prompting the user for the new task
    cout<< "Please enter the new task." << endl;

    //initializing the variable for the user input
    string input;
    cin.ignore (numeric_limits<streamsize>:: max(), '\n');
    getline(cin, input); //taking input from the user

    //adding the new task to the vector (todolist)
    todolist.push_back(input);
    cout<< "Your task has been added to the todolist." << endl;
}

void mark_as_complete(vector<string> &todo_list)
{
    //displaying the tasks to the user
    view_tasks(todolist);
    if (empty_list(todolist)) {
    cout << "Nothing to mark as complete. COnGratuLAtionsss" << endl;
    return;
    }

    //initializing variable for user choice of task number 
    int task_number;
    cin >> task_number;

    //size of the vector
    int length = todolist.size();

    //initializing the variable for valid input
    bool valid;

    //iterating until valid input is received
    while (!valid){
    if ((task_number > length) || (task_number <= 0)){
        //prompting the user for valid input
        cout << "Enter a valid task number please!" << endl;
        cin >> task_number;
        valid = false;
    }

    //valid input received
    else valid = true;
    }

    //marking the task as completed 
    todolist.erase(todolist.begin() + task_number -1);
    cout << "The task has been marked as completed" << endl;
}

void view_tasks(vector<string> &todo_list)
{
   //if the to do list is empty
    if (empty_list(todolist)){
        cout << "Your to-do list is empty." << endl;
        return;
    }

    //size of the vector
    int length = todolist.size();
    
    //iterating over the vector
    for (int i=0; i<length; i++){
         
        //displaying the task
        cout << i+1 << ". " << todolist[i] << endl; 
    }
}

//checking for empty list
bool empty_list(const vector<string> &todolist){
    //size of the vector
    int length = todolist.size();

    //if the vector has no elements
    if (length == 0) return true;

    // if the vector does have elements (not empty)
    return false;
}
