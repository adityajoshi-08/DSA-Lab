// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int data;
//     struct node *next;
// };
// typedef struct node node;

// node *top;

// void initialize()
// {
//     top = NULL;
// }

// void push(int value)
// {
//     node *tmp;
//     tmp = malloc(sizeof(node));
//     tmp->data = value;
//     tmp->next = top;
//     top = tmp;
// }

// int pop()
// {
//     node *tmp;
//     int n;
//     tmp = top;
//     n = tmp->data;
//     top = top->next;
//     free(tmp);
//     return n;
// }

// int Top()
// {
//     return top->data;
// }

// int isempty()
// {
//     return top == NULL;
// }

// void display(node *head)
// {
//     if (head == NULL)
//     {
//         printf("NULL\n");
//     }
//     else
//     {
//         printf("%d\n", head->data);
//         display(head->next);
//     }
// }

// int main()
// {
//     initialize();
//     push(10);
//     push(20);
//     push(30);
//     printf("The top is %d\n", Top());
//     pop();
//     printf("The top after pop is %d\n", Top());
//     display(top);
//     return 0;
// }

#include <stdio.h>
#include <ctype.h>
int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1, n2, n3, num;
    printf("Enter the expression :: ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n", exp, pop());
    return 0;
}
