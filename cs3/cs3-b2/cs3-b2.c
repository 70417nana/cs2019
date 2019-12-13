#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stack_find_route.h"
#include "int_to_char.h"

int main(int argc, char* argv[]){//argc:引数の個数 argv:引数の文字列配列
	char map[MAX + 2][MAX + 2];//要素
	int width,height;//幅,高さ
	int i;	
	if(argc <= 1){//コマンドラインからの入力がない場合
		width = 5;
		height = 5;
        strcpy(map[0], "+++++++");
        strcpy(map[1], "+0s000+");
        strcpy(map[2], "+00000+");
        strcpy(map[3], "+0000++");
        strcpy(map[4], "+00000+");
        strcpy(map[5], "+0000g+");
        strcpy(map[6], "+++++++");
	}else{//コマンドラインからの入力がある場合
		//入力が正しいという前提
		height = argc - 1;
		width = strlen(argv[1]);
		for(i = 0; i < height; i++){
			strcpy(map[i], argv[i+1]);
		}
	}

	//経路探索関数
	findRoute(width, height, map);

	return 0;
}