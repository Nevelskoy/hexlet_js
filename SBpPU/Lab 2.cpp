#include <stdio.h>
#include <iostream>
using namespace std;

void binary(char x)
{
       for (int i = 0; i < 8; i++)
       {
           cout << (x >> 7);
           x <<= 1;
       }
       cout << endl;
}


int main ()
{
    size_t num_bit = 5;
    char x = 0xff;
    cout << "1) Меняем заданный бит в 0 " << endl;
    binary(x);
    x = x & ~(1 << num_bit); // 1 это 00000001, сдвигаем <<, получаем 005 (если на 5)
    binary(x);
    cout << "\n" << endl;
    
    char y = 0xAA;
    int bit = (y >> num_bit) & 1;
    cout << "2) Считываем заданный бит - " << num_bit << ", бит равен " << bit <<endl;
    binary(y);
    cout << "\n" << endl;
    
    char z = 0;
    z = z | (1 << num_bit);
    cout << "3) Меняем заданный бит на 1 " << endl;
    binary(z);
    return 0;
}
