#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * Data;

typedef struct _Node
{
    Data data;
    struct _Node * next;
} Node;

typedef struct _LinkedList
{
    Node * head;
    Node * tail;
    Node * cur;
    int datanum;
} LinkedList;

typedef LinkedList List;

void InitList(List * list); // Initialization list
void Clearbuffer(void); // clear buffer
void LoadSavedPhoneNumber(List * list); // Record and reading List and Count of saved phone number
void CreateDataNum(void); // Create datanum.txt file
void CreateNumberList(void); // Create numberlist.txt file
int Menu(List * list); // Show menu(list of function) and select function
void Addphonenumber(List * list); // add phone number between last node and tail node
void Showphonenumber(List *list); // Show list of saved phone number
void Deletephonenumber(List *list); // select and delete phone number
void Saveandquit(List * list); // save all data in txt file and quit program

#endif