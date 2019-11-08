#include <stdio.h>
#define SIZE 256

int array[SIZE] = {};
int elements = 0;

//配列の中身を出力するための関数
void printArray(){
    int i;
    for (i = 0; i < elements; i++){
        printf("%4d,", array[i]);
    }
    printf("\n");
}


//小さい順に並び変えるための関数
void sortArray(){
    int i, j, tmp;
    for (i = 0; i < elements; i++){
        for (j = i+1; j < elements; j++){
            if (array[j] < array[i]){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}


/**
 * @fn      insert_sorted_list
 * @brief   それまでに探索された整数全種類を小さい順に整数列配列に格納する
 * @param   整数値key
 * @return  keyが探索されたことがない：0  
 *          keyが探索されたことがある：1
 * */
int insert_sorted_list(int key){
    int i; 
    for (i = 0; i < elements; i++){
        if (array[i] == key){
            sortArray();
            printArray();
            return 1;
        }
    }
    array[elements] = key;
    elements++;
    sortArray();
    printArray();
    return 0;
}

int main(void){
    int num;
    int IsContinue = 1;
    //終了が選択されるまで繰り返す
    while(IsContinue){
        //整数値keyを入力させる
        printf("Enter an integer      :");
        scanf("%d",&num);
        insert_sorted_list(num);
        //続行するか終了するかを聞く
        printf("Continue? Yes:1 No:0  :");
        scanf("%d",&IsContinue);
    }
    return 0;
}