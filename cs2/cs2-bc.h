#ifndef INCLUDE_CS2BC_H
#define INCLUDE_CS2BC_H

#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;           //ノードの中に入っているデータ部分
    struct node *next; //次のノードのアドレス
};

extern struct node head0;
extern struct node *head;
void list_initialize(void);
struct node *insert_after(int key, struct node *pt);
void print_list(struct node *pt);
void print_whole_list(void);
int insert_sorted_list(int key);
void delete_all(void);
int delete (int key);
void oddeven(struct node *head, struct node *oddhead, struct node *evenhead);
#endif  /* INCLUDE_CS2BC_H */