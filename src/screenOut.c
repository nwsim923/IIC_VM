#include"common.h"
#include"ItemData.h"

void ShowMenu(void)
{
	system("cls");

	printf(":::::메뉴::::: \n");
	printf("1. 신제품 추가 \n");
	printf("2. 전체제품출력 \n");
	printf("3. 제품 검색 \n");
	printf("4. 제품 수정 \n");
	printf("5. 종료 \n");
	printf(":::::::::::::: \n");
	printf("선택 >> ");
}

void ShowItemInfoByPtr(ItemData* Item)
{
	printf("::::::::::::::: \n");
	printf(":: 제품 : %s \n", Item->name);
	printf(":: 상품갯수 : %s \n", Item->number);
	printf(":: 상품가격 : %s \n", Item->cost);
	printf("::::::::::::::: \n");
}