#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

// Substring
int substring(char *str1, char *str2)
{
    int i = 0, j = 0;
    while (*(str1 + i) != '\0' && *(str2 + j) != '\0')
    {
        if (*(str1 + i) == *(str2 + j))
        {
            i++;
            j++;
        }
        else
        {
            i++;
            j = 0;
        }
    }
    if (*(str2 + j) == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// check if line is empty
int EmptyLine(char *EL)
{
    int j = strlen(EL);
    if (strcmp(EL + j - 1, "\n") == 0)
    {
        return 1;
    }
    return 0;
}
// Similar Words
int similarbyOneorZero(char *s, char *t)
{
    int cnt = 0;
    int i = strlen(s);
    int j = strlen(t);
    if (EmptyLine(t))
    {
        j--;
    }
    if (j > i + 2)
    {
        return 0;
    }
    while (i > 0 || j > 0)
    {
        if (*(s) != '\0' && *(t) != '\0' && *(s) == *(t))
        {
            s++;
            t++;
            i--;
            j--;
        }
        else if (*(s) == '\0' && *(t) != '\0' && *(s) == *(t))
        {
            t++;
            j--;
        }
        else if (*(s) != '\0' && *(t) == '\0' && *(s) == *(t))
        {
            s++;
            i--;
        }
        else if (*(t) != '\0' && *(s) != *(t))
        {
            t++;
            cnt++;
            j--;
        }
        if (i > j + 2)
        {
            return 0;
        }
    }
    if (cnt == 1 || cnt == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// char* SPLIT
int FillArray(char *line, char **linearr)
{
    int i = 0;
    char *cnt = strtok(line, " ");
    while (cnt != NULL)
    {
        linearr[i++] = cnt;
        cnt = strtok(NULL, " ");
    }
    return i;
}

// print_lines
void printA(char *line2, char *key)
{
    if (substring(line2, key) == 1)
    {
        printf("%s", line2);
    }
}

// print_similar_words

void printB(char **linearr, int linesize, char *key)
{
    for (int i = 0; i < linesize; i++)
    {
        if (similarbyOneorZero(key, linearr[i]) == 1)
        {
            printf(EmptyLine(linearr[i]) == 0 ? "%s\n" : "%s", linearr[i]);
        }
    }
}
int main()
{
    char line[LINE];
    char key[WORD];
    char letter[WORD];
    char line2[LINE];
    char *linearr[128] = {0};
    int choice = 1;
    int linesize = 0;
    while (fgets(line, LINE, stdin) != NULL)
    {
        strcpy(line2, line);
        linesize = FillArray(line, linearr);
        if (choice == 1)
            strcpy(key, linearr[0]), strcpy(letter, linearr[1]);
        if (strcmp(letter, "a\n") == 0 && choice != 1)
            printA(line2, key);
        if (strcmp(letter, "b\n") == 0 && choice != 1)
            printB(linearr, linesize, key);
        memset(line, 0, sizeof(line));
        choice = choice + 1;
    }
    return 0;
}