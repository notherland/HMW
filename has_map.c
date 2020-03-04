const char TABLESIZE = 10;

struct word{
    struct word* ptr;
    char *str;
    char len;
};

struct word* CreateTable ()
{
    struct word* table = (char*) calloc(TABLESIZE, sizeof(struct word));
    for (int i = 0; i < TABLESIZE; i++)
    {
        table[i].ptr = NULL;
        table[i].str = NULL;
    }
    return table;
}

AddTable (struct word* table, int key, char *str)
{
    struct word* new = (struct table*) calloc (1, sizeof(struct word));
    new->ptr = table[key].ptr;
    table[key].ptr = new;
    new->str = str;
}

struct word* Find (struct word* table, int key){
    return table[key].ptr;
}

void Destroy_Table (struct word* table){

}
