#include "ToDoList.h"

#include <iostream>
#include <vector>

using namespace std;

////// HELPER FUNCTIONS ///////

bool list_is_empty(const vector<string> &todo_list)
{
    if (todo_list.size() == 0)
    {
        return true;
    }

    return false;
}

void trim_input(string &input)
{
    int length;
    length = input.length();

    for (int i = 0; i < length; i++)
    {
        if (input[0] != ' ')
        {
            break;
        }

        else
        {
            input = input.substr(1, length - 1);
        }
    }

    int changed_length;

    for (int i = length - 1; i >= 0; i--)
    {

        changed_length = input.length();

        if (input.back() != ' ')
        {
            break;
        }

        else
        {
            input = input.substr(0, changed_length - 2);
        }
    }
}

bool valid_input(const string &input)
{
    if (input == "")
    {
        return false;
    }

    int length;
    length = input.length();

    for (int i = 0; i < length; i++)
    {
        if (input[i] != ' ')
        {
            return true;
        }
    }

    return false;
}