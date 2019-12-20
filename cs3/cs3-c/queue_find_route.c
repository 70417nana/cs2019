#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "queue_find_route.h"

int startpoint_num = 0;
int goalpoint_num = 0;

stkque_t queue;
//課題cのために配列．今回は0のみ使用．
int stpnt_x[STGL_NUM], stpnt_y[STGL_NUM];
int glpnt_x[STGL_NUM], glpnt_y[STGL_NUM];

int get_x, get_y;

/**
 *  @fn     get_start_point  
 *  @brief  スタートの座標を取得する
 *  @param  width mapの幅
 *  @param  height mapの行数
 *  @param  map_array map本体
 *  @return なし
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

/**
 *  @fn     get_goal_point  
 *  @brief  ゴールの座標を取得する
 *  @param  width mapの幅
 *  @param  height mapの行数
 *  @param  map_array map本体
 *  @return なし
 */
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

/**
 *  @fn     queueinit 
 *  @brief  queueを初期化して空にする
 *  @return なし
 */
void queueinit(void){
    printf("%s\n", __func__);
    //head = tail = 0なら空
    queue.head.x = 0;
    queue.head.y = 0;
    queue.tail.x = 0;
    queue.tail.y = 0;
    printf("Init successful!\n");
}

/**
 *  @fn     put  
 *  @brief  queueに整数numを入れる
 *  @param  x mapのx座標
 *  @param  y mapのy座標
 *  @return なし
 */
void put(int x, int y){
    //末尾にnumを入れる
    queue.x_array[queue.tail.x] = x;
    queue.y_array[queue.tail.y] = y; 
    printf("put(%d, %d)\n", queue.x_array[queue.tail.x], queue.y_array[queue.tail.y]);   
    //末尾の要素番号インクリメント
    queue.tail.x++;
    queue.tail.y++;
}

/**
 *  @fn     get  
 *  @brief  queueから整数を1つ取り出す
 *  @return なし
 */
void get(void){
    //getした値を格納
    get_x = queue.x_array[queue.head.x];
    get_y = queue.y_array[queue.head.y];
    //先頭の要素番号インクリメント
    queue.head.x++;
    queue.head.y++; 
    printf("get(%d, %d)\n", get_x, get_y);
}

/**
 *  @fn     queueempty  
 *  @brief  queueが空かどうかを判定する
 *  @return 空：1   空でない：0
 */
int queueempty(void){
    //head = tailなら空
    if ((queue.head.x == queue.tail.x) || (queue.head.y == queue.tail.y)){
        printf("queue is empty!\n");
        return 1;
    } else {
        return 0;
    }
}

/**
 *  @fn     printRoute  
 *  @brief  探索悔過のマップを移動数3桁まで表示できる形で表示する
 *          ただしqueue専用でありstackでは流用できない
 *  @param  width mapの幅
 *  @param  height mapの行数
 *  @param  map_array map本体
 *  @param  goal goalまでの移動回数
 *  @return なし
 */
void printRoute(int width, int height, char map[][MAX + 2], char goal){
    int i, j;  //ループカウンタ
    int tmp_y;
    int tmp_map[MAX + 2][MAX + 2];
     //壁以外を空にする    
    printf("map empty\n");
    for(i = 0; i < height + 2; i++){
		for(j=0; j < width + 2; j++){
            if(map[i][j] != '+'){
                tmp_map[i][3 * j] = ' ';
                tmp_map[i][3 * j + 1] = ' ';
                tmp_map[i][3 * j + 2] = ' ';
            }else{
                tmp_map[i][3 * j] = ' ';
                tmp_map[i][3 * j + 1] = ' ';
                tmp_map[i][3 * j + 2] = '+';
            }
		}
	}
    i = goal - '0';  //初期化
    while (!queueempty()){
        get();
        tmp_y = 3 * get_y;
        if(i < 10){
            tmp_map[get_x][tmp_y] = ' ';
            tmp_map[get_x][tmp_y + 1] = ' ';
            tmp_map[get_x][tmp_y + 2] = '0' + i;
        } else if(i < 100){
            tmp_map[get_x][tmp_y] = ' ';
            tmp_map[get_x][tmp_y + 1] = '0' + (i / 10);
            tmp_map[get_x][tmp_y + 2] = '0' + (i - 10 * (i / 10));
        } else if(i < 1000){
            tmp_map[get_x][tmp_y] = '0' + (i / 100);
            tmp_map[get_x][tmp_y + 1] = '0' + ((i - 100 * (i / 100)) / 10);
            tmp_map[get_x][tmp_y + 2] = '0' + (i - 100 * (i / 100) - 10 * (i / 10));
        }
        i--;
    }
    //表示
    printf("result:\n");
    for(i = 0; i < height + 2; i++){
		for(j=0; j < 3 * (width + 2); j++){
			printf("%c", tmp_map[i][j]);
		}
		printf("\n");
	}
}

/**
 *  @fn     getMinGoal 
 *  @brief  最小ステップ数のゴールの座標がゴールの配列の何番目に入っているか
 *  @param  map_array map本体
 *  @return 最小要素番号
 */
int getMinGoal(char map[][MAX + 2]){
    int MinGoal = 0;
    int i;  //ループカウンタ
    for (i = 0; i < goalpoint_num; i++){
        if(map[glpnt_x[MinGoal]][glpnt_y[MinGoal]] > map[glpnt_x[i]][glpnt_y[i]]){
            MinGoal = i;
        }
    }
    printf("goal point:(%d, %d)  ",glpnt_x[MinGoal], glpnt_y[MinGoal]);
    printf("mingoal:%d\n", map[glpnt_x[MinGoal]][glpnt_y[MinGoal]]);
    return MinGoal;
}

/**
 *  @fn     findShortestRoute 
 *  @brief  最短経路探索
 *  @param  width mapの幅
 *  @param  height mapの行数
 *  @param  map_array map本体
 *  @return なし
 */
void findShortestRoute(int width, int height, char map[][MAX + 2]){
    int i, j;  //ループカウンタ
    char goaltmp; //あとで消しちゃうから入れておく
    int adj[5] = {0, 1, 0, -1, 0}; //5つめは1つめと同じ
    int pnt_x, pnt_y;
//かえたよ
    int minGoal = getMinGoal(map);
    pnt_x = glpnt_x[minGoal];
    pnt_y = glpnt_y[minGoal];
    goaltmp = map[glpnt_x[minGoal]][glpnt_y[minGoal]];
    put(glpnt_x[minGoal], glpnt_y[minGoal]);  //put goal point
//
    // pnt_x = glpnt_x[0];
    // pnt_y = glpnt_y[0];
    // goaltmp = map[glpnt_x[0]][glpnt_y[0]];
    // put(glpnt_x[0], glpnt_y[0]);
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
    printRoute(width, height, map, goaltmp);
}

/**
 *  @fn     findRoute 
 *  @brief  与えられたmapに対してスタートからゴールまでの経路を見つける
 *  @param  width mapの幅
 *  @param  height mapの行数
 *  @param  map_array map本体
 *  @return なし
 */
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
//かえたよ
    get_goal_point(width, height, map);      //goal座標の検出
//    
    queueinit();
    //スタート位置の設定
    for(i = 0; i < startpoint_num; i++){
        put(stpnt_x[i], stpnt_y[i]);
        map[stpnt_x[i]][stpnt_y[i]] = '1';
    }
    //経路探索
    while(!queueempty()){
        get();
//かえたよ
        for(i = 0; i < 4; i++){      
            //0なら座標をqueueにputしてから番号を振る
            if(((map[get_x + adj[i]][get_y + adj[i + 1]]) == '0') || ((map[get_x + adj[i]][get_y + adj[i + 1]]) == 'g')){
                put(get_x + adj[i], get_y + adj[i + 1]);
                map[get_x + adj[i]][get_y + adj[i + 1]] = map[get_x][get_y] + 1;
            }
        }
//
        // for(i = 0; i < 4; i++){      
        //     //0なら座標をqueueにputしてから番号を振る
        //     if((map[get_x + adj[i]][get_y + adj[i + 1]]) == '0'){
        //         put(get_x + adj[i], get_y + adj[i + 1]);
        //         map[get_x + adj[i]][get_y + adj[i + 1]] = map[get_x][get_y] + 1;
        //     }else if((map[get_x + adj[i]][get_y + adj[i + 1]]) == 'g'){
        //         put(get_x + adj[i], get_y + adj[i + 1]);
        //         map[get_x + adj[i]][get_y + adj[i + 1]] = map[get_x][get_y] + 1;
        //         glpnt_x[0] = get_x + adj[i];
        //         glpnt_y[0] = get_y + adj[i + 1];
        //         printf("goal point:(%d, %d)\n",glpnt_x[0], glpnt_y[0]);
        //         // return;
        //     }
        // }
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
