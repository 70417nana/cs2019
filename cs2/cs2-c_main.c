#include "stdio.h"
#include "stdlib.h"
#include "cs2-c.h"

/****************************** main ********************************/

int main(void){
  int i;  //ループカウンタ
  int list_array[10] = {8, 12, 1, 8, 10, 0, 5, 3, 8, 4};  //設問の入力値
  struct node oddhead0, evenhead0;  //ダミー
  struct node *oddhead=&oddhead0, *evenhead=&evenhead0; //先頭のポインタ
  struct node head1_p0, head2_p0;  //ダミー
  struct node *head1=&head1_p0, *head2=&head2_p0; //先頭のポインタ
  list_initialize();  //headの初期化
  oddhead->next = NULL; //最後にNULLを入れておく
  evenhead->next = NULL;
  head1->next = NULL; //最後にNULLを入れておく
  head2->next = NULL;

  //ソート・挿入
  for (i = 0; i < 10; i++){
      if (insert_sorted_list(list_array[i]) == 1){
          printf("already inserted: %d\n", list_array[i]);
      } else {
          printf("inserted: %d\n", list_array[i]);
      }
      //現時点でのリストの表示
      print_whole_list();
  }

  #ifdef SBJ_2B2  //課題2
  delete_all(); //全消去関数の呼び出し
  print_whole_list(); //リストの表示
  #endif  /* SBJ_2B2 */

  #ifdef SBJ_2B3  //課題3
  delete(10);
  print_whole_list();  //リストの表示
  delete(7);
  print_whole_list();  //リストの表示
  delete(1);
  print_whole_list();  //リストの表示
  #endif  /* SBJ_2B3 */

  #ifdef SBJ_2B4
  oddeven(head, oddhead, evenhead);

  //奇数リストの表示
  printf("odd:");
  for (oddhead=oddhead->next; oddhead!=NULL; oddhead=oddhead->next){
    printf("%d -> ",oddhead->key); 
  }
  printf("\n");

  //偶数リストの表示
  printf("even:");
  for (evenhead=evenhead->next; evenhead!=NULL; evenhead=evenhead->next){
    printf("%d -> ",evenhead->key); 
  }
  printf("\n");
  #endif  /* SBJ_2B4 */

  //c
  for (i = 0; i < 5; i++){
    // insert_after(list_array[i], head1);
    // insert_after(list_array[i+5], head2);
    // head1 = head1->next;
    // head2 = head2->next;
    insert_list_GP(list_array[i], head1);
    insert_list_GP(list_array[i+5], head2);
    //現時点でのリストの表示
    printf("list1:");
    for (head1=head1->next; head1!=NULL; head1=head1->next){
        printf("%d -> ",head1->key); 
    }
    printf("\n");

    printf("list2:");
    for (head2=head2->next; head2!=NULL; head2=head2->next){
        printf("%d -> ",head2->key); 
    }
    printf("\n");

    printf("list_func:");
    print_whole_list_GP(head2);
    print_whole_list_GP(head);
  }

  return 0;
}