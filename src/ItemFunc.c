#include"common.h"
#include"ItemData.h"
#include"screenOut.h"
#include"ItemFunc.h"

#define LIST_NUM 50

int numOfData=0;//제품의 갯수
ItemData* ItemList[LIST_NUM];//구조체 ItemData로 아이템을 구성

void InputItemData(void)
{
	ItemData* pdata;
	int i;

	if(numOfData>=LIST_NUM)
	{
		puts("메모리 공간이 부족합니다.");
		return;
	}
	pdata = (ItemData*)malloc(sizeof(ItemData));

	fputs("제품 입력 : ", stdout);
	gets(pdata->name);

	printf("상품갯수 입력 : ");
	gets(pdata->number);

	ItemList[numOfData] = pdata;
	numOfData++;

	StoreDataToFileInStruct();

	puts("입력이 완료되었습니다.");
	getchar();
}

void ShowAllData(void)
{
	int i;
	for(i=0; i<numOfData; i++)
	{
		ShowItemInfoByPtr(ItemList[i]);
	}

	puts("출력이 완료되었습니다.");
	getchar();
}

void SearchItemData(void)
{
	int i;
	int searchSte=0;
	char searchName[NAME_LEN];
	fputs("찾는 제품은? ", stdout);
	gets(searchName);

	for(i=0; i<numOfData; i++)
	{
		if(!strcmp(ItemList[i]->name, searchName))
		{
			ShowItemInfoByPtr(ItemList[i]);
			searchSte = 1;
		}
	}
	if(searchSte == 0)
		puts("찾는 제품의 데이터가 검색되지 않았습니다.");
	else
		puts("검색을 완료했습니다.");
	getchar();
}

void ChangeItemData(void)
{
	int i;
	char searchName[NAME_LEN];
	char newItemNumber[NUM_LEN];

	int idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int selection = 0;
	int delIdx = 0;

	fputs("찾는 제품은? ", stdout);
	gets(searchName);

	for(i=0; i<numOfData; i++)
	{
		if(!strcmp(ItemList[i]->name, searchName))
		{
			idxOfMatchingData[matchedCount++] = i;
		}
	}
	if(matchedCount == 0)
	{
		puts("변경 대상 이름이 존재하지 않습니다.");
		getchar();
		return;
	}
	else if(matchedCount == 1)
	{
		delIdx = idxOfMatchingData[0];
	}
	else
	{
		for(i=0; i<matchedCount; i++)
		{
			printf("NUM. %d \n", i+1);
			ShowItemInfoByPtr(ItemList[idxOfMatchingData[i]]);
		}

		fputs("선택 : ", stdout);
		scanf("%d", &selection);
		fflush(stdin);

		delIdx=idxOfMatchingData[selection-1];
	}
	fputs("변경할 갯수는?", stdout);
	gets(newItemNumber);
	strcpy(ItemList[delIdx]->number, newItemNumber);

	StoreDataToFileInStruct();
	puts("변경 완료");
	getchar();
}

void StoreDataToFileInStruct(void)
{
	int i;

	FILE * fp = fopen("ItemDataStruct.dat", "wb");

	fwrite(&numOfData, sizeof(int), 1, fp);

	for(i=0; i<numOfData; i++)
	{
		fwrite(ItemList[i], sizeof(ItemData), 1, fp);
	}
	fclose(fp);
}

void LoadDataFromFileInStruct(void)
{
	int i;
	FILE * fp = fopen("ItemDataStruct.dat", "rb");
	if(fp == NULL)
		return;

	fread(&numOfData, sizeof(int), 1, fp);

	for(i=0; i<numOfData; i++)
	{
		ItemList[i] = (ItemData*)malloc(sizeof(ItemData));
		fread(ItemList[i], sizeof(ItemData), 1, fp);
	}
	fclose(fp);
}