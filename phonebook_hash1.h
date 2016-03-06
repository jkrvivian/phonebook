#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#define HASH 1
#define MAX_LAST_NAME_SIZE 16
#define SIZE 1051
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

entry *findName(char lastname[], entry *e);
void append(char lastName[], entry *e);
void FreeAll(entry *e);
unsigned int BKDRHash(char *str);
#endif
