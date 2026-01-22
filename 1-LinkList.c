#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void(*PRINTLINKNODE) (void*);
typedef int (*COMPARELINKNODE) (void*, void*);

typedef struct LINKNODE {
    void* data;
    struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST {
    LinkNode* head;
    int size;
}LinkList;

typedef struct Students {
    int idx;
    char name[100];
    int score;
}Student;

LinkList* Init_LinkList() {
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;

    return list;
}

void Insert_LinkList(LinkList* list, int pos, void* data) {
    if (list == NULL) return;
    if (data == NULL) return;
    if (pos < 0 || pos > list->size) {
        pos = list->size;
    }

    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode->data = data;
    newnode->next = NULL;

    LinkNode* pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    newnode->next = pCurrent->next;
    pCurrent->next = newnode;

    list->size++;
}

void RemoveByPos_LinkList(LinkList* list, int pos) {
    if (list == NULL) return;
    if (pos < 0 || pos >= list->size) return;

    LinkNode* pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    LinkNode* pDel = pCurrent->next;
    pCurrent->next = pCurrent->next->next;
    free(pDel);

    list->size--;
}

int Size_LinkList(LinkList* list) {
    return list->size;
}

int Find_LinkList(LinkList* list, void* data, COMPARELINKNODE compare) {
    if (list == NULL) return -1 ;
    if (data == NULL) return -1;

    LinkNode* pCurrent = list->head->next;
    int i = 0;
    while (pCurrent != NULL) {
        if (compare(pCurrent->data,data) == 0) return i;
        i++;
        pCurrent = pCurrent->next;
    }

    return -1;
}

void* Front_LinkList(LinkList* list) {
    return list->head->next->data;
}

void Print_LinkList(LinkList* list, PRINTLINKNODE print) {
    if (list == NULL) return;
    
    LinkNode* pCurrent = list->head->next;
    while (pCurrent) {
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

void FreeSpace_LinkList(LinkList* list) {
    if (list == NULL) return;

    LinkNode* pCurrent = list->head;
    while (pCurrent) {
        LinkNode* pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }

    list->size = 0;
    free(list);
}

void MyPrint(void* data) {
    Student* s = (Student*)data;
    printf("Name:%s     Idx:%d     Score:%d\n", s->name, s->idx, s->score);
}

int CompareByIdx(void* a, void* b) {
    Student* sa = (Student*)a;
    Student* sb = (Student*)b;
    if (sa->idx < sb->idx) return -1;
    if (sa->idx > sb->idx) return 1;
    return 0;
}

int main() {
    LinkList* list = Init_LinkList();
    Student s1 = {1, "zhang", 89};
    Student s2 = {15, "li", 94};
    Student s3 = {37, "wang", 55};
    Student s4 = {10, "wu", 100};
    Student s5 = {6, "liu", 55};

    Insert_LinkList(list, 0, &s1);
    Insert_LinkList(list, 0, &s2);
    Insert_LinkList(list, 0, &s3);
    Insert_LinkList(list, 0, &s4);
    Insert_LinkList(list, 0, &s5);
    Print_LinkList(list, MyPrint);

    printf("---------------------------------------------\n");

    Student s = {10, "", 0};
    int pos = Find_LinkList(list, &s, CompareByIdx);
    printf("%d\n", pos);

    printf("---------------------------------------------\n");

    int size = Size_LinkList(list);
    printf("%d\n", size);

    printf("---------------------------------------------\n");

    RemoveByPos_LinkList(list, 2);
    Print_LinkList(list, MyPrint);
    size = Size_LinkList(list);
    printf("%d\n", size);

    printf("---------------------------------------------\n");

    Student* p = (Student*)Front_LinkList(list);
    if (p != NULL) {
        printf("Name:%s     Idx:%d     Score:%d\n", p->name, p->idx, p->score);
    }

    FreeSpace_LinkList(list);
    
}