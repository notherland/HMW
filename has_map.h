const char TABLESIZE = 10;

struct word{
    struct word* ptr;
    char *str;
    int place;
};

struct word* Create_Table ()
{
    struct word* table = (struct word *) calloc(TABLESIZE, sizeof(struct word));

    for (int i = 0; i < TABLESIZE; i++)
    {
        table[i].ptr = NULL;
        table[i].str = NULL;
    }

    return table;
}

void Add_Table (struct word* table, int key, char *str, int place)
{
    struct word* new = (struct word*) calloc (1, sizeof(struct word));
    new->ptr = table[key].ptr;
    table[key].ptr = new;
    new->str = str;
    new->place = place;
    return;
}

struct word* Find (struct word* table, int key){
    return table[key].ptr;
}

void Destroy_Table (struct word* table){
    int i = 0;
    struct word *ptr, *next;
    for (i = 0; i < TABLESIZE; i += 1) {
        ptr = table[i].ptr;
        while (ptr) {
            next = ptr->ptr;
            free(ptr);
            ptr = next;
        }
        free(&table[i]);
    }
    return;
}
