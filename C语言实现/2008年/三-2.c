#include <stdio.h>
#define MAXSIZE 20

void In_Order(int T[], int i, int n);
void In_Order1(int T[], int n);

int main()
{
    int T[] = {4, 2, 6, 1, 3, 5, 7};
    int n = sizeof(T) / sizeof(T[0]);
    In_Order(T, 0, n);
    printf("\n");
    In_Order1(T, n);

    return 0;
}

void In_Order(int T[],int i, int n)
{
    if(i < n)
    {
        In_Order(T, i*2 + 1, n);
        printf("%d ", T[i]);
        In_Order(T, i*2 + 2, n);
    }
}

void In_Order1(int T[], int n)          //��������ǵݹ�
{
    int i = 0;
    int Stack[MAXSIZE], top = -1;

    while(i < n || top != -1)
    {
        while(i < n)                    //����������
        {
            Stack[++top] = i;
            i = i * 2 + 1;
        }
        if(top != -1)                   //����������������ջ�л��н��
        {
            i = Stack[top--];
            printf("%d ", T[i]);
            i = i * 2 + 2;
        }
    }
}
