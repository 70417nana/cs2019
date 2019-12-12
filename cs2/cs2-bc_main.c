#include "stdio.h"
#include "stdlib.h"
#include "cs2-bc.h"

int main(void){
  int i;
  int list_array[10] = {8, 12, 1, 8, 10, 0, 5, 3, 8, 4};
  struct node oddhead0, evenhead0;
  struct node *oddhead=&oddhead0, *evenhead=&evenhead0;
  list_initialize();
  oddhead->next = NULL;
  evenhead->next = NULL;
  for (i = 0; i < 10; i++){
      if (insert_sorted_list(list_array[i]) == 1){
          printf("already inserted: %d\n", list_array[i]);
      } else {
          printf("inserted: %d\n", list_array[i]);
      }
      print_whole_list();
  }
  // delete(10);
  // print_whole_list();  
  // delete(7);
  // print_whole_list();  
  // delete(1);
  // print_whole_list();  
  // delete_all();
  // print_whole_list();
  
  oddeven(head, oddhead, evenhead);
  printf("odd:");
  for (oddhead=oddhead->next; oddhead!=NULL; oddhead=oddhead->next){
    printf("%d -> ",oddhead->key); 
  }
  printf("\n");

  printf("odd:");
  for (evenhead=evenhead->next; evenhead!=NULL; evenhead=evenhead->next){
    printf("%d -> ",evenhead->key); 
  }
  printf("\n");
  return 0;
}