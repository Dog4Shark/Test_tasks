//
// Напишите функцию, которая принимает на вход знаковое целое число (uint32_t) 
// и печатает его двоичное представление как в памяти (решение на чистом C).
//


#include <inttypes.h>
#include <stdio.h>

//Функция которая принимает на вход знаковое целое число
void printDecIntBin(int32_t value)
{
    char ans[33];
    for (int i = 0; i < 32; ++i)
    {
        if (value & (1 << (31 - i)))
        {
            ans[i] = '1';
        }
        else
        {
            ans[i] = '0';
        }
    }
    ans[32] = '\0';
    printf("Signed value %ld in memory: %s\n", value, ans);
}

//Функция которая принимает на вход uint32_t
void printDecUIntBin(uint32_t value)
{
    char ans[33];
    for (int i = 0; i < 32; ++i)
    {
        if (value & (1 << (31 - i)))
        {
            ans[i] = '1';
        }
        else
        {
            ans[i] = '0';
        }
    }
    ans[32] = '\0';
    printf("uint32_t value %u in memory: %s\n", value, ans);
}



void main()
{
    printDecIntBin(1000);
    printDecUIntBin(5);
    printDecIntBin(64);
    printDecUIntBin(48);
    printDecIntBin(-2);
    printDecIntBin(0);

    int32_t num;
    printf("Enter a signed integer: ");
    scanf_s("%lu", &num);

    printDecIntBin(num);

    uint32_t unum;
    printf("Enter a unsigned integer: ");
    scanf_s("%lu", &unum);

    printDecUIntBin(unum);
}
