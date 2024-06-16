#include<stdio.h>
int main(){
    char one='1';
    char two='2';
    char three='3';
    char four='4';
    char five='5';
    char six='6';
    char seven='7';
    char eight='8';
    char nine='9';
    char player1[100];
    char player2[100];
    char player[100];
    char winner[100];
    char playsign;
    char playsign1='O';
    char playsign2='X';
    int number;
    int time=0;
    int select_numbers[9];
    int check;
    int size;
    int wintime;
    int enter_number[100];

    printf("Enter Player 1 name:");
    scanf("%s",player1);
    printf("Enter Player 2 name:");
    scanf("%s",player2);

    printf("\n\t|==========================================================|\n");
    printf("\t|%s Your Symbull is O and %s Your symboll is X.\n",player1,player2);
    printf("\t|%s You will start the game\n",player1);
    printf("\t|==========================================================|\n\n\n");

    printf("\t|-----|-----|-----|\n");
    printf("\t|  1  |  2  |  3  |\n");
    printf("\t|-----|-----|-----|\n");
    printf("\t|  4  |  5  |  6  |\n");
    printf("\t|-----|-----|-----|\n");
    printf("\t|  7  |  8  |  9  |\n");
    printf("\t|-----|-----|-----|\n\n");

    while(time<9){
        if(time%2==0){
            playsign=playsign1;
            strncpy(player,player1,100);
        }else{
            playsign=playsign2;
            strncpy(player,player2,100);
        }
        while(1){
            check=1;
            while(1){
                printf("%s Enter a slot number to place %c :",player,playsign);
                scanf("%s",enter_number);
                if(check_numeric(enter_number)){
                    number=atoi(enter_number);
                    //printf("\n%d\n",number);
                    break;
                }else{
                    printf("\n\t============================\n");
                    printf("\tPlease enter only numbers...\n");
                    printf("\t============================\n\n");
                }
            }

            select_numbers[time]=number;
            if(number>=1 && number<=9){
                for(int i=0;i<time;i++){
                    if(number==select_numbers[i]){
                        //printf("\nuse\n");
                        check=0;
                    }
                }

            }else{
                printf("\n\t================================\n");
                printf("\tPlease enter 1-9 numbers only...\n");
                printf("\t================================\n\n");
                check=2;
            }
            if(check==1){
                break;
            }else if(check==2){

            }else{
                printf("\n\t=====================================================\n");
                printf("\tUse this slot before.please enter another number.....\n");
                printf("\t=====================================================\n\n");
            }
        }



        switch(number){
            case 1:
                one=playsign1;
                break;
            case 2:
                two=playsign;
                break;
            case 3:
                three=playsign;
                break;
            case 4:
                four=playsign;
                break;
            case 5:
                five=playsign;
                break;
            case 6:
                six=playsign;
                break;
            case 7:
                seven=playsign;
                break;
            case 8:
                eight=playsign;
                break;
            case 9:
                nine=playsign;
                break;

            //default:printf("a month is not available.");
        }
        time++;



        printf("\n\t|-----|-----|-----|\n");
        printf("\t|  %c  |  %c  |  %c  |\n",one,two,three);
        printf("\t|-----|-----|-----|\n");
        printf("\t|  %c  |  %c  |  %c  |\n",four,five,six);
        printf("\t|-----|-----|-----|\n");
        printf("\t|  %c  |  %c  |  %c  |\n",seven,eight,nine);
        printf("\t|-----|-----|-----|\n\n");

        if((one==two && two==three) || (four==five && five==six) || (seven==eight && eight==nine) || (one==four && four==seven) || (two==five && five==eight) || (three==six && six==nine) || (one==five && five==nine) || (three==five && five==seven) ){
            strncpy(winner,player,100);
            wintime=1;
            break;

        }

    }
    if(wintime==1){
        printf("\n\n\t================================\n");
        printf("\t\t%s win the game\n",winner);
        printf("\t================================\n\n");
    }else{
        printf("\n\n\t============================\n");
        printf("\t\tTie the game\n");
        printf("\t============================\n\n");
    }

    delay(10);

    return 0;
}
int check_numeric(char name[100]){
    int len=strlen(name);
    //printf("length=%d",len);
    for(int i=0;i<len;i++){
        if(!isdigit(name[i])){
            return 0;
        }
    }
    return 1;

}
void delay(int numOfSec)
{
	int numOfMilliSec = 1000 * numOfSec;
	time_t startTime = clock();
	while(clock() < startTime + numOfMilliSec);
}


