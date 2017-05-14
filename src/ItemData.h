#ifndef __ITEMDATA_H__
#define __ITEMDATA_H__

#define NAME_LEN 30
#define NUM_LEN 30
#define COST_NUM 30

typedef struct __ItemData
{
	char name[NAME_LEN];
	char number[NUM_LEN];
	char cost[COST_NUM];
}ItemData;

#endif