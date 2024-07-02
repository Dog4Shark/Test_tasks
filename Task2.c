//
// Напишите функцию, удаляющую последовательно дублирующиеся символы в строке (решение на чистом C):
// 
// void remove_dups(char* str);
// // sample
// char data[] = "aaa CCCaaaaa";
// remove_dups(data);
// printf("%s\n", data);
// // "a С a"

#include <stdio.h>

void remove_dups(char* str)
{
    if (str[0] == '\0')
        return;
    int first = 1;
    for (int i = 1; i < str[i] != '\0'; i++)
    {
        if (str[i - 1] != str[i])
        {
            str[first++] = str[i];
        }
    }
    str[first] = '\0';
}

void main()
{
    //Tests
    char data1[] = "hhhgerll        ;fdlfg;dfg!!!!!!!";
    printf("String before modification: %s\n", data1);
    remove_dups(data1);
    printf("String after modification: %s\n", data1);       //hgerl ;fdlfg;dfg!

    char data2[] = "";
    printf("String before modification: %s\n", data2);
    remove_dups(data2);
    printf("String after modification: %s\n", data2); 

    char data3[] = "777777666545667777770023444   444";
    printf("String before modification: %s\n", data3);
    remove_dups(data3);
    printf("String after modification: %s\n", data3);       //76545670234 4

    char data4[] = "      ~~~~~~~~~     234444";
    printf("String before modification: %s\n", data4);
    remove_dups(data4);
    printf("String after modification: %s\n", data4);       // ~ 234
}