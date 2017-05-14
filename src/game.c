/*
 *  Created on: 2017. 4. 12.
 *      Author: jjunney
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coin,com,usr;
int Choice;

int CardCom(void)
{

   srand((unsigned int)time(NULL));
   return rand()%13;
}
int Com(){
	srand((unsigned int)time(NULL));
	return rand()%100;
}

int ChoiceCard(void)
{
   printf("입력 ㄱ\n");
   scanf("%d",&Choice);
   if (Choice>13)//13넘어가면 종료
   return;

   return Choice;
}
int ChoiceOddEven(void){

   scanf("%d",&Choice);
   return Choice;
}


void resultCard(void){

     com=Com();
     usr=ChoiceCard();
     usr=ChoiceOddEven();

     if(com>usr)
        puts("com win");
     else if(com<usr)

        puts("you win");
     else
        puts("draw");

}

void resultOddEven(void){
   com=Com();
   usr=ChoiceOddEven();

    if(com%2==usr%2){
       puts("you win");
    	coin ++;
    }
     else
        puts("com win");

}


void write(void){
    FILE*fp=("data.dat","wb");
     if(fp==NULL){
        //puts("파일오픈 실패!");
           }
     fwrite((void*)&coin,sizeof(coin),1,fp);
     fclose(fp);

}

 int main() {


    ChoiceCard();
    ChoiceOddEven();
    write();

    resultCard();
    resultOddEven();
    write();
 }



