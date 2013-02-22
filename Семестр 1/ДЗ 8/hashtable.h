#pragma once;
#include "list.h"
#include <iostream>
using namespace std;

List** createHasheTable(int hashsize);
int calculateHash(char* str, int hashsize);
void addValue(List** table, char* value, int hashsize);
void deleteValue(List** table, char* value, int hashsize);
void destroyHashTable(List** table, int hashtable);