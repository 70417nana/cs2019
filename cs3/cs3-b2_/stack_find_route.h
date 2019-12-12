#ifndef __S_FINDROUTE__
#define __S_FINDROUTE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

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

void stackinit(void);
void push(int x, int y);
void pop(void);
int stackempty(void);

void get_start_point(int width, int height, char map_array[][MAX + 2]);
void get_goal_point(int width, int height, char map_array[][MAX + 2]);
void foundRoute(int width, int height, char map[][MAX + 2]);
void findRoute(int width, int height, char map[][MAX + 2]);

#endif /*__S_FINDROUTE__*/