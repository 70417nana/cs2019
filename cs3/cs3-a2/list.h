#ifndef _LINK_H_
#define _LINK_H_

#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;           //ノードの中に入っているデータ部分
    struct node *next; //次のノードのアドレス
};

void list_initialize(void);
struct node * insert_after(int key, struct node * pt);
void delete_all(void);
int delete_next(struct node *pt);
void print_whole_list(struct node *list);

void stackinit(struct node *head);
void push(int num, struct node *head);   // stackに整数numを入れる
int pop(struct node *head);  // stackから整数を1つ取り出す
int stackempty(struct node *head);// stackが空だったら非0の整数を返し，中身があったら0を返す．

void queueinit(struct node *head);     // queueを初期化して空にする
void put(int num, struct node *head);   // queueに整数numを入れる
int get(struct node *head);  // queueから整数を1つ取り出す
int queueempty(struct node *head);   // queueが空だったら非0の整数を返し，中身があったら0を返す

#endif /* _LINK_H_ */