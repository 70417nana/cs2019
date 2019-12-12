#include "stdio.h"
#include "stdlib.h"
#include "list.h"

/************************* 前回の課題で作成した関数 **************************/
struct node head0; //処理し易さのために先頭に置くダミーの要素
struct node *head=&head0; //先頭へのポインタの定義

/**
 *  @fn     list_initialize
 *  @brief  リストの初期化
 *  @param  なし
 *  @return なし
 * */
void list_initialize(void){
    head->next = NULL; //headの次はNULLとする．
}

/**
 *  @fn     insert_after
 *  @brief  末尾にkeyを挿入する
 *  @param  key 整数
 *  @param  pt  挿入したい場所のポインタ
 *  @return 新しいnodeの先頭アドレス
 * */
struct node * insert_after(int key, struct node * pt){ //挿入したいkeyの値と次に挿入したい場所のポインタ
    struct node * new_node; //挿入されるキーを格納するノードへのポインタ
    new_node = (struct node*)malloc(sizeof *new_node); //ノードの確保
    if (new_node==NULL){ //確保できなかった場合は
        printf("Not enough memory\n");
        exit(1);  //終了
    }
    new_node -> key = key; //新しいノードのキーに値を格納
    new_node -> next = pt -> next; //new_nodeのnextはptのnext
    pt -> next = new_node; //ptのnextはnew_node
    return new_node; //new_nodeの先頭アドレスを返す
}

/**
 *  @fn     delete_all
 *  @brief  ノードの全削除をする
 *  @param  なし
 *  @return なし
 * */
void delete_all(void){
    printf("delete all\n");
    struct node *p;
    struct node *tmp;
    for (p = head->next; p != NULL; p = tmp){
        tmp = p->next;
        free(head->next); //開放する
        head->next = tmp;
    }
}
/************************ ここまで前回作成した関数 *************************/


/**
 *  @fn     delete_next
 *  @brief  次の要素を返してその要素を削除する
 *  @param  pt  消したいところの前のノード
 *  @return 次の要素
 * */
int delete_next(struct node *pt){
    int num;
    struct node *tmp;
    if(pt->next != NULL){//次の要素がNULLならおわり
        num = pt->next->key;
        tmp = pt->next->next;
        free(pt->next);
        pt->next = tmp; //つなぎかえる
        return num;
    } else {
        exit(1);
    }
}

/**
 *  @fn     print_whole_list
 *  @brief  指定したリストをすべて表示する
 *  @param  list    表示したいリストのheadのアドレス  
 *  @return なし
 * */
void print_whole_list(struct node *list){
    if(!stackempty(list)) {
        for (list=list->next; list!=NULL; list=list->next){
            printf("%d -> ",list->key); 
        }
    }
    printf("\n");
}


// stackを初期化して空にする
void stackinit(struct node *head){
    printf("%s\n", __func__);
    //headの次がnullなら間になにもないため空となる
    head->next = NULL;
}

// stackに整数numを入れる
void push(int num, struct node *head){
    printf("push:%3d   ", num);
    struct node *p; //ループカウンタ
    //pを末尾までもっていく
    for (p = head; p->next != NULL; p = p->next){
        /* なにもしない */
    }
    //末尾まで来たらinsert
    insert_after(num, p);
}

// stackから整数を1つ取り出す
int pop(struct node *head){
    struct node *p; //ループカウンタ
    //delete_next関数は次の要素を消すためp->next->nextがNULLになるまで
    for (p = head; p->next->next != NULL; p = p->next){
        /* なにもしない */
    }
    //末尾まで来たらpの次をdelete
    
    printf("pop :%3d   ", p->next->key);
    return delete_next(p);
} 

// stackが空だったら非0の整数を返し，中身があったら0を返す．
int stackempty(struct node *head){
    //headの次がNULLなら空
    if (head->next == NULL){
        printf("empty!\n");
        return 1;
    } else {
        return 0;
    }
}

// queueを初期化して空にする
void queueinit(struct node *head){
    printf("%s\n", __func__);
    //headの次がnullなら間になにもないため空となる
    head->next = NULL;
}

// queueに整数numを入れる
void put(int num, struct node *head){
    struct node *p; //ループカウンタ
    //pを末尾までもっていく
    for (p = head; p->next != NULL; p = p->next){
        /* なにもしない */
    }
    //末尾まで来たらinsert
    insert_after(num, p);
}

// queueから整数を1つ取り出す
int get(struct node *head){
    //headの次を消して消した値を返す
    return delete_next(head);
}

// queueが空だったら非0の整数を返し，中身があったら0を返す．
int queueempty(struct node *head){
    //headの次がNULLなら空
    if (head->next == NULL){
        printf("empty!\n");
        return 1;
    } else {
        return 0;
    }
}