#include "stdio.h"
#include "stdlib.h"
#include "cs3-a.h"

int main(void){
    printf("cs3-a1\n");
    printf("%s\n", __func__);

    int i;

    printf("\nstack\n");
    stackinit();
    //0~9を順にpush
    for (i = 0; i < 10; i++){
        printf("push:%3d   ", i);
        push(i);
        print_stack();
    }
    //3つpop
    for (i = 0; i < 3; i++){
        printf("pop :%3d   ", pop());
        print_stack();
    }
    //3,4push
    for (i = 3; i < 5; i++){
        printf("push:%3d   ", i);
        push(i);
        print_stack();
    }
    //空にしてみる
    stackinit();
    print_stack();
    //3~5を順にpush
    for (i = 3; i < 6; i++){
        printf("push:%3d   ", i);
        push(i);
        print_stack();
    }

    printf("\nqueue\n");
    queueinit();
    //0~9を順にput
    for (i = 0; i < 10; i++){
        printf("put :%3d   ", i);
        put(i);
        print_queue();
    }
    //3回get
    for (i = 0; i < 3; i++){
        printf("get :%3d   ", get());
        print_queue();
    }
    //3,4put
    for (i = 3; i < 5; i++){
        printf("put :%3d   ", i);
        put(i);
        print_queue();
    }
    //空にしてみる
    queueinit();
    print_queue();
    //3~5put
    for (i = 3; i < 6; i++){
        printf("put :%3d   ", i);
        put(i);
        print_queue();
    }
    return 0;
}