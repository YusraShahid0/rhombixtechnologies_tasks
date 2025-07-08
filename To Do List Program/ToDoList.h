#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int menu();
void add_task(vector<string> &todo_list);
void mark_as_complete(vector<string> &todo_list);
void view_tasks(vector<string> &todo_list);
bool list_is_empty(const vector<string> &todo_list);

#endif 
