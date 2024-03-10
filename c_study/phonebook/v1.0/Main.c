#include "Header.h"

int main(void)
{
    List * list;
    list = (List*)malloc(sizeof(List));
    int num; // select function

    InitList(list); // Initialization list
    LoadSavedPhoneNumber(list); // Record and reading List and Count of saved phone number

    while(1)
    {
        num = Menu(list); // Show menu(list of function) and select function

        if (num == 0)
        {
            Saveandquit(list); // save all data in txt file and quit program
            break;
        }
        
        else if (num == 1)
            Addphonenumber(list); // add phone number between last node and tail node

        else if (num == 2)
            Showphonenumber(list); // Show list of saved phone number

        else if (num == 3)
            Deletephonenumber(list); // select and delete phone number

        else
            printf("Error! Please insert number in list");
    }

    return 0;
}