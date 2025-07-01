#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Helper Function Declarations
bool list_is_empty(const vector<string> &todo_list);
void trim_input(string &input);
bool valid_input(const string &input);

//Principal Function Declarations
int menu();
void add_task(vector<string> &todo_list);
void mark_as_complete(vector<string> &todo_list);
void view_tasks(vector<string> &todo_list);


#endif 