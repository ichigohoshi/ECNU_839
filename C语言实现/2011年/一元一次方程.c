#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20

void Solve(char* s);
int Operate(char* buf, int num, int isX, int isRight);

int main()
{
    char s[] = {"6x-x=x+4"};
    Solve(s);
    return 0;
}

void Solve(char *s)
{
    int nNum, xNum, isRight;
    char buf[MAXSIZE] = {0}, x;
    nNum = xNum = isRight = 0;

    for( ; *s; s++)
    {
        if((*s >= '0' && *s <= '9') || *s == '+' || *s == '-')
        {
            if(*s == '+' || *s == '-')
                nNum = Operate(buf, nNum, 0, isRight);
            strncat(buf, s, 1);                                 //ע�ⲻ���Ƿ���������㶼Ҫ�������˳���������ÿ��������Ž��м���
        }
        if(*s == '=')
        {
            nNum = Operate(buf, nNum, 0, isRight);              //�����ʽ�ұ�ǰ�Ƚ���߽�������
            isRight = 1;
        }
        if(*s >= 'a' && *s <= 'z')
        {
            x = *s;
            xNum = Operate(buf, xNum, 1, isRight);
        }
    }
    nNum = Operate(buf, nNum, 0, isRight);                      //������ʱ��������
    printf("%c = %.3f", x, (float)nNum / (float)xNum);
}

int Operate(char *buf, int num, int isX, int isRight)
{
    int op = atoi(buf);                                         //atoi()������"+1" -> 1 "-1" -> -1 "+" -> 0  "-" -> 0 �������ַ�ֹͣת��

    if(!isX)
    {
        if(!isRight)
            num -= op;
        else
            num += op;
    }
    else
    {
        if(op == 0)                                             //����ǵ�����ĸ�������x��-x
        {
            if(buf[0] == '-')
                op = -1;
            else
                op = 1;
        }
        if(!isRight)
            num += op;
        else
            num -= op;
    }
    memset(buf, 0, MAXSIZE);                                    //�ǵ���ջ�������

    return num;
}
