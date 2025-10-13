//палиндром 


#include <stdio.h>
#include <string.h>









int main(void)
{

    char string[] = "abaCSba";


    //удаляем пробелы
    int i = 0;
    int j = 0;

    for (i = 0; string[i] != '\0' ; i++)
    {
        if (string[i] != ' ')
        {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';

    char reversedString[strlen(string)+1];

    int len = strlen(string);
    for (int i = 0; i < len; i++) 
    {
        reversedString[i] = string[len - 1 - i];
    }
    reversedString[len] = '\0';



    
    if (strcmp(string, reversedString)==0)
    {
        printf("True\n");
    }
    else printf("False\n");


    return 0;
}