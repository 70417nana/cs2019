#include "stdio.h"
#include "stdlib.h"
#include "cs2-c.h"


//------------- 検証用オプション ---------------//
/*  検証する課題以外はコメントアウト
    コメントアウトされていない課題が実行される
 */

#define SBJ_2B1   //課題2b-1
// #define SBJ_2B2   //課題2b-2
// #define SBJ_2B3   //課題2b-3
// #define SBJ_2B4   //課題2b-4

//---------------------------------------------//

// struct node{
//     int key;           //ノードの中に入っているデータ部分
//     struct node *next; //次のノードのアドレス
// };

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

// struct node *merge(struct node *head1, struct node *head2){
  
// }
