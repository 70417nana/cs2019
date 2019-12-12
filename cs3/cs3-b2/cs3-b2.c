#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 50

int stpnt_x[10], stpnt_y[10];
int glpnt_x[10], glpnt_y[10];
int startpoint_num = 0;
int goalpoint_num = 0;

int pop_x, pop_y;

typedef struct{
    int x;
    int y;
} point_t;

typedef struct {
    point_t tail;    //データの数, 一番後ろの要素番号
    int x_array[MAX];
    int y_array[MAX];
    point_t head;   //スタックでは未使用
} stkque_t;

stkque_t stack;

/**
 *  @fn     get_start_point  
 * 
 */
void get_start_point(int width, int height, char map_array[][MAX + 2]){
    int i, j;   //ループカウンタ
    for (i = 1; i <= height; i++){
        for(j = 1; j <= width; j++){
            // sがある座標を探す
            if(map_array[i][j] == 's'){
                stpnt_x[startpoint_num] = i;
                stpnt_y[startpoint_num] = j;
                printf("start point: %d, %d\n", stpnt_x[startpoint_num], stpnt_y[startpoint_num]);
                startpoint_num ++;
            }
        }
    }
}
void get_goal_point(int width, int height, char map_array[][MAX + 2]){
    int i, j;   //ループカウンタ
    for (i = 1; i <= height; i++){
        for(j = 1; j <= width; j++){
            // sがある座標を探す
            if(map_array[i][j] == 'g'){
                glpnt_x[goalpoint_num] = i;
                glpnt_y[goalpoint_num] = j;
                printf("goal point: %d, %d\n", glpnt_x[goalpoint_num], glpnt_y[goalpoint_num]);
                goalpoint_num ++;
            }
        }
    }
}

// stackを初期化して空にする
void stackinit(void){
    printf("%s\n", __func__);
    //tail = 0なら空
    stack.tail.x = 0;
    stack.tail.y = 0;
    printf("Init successful!\n");
}

// stackに整数numを入れる
void push(int x, int y){
    //末尾にnumを入れる
    stack.x_array[stack.tail.x] = x;
    stack.y_array[stack.tail.y] = y; 
    printf("push(%d, %d)\n", stack.x_array[stack.tail.x], stack.y_array[stack.tail.y]);   
    //末尾の要素番号インクリメント
    stack.tail.x++;
    stack.tail.y++;
}

// stackから整数を1つ取り出す
void pop(void){
    //popした値を格納
    pop_x = stack.x_array[stack.head.x];
    pop_y = stack.y_array[stack.head.y];
    //先頭の要素番号インクリメント
    stack.head.x++;
    stack.head.y++; 
    printf("pop(%d, %d)\n", pop_x, pop_y);
}

// stackが空だったら非0の整数を返し，中身があったら0を返す．
int stackempty(void){
    //head = tailなら空
    if ((stack.head.x == stack.tail.x) || (stack.head.y == stack.tail.y)){
        printf("stack is empty!\n");
        return 1;
    } else {
        return 0;
    }
}

//最短経路表示関数
void findShortestRoute(int width, int height, char map[][MAX + 2]){
    int i, j;  //ループカウンタ
    char goaltmp = map[glpnt_x[0]][glpnt_y[0]]; //あとで消しちゃうから入れておく
    int adj[5] = {0, 1, 0, -1, 0}; //5つめは1つめと同じ
    int pnt_x = glpnt_x[0];
    int pnt_y = glpnt_y[0];
    push(glpnt_x[0], glpnt_y[0]);  //push goal point
    while (map[pnt_x][pnt_y] != '1'){
        for(i = 0; i < 4; i++){
            if(map[pnt_x + adj[i]][pnt_y + adj[i + 1]] == map[pnt_x][pnt_y] - 1){
                push(pnt_x + adj[i], pnt_y + adj[i + 1]);
                pnt_x = pnt_x + adj[i];
                pnt_y = pnt_y + adj[i + 1];
            }
        }
    }
    //壁以外を空にする    
    printf("map empty\n");
    for(i = 0; i < height + 2; i++){
		for(j=0; j < width + 2; j++){
            if(map[i][j] != '+'){
                map[i][j] = ' ';
            }
		}
	}
    i = 0;  //初期化
    while (!stackempty()){
        pop();
        map[pop_x][pop_y] = goaltmp - i;
        i++;
    }
    //表示
    for(i = 0; i < height + 2; i++){
		for(j=0; j < width + 2; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

//経路探索関数
void findRoute(int width, int height, char map[][MAX + 2]){//width:幅 height:高さ map[MAX]:要素
    int adj[5] = {0, 1, 0, -1, 0}; //5つめは1つめと同じ
	//表示開始
	int i,j;	
	for(i=0; i < height + 2; i++){
		for(j=0; j < width + 2; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	//表示終了

	//
	//経路探索アルゴリズムの実装部分    
    get_start_point(width, height, map);     //start座標の検出
    get_goal_point(width, height, map);      //goal座標の検出
    stackinit();
    //スタート位置の設定
    push(stpnt_x[0], stpnt_y[0]);
    map[stpnt_x[0]][stpnt_y[0]] = '1';
    //経路探索
    while(!stackempty()){
        pop();
        for(i = 0; i < 4; i++){      
            //0なら座標をstackにpushしてから番号を振る
            if(((map[pop_x + adj[i]][pop_y + adj[i + 1]]) == '0') || ((map[pop_x + adj[i]][pop_y + adj[i + 1]]) == 'g')){
                push(pop_x + adj[i], pop_y + adj[i + 1]);
                map[pop_x + adj[i]][pop_y + adj[i + 1]] = map[pop_x][pop_y] + 1;
            }
        }
        //表示
        for(i=0; i < height + 2; i++){
            for(j=0; j < width + 2; j++){
                printf("%c", map[i][j]);
            }
            printf("\n");
	    }
    }
    findShortestRoute(width, height, map);
}


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