#include"common.h"
#include"ItemData.h"

void ShowMenu(void)
{
	system("cls");

	printf(":::::�޴�::::: \n");
	printf("1. ����ǰ �߰� \n");
	printf("2. ��ü��ǰ��� \n");
	printf("3. ��ǰ �˻� \n");
	printf("4. ��ǰ ���� \n");
	printf("5. ���� \n");
	printf(":::::::::::::: \n");
	printf("���� >> ");
}

void ShowItemInfoByPtr(ItemData* Item)
{
	printf("::::::::::::::: \n");
	printf(":: ��ǰ : %s \n", Item->name);
	printf(":: ��ǰ���� : %s \n", Item->number);
	printf(":: ��ǰ���� : %s \n", Item->cost);
	printf("::::::::::::::: \n");
}