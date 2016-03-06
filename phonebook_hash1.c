#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash1.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *e)
{
    /* TODO: implement */
    entry *tmp;
    //unsigned int index = BKDRHash(lastname);
    if(e) {
        printf("there is %s\n",e->lastName);
        if (strcasecmp(lastname, e->lastName) == 0)
            return e;
        else {
            for(tmp = e; (tmp->pNext) && strcasecmp(lastname, tmp->lastName) != 0; tmp = tmp->pNext);
            if(tmp) return tmp;
            else return NULL;
        }
    }
    return NULL;
}

void append(char lastName[], entry *e)
{
    entry *tmp;
    /*if the index has no data*/
    if (e->pNext== NULL) {
        e = (entry *) malloc(sizeof(entry));
        strcpy(e->lastName, lastName);
        e->pNext = NULL;
    } else {
        if(e->pNext) {
            for(tmp = e; tmp->pNext != NULL; tmp = tmp->pNext)
                printf("who %s\n",tmp->lastName);
        } else tmp = e;
        tmp->pNext = (entry *) malloc(sizeof(entry));
        tmp = tmp->pNext;
        strcpy(tmp->lastName, lastName);
        tmp->pNext = NULL;
    }

}

void FreeAll(entry *e)
{
    entry *tmp;
    while(e) {
        tmp = e;
        e = e->pNext;
        free(tmp);
    }
}

unsigned int BKDRHash(char lastName[])
{
    unsigned int seed=31;
    unsigned int hash=0;
    int i=0;
    while(i<strlen(lastName)) {
        hash = hash * seed + lastName[i];
        ++i;
    }
    hash %= 1051;
    if(hash < 0) hash += 1051;

    return hash;
}

