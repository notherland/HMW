#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hash_map.c"

const char MAXWORDLEN  = 20;
const char r = 3;
const char p = 10;

int Hash (char* str){
    int i = 0, hash = 0, R = 1;
    while (isalpha(str[i]))
    {
        hash = hash + (str[i] * R);
        R= R*r;
    }
    return hash % p;
}

char* Read_Word(){
    char *str = (struct word*)calloc(1, sizeof(struct word));
    int len = 0;
    scanf ("%c", str[len]);
    while (str[len] != " ")
    {
        len += 1;
        scanf ("%c", str[len]);
    }
    if (len == 0)
        return -1;
    else return str;
}

struct word *Read_Words(){
    struct word* top = CreateTable();
    char *str = (char*)calloc (MAXWORDLEN, sizeof(char));
    int key = 0;
    while (Read_Word() != -1)
    {
        key = Hash (str);
        AddTable (top, key, str);
    }
    return top;
}

Find_Words ()

Print(){
}

int main() {
    struct word* list = (struct table*) calloc (1, sizeof(struct word));
    char *fname = Read_Word();
    scanf ("%s", fname);
    FILE *f = fopen(fname, "r");
    list = Read_Words ()
    Count_Words (f);
}

