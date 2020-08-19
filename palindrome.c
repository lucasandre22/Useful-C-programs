#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *unlimited_scanf(char *string)
{
    char letter;
    int i;
    string=(char *)malloc(sizeof(char));
    if(!string)
        return NULL;
    scanf("%c", &letter);
    for(i=0;letter!='\n';i++)
    {
        string=(char *)realloc(string,(i+2)*sizeof(char));
        string[i]=letter;
        scanf("%c", &letter);
    }
    string[i]='\0';
    return string;
}

int main()
{
    int size, size_without_space = 0, palindrome = 1;
    char* string;
    printf("Palindrome check\nPlease write your phrase : ");
    string = unlimited_scanf(string);
    size = strlen(string);
    for(int i = 0; i < size; i++) {
        if(string[i] == ' ') {
            for(int j = i; j < size-size_without_space; j++)
                string[j] = string[j+1];
            size--;
        }
    }
    for(int i = 0; i < size-1; i++) {
        if(string[i] != string[(size-1)-i]) {
            printf("It's not a palindrome!");
            palindrome = 0;
            break;
        }
    }
    if(palindrome)
        printf("It's a palindrome!");
    free(string);
    return 0;
}
