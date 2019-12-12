#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 50

int stpnt_x[10], stpnt_y[10];
int glpnt_x[10], glpnt_y[10];
int startpoint_num = 0;
int goalpoint_num = 0;

int get_x, get_y;

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

stkque_t queue;

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

// queueを初期化して空にする
void queueinit(void){
    printf("%s\n", __func__);
    //head = tail = 0なら空
    queue.head.x = 0;
    queue.head.y = 0;
    queue.tail.x = 0;
    queue.tail.y = 0;
    printf("Init successful!\n");
}

// queueに整数numを入れる
void put(int x, int y){
    //末尾にnumを入れる
    queue.x_array[queue.tail.x] = x;
    queue.y_array[queue.tail.y] = y; 
    printf("put(%d, %d)\n", queue.x_array[queue.tail.x], queue.y_array[queue.tail.y]);   
    //末尾の要素番号インクリメント
    queue.tail.x++;
    queue.tail.y++;
}

// queueから整数を1つ取り出す
void get(void){
    //getした値を格納
    get_x = queue.x_array[queue.head.x];
    get_y = queue.y_array[queue.head.y];
    //先頭の要素番号インクリメント
    queue.head.x++;
    queue.head.y++; 
    printf("get(%d, %d)\n", get_x, get_y);
}

// queueが空だったら非0の整数を返し，中身があったら0を返す．
int queueempty(void){
    //head = tailなら空
    if ((queue.head.x == queue.tail.x) || (queue.head.y == queue.tail.y)){
        printf("queue is empty!\n");
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
    put(glpnt_x[0], glpnt_y[0]);  //put goal point
    while (map[pnt_x][pnt_y] != '1'){
        for(i = 0; i < 4; i++){
            if(map[pnt_x + adj[i]][pnt_y + adj[i + 1]] == map[pnt_x][pnt_y] - 1){
                put(pnt_x + adj[i], pnt_y + adj[i + 1]);
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
    while (!queueempty()){
        get();
        map[get_x][get_y] = goaltmp - i;
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
    queueinit();
    //スタート位置の設定
    put(stpnt_x[0], stpnt_y[0]);
    map[stpnt_x[0]][stpnt_y[0]] = '1';
    //経路探索
    while(!queueempty()){
        get();
        for(i = 0; i < 4; i++){      
            //0なら座標をqueueにputしてから番号を振る
            if(((map[get_x + adj[i]][get_y + adj[i + 1]]) == '0') || ((map[get_x + adj[i]][get_y + adj[i + 1]]) == 'g')){
                put(get_x + adj[i], get_y + adj[i + 1]);
                map[get_x + adj[i]][get_y + adj[i + 1]] = map[get_x][get_y] + 1;
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