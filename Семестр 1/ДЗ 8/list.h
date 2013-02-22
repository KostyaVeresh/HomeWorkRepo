#pragma once
#include <iostream>
using namespace std;

struct ListElement
{
	char* value;
	int count;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

typedef ListElement* Position;

List *createList();
Position elemPos(char* value, List *list);  //���������� ��������� �� ������� ������ �� ��� ��������
void addElem(Position p, char* value);  //��������� � ������ ����� �������
void deleteElem(char* value, List *list);   //������� ������� ������ �� ��� ��������
void printList(List *list);   //������� �� ����� ������
void deleteList(List *list);  //������� ������
bool isEmpty(List *list); //������������� ������