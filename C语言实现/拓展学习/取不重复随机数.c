#include <stdio.h>
#include <stdlib.h>

int randrange(int N)
{
    return rand() / (RAND_MAX / N + 1);         //��ΧN�������
}

int main()
{
    int a[10], i, nvalues = 10;

    for(i = 0; i < nvalues; i++)                //nvalue����
        a[i] = i + 1;
    for(i = 0; i < nvalues - 1; i++)            //��������Ԫ�ش���
    {
        int c = randrange(nvalues - i);
        int t = a[i];
        a[i] = a[i + c];
        a[i + c] = t;
    }
    for(int i = 0; i < nvalues; i++)
        printf("%d ", a[i]);
    return 0;
}
