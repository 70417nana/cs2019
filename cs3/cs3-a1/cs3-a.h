#ifndef _CS3A_H_
#define _CS3A_H_

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct {
    int tail;    //データの数, 一番後ろの要素番号
    int array[STACK_SIZE];
    int head;   //スタックでは未使用
} stkque_t;

void stackinit(void);   // stackを初期化して空にする
void push(int num);     // stackに整数numを入れる
int pop(void);          // stackから整数を1つ取り出す
int stackempty(void);   // stackが空だったら非0の整数を返し，中身があったら0を返す．

void queueinit(void);   // queueを初期化して空にする
void put(int num);      // queueに整数numを入れる
int get(void);          // queueから整数を1つ取り出す
int queueempty(void);   // queueが空だったら非0の整数を返し，中身があったら0を返す．

void print_stack(void);
void print_queue(void);

#endif /* _CS3A_H_ */