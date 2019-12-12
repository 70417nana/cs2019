#include "stdio.h"
#include "stdlib.h"
#include "cs3-a.h"

stkque_t stack;
stkque_t queue;

/* それぞれの関数内でループを用いないこと！ */
// stackを初期化して空にする
void stackinit(void){
    printf("%s\n", __func__);
    //末尾の要素番号 = head = 0
    stack.tail = 0;
    printf("Init successful!\n");
}

// stackに整数numを入れる
void push(int num){
    //末尾にnumを入れる
    stack.array[stack.tail] = num;
    //末尾の要素番号インクリメント
    stack.tail++;
}

// stackから整数を1つ取り出す
int pop(void){
    int tmp;
    tmp = stack.array[stack.tail];
    //末尾の要素番号デクリメント
    stack.tail--;
    //popした値を返す
    return tmp;
}

// stackが空だったら非0の整数を返し，中身があったら0を返す．
int stackempty(void){
    //末尾の要素番号が0じゃないなら空じゃない
    if (stack.tail > 0) {
        return 0;
    } else {
        printf("stack is empty!\n");
        return 1;
    }
}

void print_stack(void){
    int i;
    for (i = 0; i < stack.tail; i++){
        printf("%d, ", stack.array[i]);
    }
    printf("\n");
}

// queueを初期化して空にする
void queueinit(void){
    printf("%s\n", __func__);
    //head = tail = 0なら空
    queue.head = 0;
    queue.tail = 0;
    printf("Init successful!\n");
}

// queueに整数numを入れる
void put(int num){
    //末尾にnumを入れる
    queue.array[queue.tail] = num;
    //末尾の要素番号インクリメント
    queue.tail++;
}

// queueから整数を1つ取り出す
int get(void){
    int tmp;
    tmp = queue.array[queue.head];
    //先頭の要素番号インクリメント
    queue.head++;
    //getした値を返す
    return tmp;
}

// queueが空だったら非0の整数を返し，中身があったら0を返す．
int queueempty(void){
    //head = tailなら空
    if (queue.head == queue.tail){
        printf("queue is empty!\n");
        return 1;
    } else {
        return 0;
    }
}

void print_queue(void){
    int i;
    for (i = queue.head; i < queue.tail; i++){
        printf("%d, ", queue.array[i]);
    }
    printf("\n");
}

