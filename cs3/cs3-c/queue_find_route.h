#ifndef __Q_FINDROUTE__
#define __Q_FINDROUTE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define STGL_NUM  (MAX * MAX)

typedef struct{
    int x;
    int y;
} point_t;

typedef struct {
    point_t tail;    //データの数, 一番後ろの要素番号
    int x_array[MAX];
    int y_array[MAX];
    point_t head; 
} stkque_t;

void queueinit(void);
void put(int x, int y);
void get(void);
int queueempty(void);

void get_start_point(int width, int height, char map_array[][MAX + 2]);
void get_goal_point(int width, int height, char map_array[][MAX + 2]);
void findShortestRoute(int width, int height, char map[][MAX + 2]);
void findRoute(int width, int height, char map[][MAX + 2]);
void printRoute(int width, int height, char map[][MAX + 2], char goal);
int getMinGoal(char map[][MAX + 2]);

#endif /*__Q_FINDROUTE__*/