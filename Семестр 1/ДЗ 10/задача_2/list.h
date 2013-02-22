#pragma once

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

typedef ListElement* Position;

List *createList();
Position elemPos(int value, List *list);  //���������� ��������� �� ������� ������ �� ��� ��������
void addElem(Position p, int value);  //��������� � ������ ����� �������
void deleteElem(int value, List *list);   //������� ������� ������ �� ��� ��������
void printList(List *list);   //������� �� ����� ������
void deleteList(List *list);  //������� ������