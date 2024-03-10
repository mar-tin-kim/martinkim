#include "Header.h"

// Initialization list
void InitList(List * list)
{
    list -> head = NULL;
    list -> tail = NULL;
    list -> cur = NULL;
    list -> datanum = 0;

    printf("# Initialization Success\n\n");

    return;
}

// clear buffer
void Clearbuffer(void)
{
    while(getchar() != '\n');
}

// Record and reading List and Count of saved phone number
void LoadSavedPhoneNumber(List * list)
{
    char data[100]; // temporary recording phone number
    FILE * datanum; // Record and reading Count of saved phone number
    FILE * numberlist; // Record and reading List of saved phone number
    
    datanum = fopen("datanum.txt", "r");

    if (datanum == NULL)
        CreateDataNum(); // Create datanum.txt file

    fscanf(datanum, "%d", &(list -> datanum));

    numberlist = fopen("numberlist.txt", "r");

    if (numberlist == NULL)
        CreateNumberList(); // Create numberlist.txt file

    while(fgets(data, 100, numberlist) != NULL) // if number exist in numberlist.txt, load number and save number in struct
    {
        Node * newnode = (Node*)malloc(sizeof(Node));
        newnode -> data = (char *)malloc(strlen(data) + 1);
        strcpy(newnode -> data, data);
        newnode -> next = NULL;

        if(list -> head == NULL) // First
        {
            list -> head = newnode;
            list -> tail = newnode;
        }

        else // After first, connect newnode between last node and tail node
        {
            Node * cur = list -> head;
            while (cur -> next != NULL)
                cur = cur -> next;

            Node * temp = cur -> next;
            cur -> next = newnode;
            newnode -> next = temp;
            list -> tail = newnode;
        }
    }
    
    fclose(datanum);
    fclose(numberlist);

    printf("# Loading Success!!\n\n");

    return;
}

// Create datanum.txt file
void CreateDataNum(void)
{
    printf("# Because of no exist file, Will create new file... \n");

    FILE * fp = fopen("datanum.txt", "w");

    fputs("0", fp);

    fclose(fp);

    printf("# Success create datanum.txt\n");

    return;
}

// Create numberlist.txt file
void CreateNumberList(void)
{
    printf("# Because of no exist file, Will create new file... \n");

    FILE * fp = fopen("numberlist.txt", "w");

    fclose(fp);

    printf("# Success create numberlist.txt\n");

    return;
}

// Show menu(list of function) and select function
int Menu(List * list)
{
    int num;

    printf("====================\n\n");
    printf("Welcome to phone book!!\n");
    printf("Count of current saved phone number: %d\n\n", list -> datanum);
    printf("[List of function]\n");
    printf("1 : Add phone number\n");
    printf("2 : Show list of saved phone number\n");
    printf("3 : Select and delete phone number\n");
    printf("0 : Save and Quit\n\n");
    printf("====================\n\n");
    printf("Insert Number: ");
    scanf("%d", &num);

    return num;
}

// add phone number between last node and tail node
void Addphonenumber(List * list)
{
    Node * newnode = (Node*)malloc(sizeof(Node));
    char data[100];

    printf("# Add phone number function\n");
    printf("Insert phone number : ");
    scanf("%s", data);
    newnode -> data = (char *)malloc(strlen(data) + 1);
    strcpy(newnode -> data, data);
    newnode -> next = NULL;

    if(list -> head == NULL) // if not exist Data of phone number, connect newnode between list's head and list's tail
    {
        list -> head = newnode;
        list -> tail = newnode;
    }

    else // if exist Data of phone number, connect newnode between last node and tail node
    {
        Node * cur = list -> head;
        while (cur -> next != NULL)
            cur = cur -> next;

        Node * temp = cur -> next;
        cur -> next = newnode;
        newnode -> next = temp;
        list -> tail = newnode;
    }

    (list -> datanum)++;

    printf("# Add phone number Success!!\n\n");

    return;
}

// Show list of saved phone number
void Showphonenumber(List *list)
{
    if(list -> datanum == 0)
    {
        printf("# No exist phone number!!\n");
        return;
    }

    printf("[List of saved phone number]\n");

    Node * cur = list -> head;
    while (cur != NULL)
    {
        printf("%s\n", cur -> data);
        cur = cur -> next;
    }

    return;
}

// select and delete phone number
void Deletephonenumber(List *list)
{
    if(list -> datanum == 0)
    {
        printf("# No exist phone number!!\n");
        return;
    }

    char target[100];

    printf("[Select and delete phone number]\n");
    printf("Insert number : ");
    Clearbuffer(); // clear buffer
    fgets(target, 100, stdin);

    Node * cur = list -> head;
    Node * temp = NULL;

    while (cur != NULL)
    {
        if (strcmp(cur -> data, target) == 0)
        {
            if (temp == NULL)
                list -> head = cur -> next;

            else
                temp -> next = cur -> next;

            free(cur);
            (list -> datanum)--;

            printf("# Delete phone number Success!!\n");
            return;
        }

        temp = cur;
        cur = cur -> next; 
    }

    printf("# No exist number you insert!!\n");
    return;
}

// save all data in txt file and quit program
void Saveandquit(List * list)
{
    FILE * datanum; // Record count of saved phone number
    FILE * numberlist; // Record all list of saved phone number

    datanum = fopen("datanum.txt", "w");
    fprintf(datanum, "%d", list -> datanum);
    fclose(datanum);

    numberlist = fopen("numberlist.txt", "w");
    Node * cur = list -> head;
    while (cur != NULL)
    {
        fprintf(numberlist, "%s\n", cur -> data);
        cur = cur -> next;
    }
    fclose(numberlist);

    printf("# Success saved all data!! Good bye~\n");

    return;
}