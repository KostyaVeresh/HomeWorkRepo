#pragma once

typedef int ElementType;

struct List;

struct ListElement;


List *createList(); // создает список
void addElement(List *list, ElementType value); // добавляет элемент в конец списка
int returnAmount(List *list); // возвращает длину списка
ElementType returnElement(List *list, int n); // возвращает значение n-ого элемента списка 
List *firstPart(List *list, int number); // возвращает список с первого элемента до номера
List *secondPart(List *list, int number); // возвращает список с номера до конца списка
void printList(List *list); // выводит список на экран
void deleteList(List *list); // удаляет список