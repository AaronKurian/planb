#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}
int Precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '^')
        return 3;
    return 0;
}
void infixToPostfix(char infix[], char postfix[])
{
    char stack[100];
    int top = -1;
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else if (isOperator(infix[i]))
        {
            while (top != -1 && Precedence(stack[top]) >= Precedence(infix[i]))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        else
        {
            postfix[j++] = infix[i];
        }
    }
    while (top != -1)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[100];
    printf("ENTER THE INFIX EXPRESSION: ");
    char postfix[100];
    fgets(infix, 100, stdin);
    infixToPostfix(infix, postfix);
    printf("THE POSTFIX EXPRESSION IS : %s\n", postfix);
    return 0;
}