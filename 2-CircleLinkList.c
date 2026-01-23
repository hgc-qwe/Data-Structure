#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LINKNODE {
    struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST {
    LinkNode head;
    int size;
}LinkList;

LinkList* Init_CircleLinkList() {
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head.next = &(list->head);
    list->size = 0;

    return list;
}

typedef struct PERSON {
    LinkNode node;
    char name[64];
    int age;
    int score;
}Person;

typedef int (*COMPARENODE) (LinkNode*, LinkNode*);
typedef void (*PRINTNODE) (LinkNode*);

void Insert_CircleLinkList(LinkList* list, int pos, LinkNode* data) {
    if (list == NULL) return;
    if (data == NULL) return;
    if (pos < 0 || pos > list->size) pos = list->size;

    LinkNode* pCurrent = &(list->head);
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    data->next = pCurrent->next;
    pCurrent->next = data;

    list->size++;
}

LinkNode* Front_CircleLinkList(LinkList* list) {
    return list->head.next;
}

void RemoveByPos_CircleLinkList(LinkList* list, int pos) {
    if (list == NULL) return;
    if (pos < 0 || pos > list->size) return;

    LinkNode* pCurent = &(list->head);
    for (int i = 0; i < pos; i++) {
        pCurent = pCurent->next;
    }

    LinkNode* pDel = pCurent->next;
    pCurent->next = pDel->next;

    list->size--;
}

void RemoveByValue_CircleLinkList(LinkList* list, LinkNode* data, COMPARENODE compare) {
    if (list == NULL) return;
    if (data == NULL) return;

    LinkNode* pPrev = &(list->head);
    LinkNode* pCurrent = list->head.next;
    for (int i = 0; i < list->size; i++) {
        if (compare(pCurrent, data) == 1) {
            pPrev->next = pCurrent->next;
            break;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }
}

int Size_circleLinkList(LinkList* list) {
    return list->size;
}

int IsEmpty_CircleLinkList(LinkList* list) {
    if (list == NULL || list->size == 0) return 1;
    else return 0;
}

int Find_CircleLinkList(LinkList* list, LinkNode* data, COMPARENODE compare) {
    if (list == NULL) return -1;
    if (data == NULL) return -1;

    LinkNode* pCurrent = list->head.next;
    int flag = -1;
    for (int i = 0; i < list->size; i++) {
        if (compare(pCurrent, data) == 1) {
           flag = i;
           break;
        }
        pCurrent = pCurrent->next;
    }

    return flag;
}

void Print_CircleLinkList(LinkList* list, PRINTNODE print) {
    if (list == NULL) return;

    LinkNode* pCurrent = list->head.next;
    for (int i = 0; i < list->size * 2; i++) {
        if (pCurrent == &(list->head)) pCurrent = pCurrent->next;
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
}

void FreeSpace_CircleLinkList(LinkList* list) {
    if (list == NULL) return;
    free(list);
}

void Myprint(LinkNode* data) {
    Person* p = (Person*)data;
    printf("Name:%s     Age:%d     Score:%d\n", p->name, p->age, p->score);
}

int Mycompare(LinkNode* a, LinkNode* b) {
    Person* pa = (Person*)a;
    Person* pb = (Person*)b;

    if (strcmp(pa->name, pb->name) == 0 && pa->age == pb->age && pa->score == pb->score) return 1;
    else return 0;
}

int main() {
    LinkList* list = Init_CircleLinkList();

    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "zhang");
    strcpy(p2.name, "li");
    strcpy(p3.name, "wang");
    strcpy(p4.name, "liu");
    strcpy(p5.name, "wu");

    p1.age = 10;
    p2.age = 12;
    p3.age = 44;
    p4.age = 15;
    p5.age = 19;

    p1.score = 100;
    p2.score = 98;
    p3.score = 30;
    p4.score = 66;
    p5.score = 100;

    Insert_CircleLinkList(list, 100,(LinkNode*)&p1);
    Insert_CircleLinkList(list, 100,(LinkNode*)&p2);
    Insert_CircleLinkList(list, 100,(LinkNode*)&p3);
    Insert_CircleLinkList(list, 100,(LinkNode*)&p4);
    Insert_CircleLinkList(list, 100,(LinkNode*)&p5);
    Print_CircleLinkList(list, Myprint);

    Person pDel;
    strcpy(pDel.name, "wang");
    pDel.age = 44;
    pDel.score = 30;
    RemoveByValue_CircleLinkList(list, (LinkNode*)&pDel, Mycompare);
    Print_CircleLinkList(list, Myprint);

    FreeSpace_CircleLinkList(list);
}