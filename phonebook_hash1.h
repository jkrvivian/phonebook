#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#define OPT 2
#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
// #define OPT 1

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

entry *findName(char lastname[], entry *pHead);
void append(char lastName[], entry *HashTable[]);
unsigned int BKDRHash(char *str);
#endif
