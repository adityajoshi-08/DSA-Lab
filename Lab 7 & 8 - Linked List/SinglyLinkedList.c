#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node* head = NULL;
node *tail = NULL;

// Functions for insertion
void insertTop(int value){
    node* temp = malloc(sizeof(node));
    temp->data = value;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    } else
    {
        temp->next = head;
        head = temp;
    }
    free(temp);
}

void insertLast(int value){
    node *temp = malloc(sizeof(node));
    temp->data = value;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    } else
    {
        tail->next = temp;
        tail = temp;
    }
    free(temp);
}

void insert(int index, int value){
    node* temp = malloc(sizeof(node));
    temp->data = value;
    node* tmp = head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }

    temp->next = tmp->next;
    tmp->next = temp;
}

// Functions for deletion

void deleteStart(){
    node* tmp = head;
    head = head->next;
    free(tmp);
}

void deleteEnd(){
    node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node* tmp = temp->next;
    tail = temp;
    free(tmp);
}

void delete(int index){
    node* tmp = head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    node* temp = tmp->next;
    tmp->next = tmp->next->next;
    free(temp);
}

void print(){
    node* tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        printf("%d -->", tmp->data);
    }
}

int main()
{
    
    return 0;
}
