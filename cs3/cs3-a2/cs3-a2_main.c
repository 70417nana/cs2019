#include "stdio.h"
#include "stdlib.h"
#include "list.h"

int main(void){
    printf("%s\n", __func__);
    printf("stack\n");

    struct node stkhead0;
    struct node quehead0;
    struct node *stackhead = &stkhead0;
    struct node *queuehead = &quehead0;

    int i;

    /********************** 動作確認用 **********************/
    printf("\nstack\n");
    stackinit(stackhead);
    //0~9を順にpush
    for (i = 0; i < 10; i++){
        printf("push:%3d   ", i);
        push(i, stackhead);
        print_whole_list(stackhead);
    }
    //3つpop
    for (i = 0; i < 3; i++){
        printf("pop :%3d   ", pop(stackhead));
        print_whole_list(stackhead);
    }
    //3,4push
    for (i = 3; i < 5; i++){
        printf("push:%3d   ", i);
        push(i, stackhead);
        print_whole_list(stackhead);
    }
    //空にしてみる
    stackinit(stackhead);
    print_whole_list(stackhead);
    //3~5を順にpush
    for (i = 3; i < 6; i++){
        printf("push:%3d   ", i);
        push(i, stackhead);
        print_whole_list(stackhead);
    }


    printf("\nqueue\n");
    queueinit(queuehead);
    //0~9を順にput
    for (i = 0; i < 10; i++){
        printf("put :%3d   ", i);
        put(i, queuehead);
        print_whole_list(queuehead);
    }
    //3回get
    for (i = 0; i < 3; i++){
        printf("get :%3d   ", get(queuehead));
        print_whole_list(queuehead);
    }
    //3,4put
    for (i = 3; i < 5; i++){
        printf("put :%3d   ", i);
        put(i, queuehead);
        print_whole_list(queuehead);
    }
    //空にしてみる
    queueinit(queuehead);
    print_whole_list(queuehead);
    //3~5put
    for (i = 3; i < 6; i++){
        printf("put :%3d   ", i);
        put(i, queuehead);
        print_whole_list(queuehead);
    }

    return 0;
}