#include <stdio.h>

int bitsSwapRequired(int x, int y)
{
    int cnt = 0;
    for(unsigned mask = (1 << 31); mask > 0; mask >>= 1)    //Ҫʹ���޷���������������λ��������ɨ��ſ���
    {
        if( (x & mask) != (y & mask) )
            cnt++;
    }
    return cnt;
}


int main()
{
//    int x = 0xa0000000;
//    int y = 0x20000000;
    int x = 1, y = 10;

    printf("%d ", bitsSwapRequired(x, y));
    return 0;
}
