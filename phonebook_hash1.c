#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash1.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
    entry *tmp;
    unsigned int index = BKDRHash(lastname);
    if(HashTable[index]) {
        if (strcasecmp(lastname, HashTable[index]->lastName) == 0)
            return tmp;
        else{
            for(tmp = HashTable[index]; (tmp->pNext) && strcasecmp(lastname, HashTable[index]->lastName) != 0; tmp = tmp->pNext);
            if(tmp) return tmp;
        }
    }
    return NULL;
}

void append(char lastName[], entry *HashTable[])
{
    entry *tmp;
    unsigned int index = BKDRHash(lastName);
    /*if the index has no data*/
    if (!HashTable[index]) {
        HashTable[index] = (entry *) malloc(sizeof(entry));
	strcpy(HashTable[index]->lastName, lastName);
    	HashTable[index]->pNext = NULL;
    } else {
        for(tmp = HashTable[index]; tmp->pNext != NULL; tmp = tmp->pNext);
        tmp->pNext = (entry *) malloc(sizeof(entry));
	tmp = tmp->pNext;
	strcpy(tmp->lastName, lastName);
        tmp->pNext = NULL;
    }
    
}

unsigned int BKDRHash(char lastName[])
{
    unsigned int seed=31;
    unsigned int hash=0;
    int i=0;
    while(lastName[i] != '\0') {
        hash = hash * seed + lastName[i];
	++i;
    }

    return hash;
}

