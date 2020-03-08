#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash_map.c"
#include <assert.h>

const char MAXWORDLEN  = 250;
const char r = 3;
const char p = 10;

//возвращает длину текствого файла
int Text_Len (FILE* file)
{
    fseek(file, 0 , SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);
    return length;
}

int Hash (char* str){
    int i = 0, hash = 0, R = 1;

    while (str[i] != '\0')
    {
        hash = hash + (str[i] * R);
        R= R*r;
        i += 1;
    }

    return hash % p;
}

//считывает название, список слов, распределяет в хэш-таблице
char *Read_Input(struct word* top, int *count, FILE *file){
    int textlen = Text_Len(file);

    char *str = (char*) calloc(textlen + 1, sizeof(char));
    fread (str, sizeof(char), textlen, file);

    char *fname = strtok (str, " ");

    int key = 0;
    while (str = strtok(NULL, " "))
    {
        printf ("word: %s\n", str);
        key = Hash (str);
        printf ("key:  %d\n", key);
        Add_Table (top, key, str, *count);
        *count += 1;
    }

    free (str);
    return fname;
}

//ищет слово в хэш-таблице
void Find_word(char *str, struct word* list, char* string)
{
    int key = Hash(str);
    struct word *ptr = list[key].ptr;

    while (ptr != NULL)
    {
        if (strcmp(ptr->str, str) == 0)
        {
            string[ptr->place] +=1;
            return;
        }
        ptr = ptr->ptr;
    }

    return;
}

void Print (char *string, int count){
    int i = 0;
    for (i = 0; i < count; i += 1)
        printf ("%d ", string[i]);
    return;
}

void Count_Words (char *fname, struct word* list, int count)
{
    FILE *file = fopen(fname, "r");
    int textlen = Text_Len(file);

    char *str = calloc(textlen + 1, sizeof(char));
    fread (str, sizeof(char), textlen, file);

    char *array = calloc (count, sizeof(char));

    char *ptr = strtok (str, " /,.!?;:’'\n\0");
    while (ptr != NULL)
    {
        //printf ("%s\n", ptr);
        Find_word (ptr, list, array);
        ptr = strtok (NULL, " /,.!?;:’'\n\0");
    }

    Print(array, count);

    free (str);
    free (array);
    return;
}

int main() {
    struct word* list = Create_Table();
    FILE * file = fopen("C:\\Users\\nothe\\CLionProjects\\untitled7\\test.txt", "r");
    assert(file);
    int count = 0;
    char *fname = Read_Input (list, &count, file);
    Count_Words (fname, list, count);
    Destroy_Table(list);
}

