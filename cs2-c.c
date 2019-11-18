#include "stdio.h"
#include "stdlib.h"

struct node{
    int key;           //ノードの中に入っているデータ部分
    struct node *next; //次のノードのアドレス
};

struct node head0; //処理し易さのために先頭に置くダミーの要素
struct node *head=&head0; //先頭へのポインタの定義

void list_initialize(void){
    head->next = NULL; //headの次はNULLとする．
}

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

void print_list(struct node * pt){
    struct node *p;
    for (p=pt; p!=NULL; p=p->next){
    printf("%d -> ",p->key); //pのkeyを表示して
    }
    printf("\n");
}

void print_whole_list(void){
    struct node *p;
    for (p=head->next; p!=NULL; p=p->next){
    printf("%d -> ",p->key); //pのkeyを表示して
    }
    printf("\n");
}

void print_whole_list_GP(struct node *list){
    for (list=list->next; list!=NULL; list=list->next){
        printf("%d -> ",list->key); 
    }
    printf("\n");
}

/**
 * @fn      insert_sorted_list
 * @brief   それまでに探索された整数全種類を小さい順に整数列配列に格納する
 * @param   整数値key
 * @return  keyが探索されたことがない：0  
 *          keyが探索されたことがある：1
 * */
int insert_sorted_list(int key){
    struct node *p;
    struct node *insert_p = head; //先頭
    for (p = head->next; p != NULL; /*なにもしない*/){
        //小さい順に並んでいる前提であるためkeyより小さければよい
        if (p->key < key){
            insert_p = p;
            p = p->next;
        } else if (p->key == key){  //keyと同じ数字が既にある場合は1を返して終了
            return 1;
        } else { 
            break;
        }
    }
    //リストにまだないkeyの場合は最後に挿入し0を返す
    insert_after(key, insert_p);
    return 0;
}

int insert_list_GP(int key, struct node *insert_head){
    struct node *p;
    struct node *insert_p = insert_head; //先頭
    for (p = insert_head->next; p != NULL; /*なにもしない*/){
        //小さい順に並んでいる前提であるためkeyより小さければよい
        if (p->key < key){
            insert_p = p;
            p = p->next;
        } else { 
            break;
        }
    }
    //リストにまだないkeyの場合は最後に挿入し0を返す
    insert_after(key, insert_p);
    return 0;
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

/**
 * @fn      delete
 * @brief   指定されたkeyのノードの削除をする
 * @param   整数値key
 * @return  削除成功：0  
 *          削除失敗：1
 * */
int delete(int key){
    struct node *p;
    struct node *tmp;
    for (p = head->next; p != NULL; p = p->next){
        if(p->next != NULL) {
            //ヒットしたら消して，消せたことを示した後に1を返す
            if (key == p->next->key){
                tmp = p->next->next;//次の次を一時的においておく
                free(p->next);
                p->next = tmp;
                printf("node%d deletion successful\n", key);
                return 1;
            }
        }
    }
    //ヒットしなかったら消せたことを示した後に0を返す
    printf("node%d deletion failed\n", key);
    return 0;
}

int delete_GP(struct node *p, int key)
{
    struct node *temp;
    //リストの最後までfor文を回す
    for (; p != NULL; p = p->next)
    {
        if (p->next != NULL && key == p->next->key)
        { //pの次のノードがkeyと同じ値であった場合
            //削除したいノードの次のノードのアドレスを一時変数に記憶させておく
            temp = p->next->next;
            //keyと同じ値を持つノードのメモリを開放
            free(p->next);
            //pのnextに削除したノードの次のノードのアドレスを格納
            p->next = temp;
            //削除したので1を返す
            return 1;
        }
    }
    //keyと同じ値がなければ0を返す
    return 0;
}
/**
 * @fn      oddeven
 * @brief   偶数と奇数のリストに分ける
 * @param   元のリストのアドレスhead
 * @param   奇数のリストのアドレスoddhead
 * @param   偶数のリストのアドレスevenhead
 * @return  なし
 * */
void oddeven(struct node *head, struct node *oddhead, struct node *evenhead){
    struct node *oddlist = oddhead, *evenlist = evenhead, *p;
    for (p = head->next; p != NULL; p = p->next){
        //奇数
        if (((p->key) % 2) == 1){
            oddlist->next = p;
            oddlist = oddlist->next;
        }
        //偶数
        else{
            evenlist->next = p;
            evenlist = evenlist->next;  
        }
    }
    //最後にNULLを入れる
    oddlist->next = NULL;
    evenlist->next = NULL;
}

/**
 * @fn      merge
 * @brief   二つのリストをマージする
 * @param   元のリストのアドレスhead1
 * @param   元のリストのアドレスhead1
 * @return  merge後のリスト
 * */
struct node *merge(struct node *head1, struct node *head2){
    //mergeの初期設定
    static struct node merge0;
    struct node *merge = &merge0;
    merge->next = NULL;

    //一旦別のポインタに入れてから操作する
    struct node *i = head1->next, *j = head2->next, *p = merge, *tmp;
    for (i = head1->next; i != NULL; i = tmp){
        for (j = head2->next; j != NULL; j = tmp){
            tmp = j->next;
            if (i->key > j->key){
                p->next = j;
                p = p->next;
                head2->next = tmp;
            }
        }
        tmp = i->next;
        p->next = i;
        p = p->next;
        head1->next = tmp;
    }
    p->next = head2->next;
    head2->next = NULL;
    return merge;
}

/****************************** main ********************************/
int main(void){
    int i;  //ループカウンタ
    int list_array1[9] = {1, 2, 3, 3, 4, 5, 7, 9, 10};  //設問の入力値
    int list_array2[10] = {1, 2, 5, 5, 6, 8, 9, 10, 11, 12};  //設問の入力値
    struct node oddhead0, evenhead0;  //ダミー
    struct node *oddhead=&oddhead0, *evenhead=&evenhead0; //先頭のポインタ
    struct node head1_p0, head2_p0;  //ダミー
    struct node *head1=&head1_p0, *head2=&head2_p0 ,*tmp; //先頭のポインタ
    list_initialize();  //headの初期化
    oddhead->next = NULL; //最後にNULLを入れておく
    evenhead->next = NULL;
    head1->next = NULL; //最後にNULLを入れておく
    head2->next = NULL;

    //c
    tmp = head1;
    for (i = 0; i < 9; i++){
    tmp = insert_after(list_array1[i], tmp);
    }
    tmp = head2;
    for (i = 0; i < 10; i++){
    tmp = insert_after(list_array2[i], tmp);
    }
    printf("list1:");
    print_whole_list_GP(head1);
    printf("list2:");
    print_whole_list_GP(head2);
    tmp = merge(head2, head1);
    printf("result ");
    print_whole_list_GP(tmp);
    return 0;
}