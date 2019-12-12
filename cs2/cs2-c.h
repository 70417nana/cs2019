#ifndef __CS2C_H__
#define __CS2C_H__

#include <stdio.h>
#include <stdlib.h>

//------------- 検証用オプション ---------------//
/*  検証する課題以外はコメントアウト
    コメントアウトされていない課題が実行される
 */

#define SBJ_2B1   //課題2b-1
// #define SBJ_2B2   //課題2b-2
// #define SBJ_2B3   //課題2b-3
// #define SBJ_2B4   //課題2b-4

//---------------------------------------------//



struct node{
    int key;           //ノードの中に入っているデータ部分
    struct node *next; //次のノードのアドレス
};

extern struct node head0; //処理し易さのために先頭に置くダミーの要素
extern struct node *head; //先頭へのポインタの定義

void list_initialize(void);
struct node * insert_after(int key, struct node * pt);
void print_list(struct node * pt);
void print_whole_list(void);
void print_whole_list_GP(struct node *list);

int insert_sorted_list(int key);
int insert_list_GP(int key, struct node *insert_head);
void delete_all(void);
int delete(int key);
void oddeven(struct node *head, struct node *oddhead, struct node *evenhead);
// struct node *merge(struct node *head1, struct node *head2);

#endif /* __CS2C_H__ */