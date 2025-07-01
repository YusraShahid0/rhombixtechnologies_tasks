#include "ToDoList.h"
#include "ToDoList.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> todo_list;
    cout << "Helloo! It's sad to see you're back to your to-do list. But no worries it's better to put the task on the list and feel a step closer to completing it rather than actually doing it... hehe" << endl;
    int choice;
    
    while (true)
    {
        choice = menu();

         if (cin.fail()) {
            cin.clear(); // clear the fail state
            cin.ignore(10000, '\n'); // discard bad input
            cout << "Invalid input. Please enter a number.\n";
            continue; // go back to the menu
         }

        switch (choice)
        {
        case 1:
            cout << endl << "Ahhh! this is where procrastination begins..." << endl;
            add_task(todo_list);
            break;

        case 2:
            cout << endl << "wow gurlll! u actually got something completed!" << endl;
            mark_as_complete(todo_list);
            break;

        case 3:
            cout << endl << "haha... Welcome to Your Journey to Depression Land." << endl;
            view_tasks(todo_list);
            break;
        case 4:
            return 0;
            break;
        }
    }
}