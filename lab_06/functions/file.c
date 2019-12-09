#include "file.h"

void add_element_in_file(FILE *f, char word[MAX_LEN_WORD])
{
    fprintf(f, " %s", word);
}