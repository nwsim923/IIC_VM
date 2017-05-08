// Xcode ver

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//#include <Windows.h>

int money;

typedef struct item
{
    char name[20];
    int price;
    int qtr;
} item;

item items[4];


void PrintList ()
{
    printf("Xcode ver\n");
    puts("---------------------------------------------------\n");
    puts("자판기 물품\n");
    printf("1. %7s %5d원  남은수량 : %4d개\n", items[0].name, items[0].price, items[0].qtr);
    printf("2. %7s %5d원  남은수량 : %4d개\n", items[1].name, items[1].price, items[1].qtr);
    printf("3. %7s %5d원  남은수량 : %4d개\n", items[2].name, items[2].price, items[2].qtr);
    printf("4. %7s %5d원  남은수량 : %4d개\n", items[3].name, items[3].price, items[3].qtr);
    puts("---------------------------------------------------\n");
    printf("현재금액 : %d\n", money);
}

void ListToDo()
{
    puts("1. 동전투입\n");
    puts("2. 동전빼기\n");
    puts("3. 상품선택\n");
    puts("4. exit\n");
}

void InsertCoin()
{
    int moneyput;
    puts("InsertCoin입니다.");
    printf("원하는 금액을 입력하세요 : ");
    scanf("%d", &moneyput);
    printf("%d원 투입되었습니다.", moneyput);
    money+=moneyput;
    sleep(1);
}

void Refund()
{
    puts("Refund입니다.");
    printf("잔돈은 %d원입니다.", money);
    puts("잔돈이 모두 반환되었습니다.");
    money=0;
    sleep(1);
}

int choice (int item)
{
    int qt;
    
    printf("%s 몇 개를 주문하시겠습니까? : ", items[item-1].name);
    scanf("%d", &qt);
    
    if(qt>items[item-1].qtr)
        printf("죄송합니다. 재고가 부족합니다.\n");
    
    else if(money>=qt*items[item-1].price)
    {
        items[item-1].qtr-=qt;
        money-=(qt*items[item-1].price);
        printf("%s %d개 나왔습니다.\n", items[item-1].name, qt);
        printf("%d원 입니다.", qt*items[item-1].price);
    }
    
    else
        printf("금액이 %d원 부족합니다.", (items[item-1].price*qt)-money);
    
    return 0;
}

int Order()
{
    int order;
    puts("Order입니다.");
    printf("원하는 물건을 고르세요 : ");
    
    scanf("%d", &order);
    choice(order);
    
    
    sleep(1);
    return 0;
}



void user()
{
    int num;
    int roop=1;
    while(roop)
    {
        //system("cls");
        system("clear");
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
                printf("이용해주셔서 감사합니다.\n\n");
                roop=0;
                break;
        }
    }
}


void file_read ()
{
    
    FILE * fpp = fopen("data.txt", "rt");
    
    fscanf(fpp, "%s %d %d", items[0].name, &items[0].price, &items[0].qtr);
    fscanf(fpp, "%s %d %d", items[1].name, &items[1].price, &items[1].qtr);
    fscanf(fpp, "%s %d %d", items[2].name, &items[2].price, &items[2].qtr);
    fscanf(fpp, "%s %d %d", items[3].name, &items[3].price, &items[3].qtr);
    fscanf(fpp, "%d", &money);
    fclose(fpp);
}

void file_write()
{
    
    
    
    FILE * fp = fopen("data.txt", "wt");
    fprintf(fp, "%s %d %d\n", items[0].name, items[0].price, items[0].qtr);
    fprintf(fp, "%s %d %d\n", items[1].name, items[1].price, items[1].qtr);
    fprintf(fp, "%s %d %d\n", items[2].name, items[2].price, items[2].qtr);
    fprintf(fp, "%s %d %d\n", items[3].name, items[3].price, items[3].qtr);
    fprintf(fp, "%d", money);
    fclose(fp);
    
    
}

int main (void)
{
    file_read();
    
    printf("Xcode ver\n");
    
    user();
    
    file_write();
    
    return 0;
}
