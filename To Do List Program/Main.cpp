#include "ToDoList.h"
#include "ToDoList.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //initializing the todolist in the form of a vector of strings
    vector<string> todolist;
    
    //initializing the variable for the user's choice
    int choice;

    //running the program continuously
    while (true){
        //getting the choice of the user
        choice = menu();

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a valid input (number)" << endl;
            continue;
        }

        //calling the functions according to the user's choice
        switch(choice) {
            case(1) : add_tasks(todolist); break;
            case(2) : mark_tasks(todolist); break;
            case(3) : view_tasks(todolist); break;
            case(4) : return 0;
        }
    }
}
