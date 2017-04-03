//상규 첫번째 소스

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


void PrintList ()
{
	puts("---------------------------------------------------\n");
	puts("현 재고량\n");
	puts("1. 콜라   --개\n");
	puts("2. 사이다 --개\n");
	puts("3. 환타   --개\n");
	puts("---------------------------------------------------\n");
}

void ListToDo()
{
	puts("1. 동전투입\n");
	puts("2. 동전빼기\n");
	puts("3. 상품선택\n");
	puts("4. printlist\n");
	puts("5. listtodo\n");
	puts("6. exit\n");
}


void user()
{
	int num;
	int roop=1;
	while(roop)
	{

		system("cls");
		PrintList();
		ListToDo();

		printf("원하는 작업을 선택하세요 : ");
		scanf("%d", &num);

		switch(num)
		{
		case 1:
			InsertCoin();
			break;

		case 2:
			Refund();
			break;

		case 3:
			Order();
			break;

		case 4:
			PrintList();
			break;

		case 5:
			ListToDo();
			break;

		case 6:
			printf("이용해주셔서 감사합니다.\n\n");
			roop=0;
			break;
		}
	}
}

int InsertCoin()
{
	puts("InsertCoin입니다.");
	Sleep(2000);
	return 0;
}

int Refund()
{
	puts("Refund입니다.");
	Sleep(2000);
	return 0;
}

int Order()
{
	puts("Order입니다.");
	Sleep(2000);
	return 0;
}

int main (void)
{

	user();

	return 0;
}
