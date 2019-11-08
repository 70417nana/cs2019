#include<stdio.h>

int main(){
	int row, col;	//col:列 row:行

	printf("1問目\n");
/**
*	1. 行ごとに列でforループをまわす
*	2. 行×列の計算結果を出力する
**/
	for(row=1;row<10;row++){
		for(col=1;col<row+1;col++){
			printf("%3d",row*col);
		}
	printf("\n");
	}

	printf("2問目\n");
/**
*	1. 行ごとに列でforループをまわす
*	2. 行の値が列の値以下なら行×列の計算結果を出力する
*	   そうでないなら半角スペースを3つ出力する
**/
	for(row=1;row<10;row++){
		for(col=1;col<10;col++){
			if(row<=col){
				printf("%3d",row*col);
			}else{
				printf("   ");
			}
		}
		printf("\n");
	}
	return 0;
}