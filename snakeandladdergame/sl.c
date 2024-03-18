#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

//The below function is used to generate the random dice value it will return a random number from 1 to 6

int randm(){
   
    int a;
   a= (rand()%6)+1;
   return a;
}


int main(){

//the below array named snakehead if the player points is equal to the snakes head it decreases the points to the snake tail 
    int snakehead[]={14,27,36,49,51,58,63,67,75,79,80,84,91,97};//13
    int snaketail[]={2,3,7,11,16,20,25,29,33,37,45,65,74,83};//13
    //the maximum  points to win the game
    int maxpoints=100;
    //playermaxpoints and player1 and layer2 are assigned to zero
    int playermaxpoints=0,player1=0,player2=0;


             srand(time(0));
         //   printf("%d\n",random());
           while(1){
            int choice,dice;
            //if the player points is less than 100 the player can resume play else the game is over 
                    if(playermaxpoints<100){
                            printf("Enter 1 for player1 turn or 2 for player2 turn : ");
                            //1 for player1 turn or 2 for player2 turn
                            scanf("%d",&choice);
                            if(choice==1){
                                dice=randm();
                                //random dice is stored in the dice variable
                                printf("Player1 is playing......\n");
                                sleep(2);//time interval for 2 seconds
                                printf("Dice is rolled \n");
                                printf("Value of the rolled dice is %d\n",dice);
                                //dice is added with the player points
                                player1+=dice;
                                for(int i=0; i<14; i++){
                                    //if the player points is equal to the snakehead the snake tail value is assign to the player
                                    if(player1==snakehead[i]){
                                        player1=snaketail[i];
                                    }
                                }
                                printf("Player1 points %d\n",player1);
                                printf("Player2 points %d\n",player2);
                                if(player1<player2){
                                    playermaxpoints=player2;
                                }else{
                                    playermaxpoints=player1;
                                }
                            }else if(choice==2){
                                dice=randm();  //random dice is stored in the dice variable
                                printf("Player2 is playing......\n");
                                printf("Dice is rolled\n ");
                                printf("Value of the rolled dice is %d\n",dice);
                                player2+=dice;  //dice is added with the player points
                                for(int i=0; i<14; i++){
                                    //if the player points is equal to the snakehead the snake tail value is assign to the player 
                                    if(player2==snakehead[i]){
                                        player2=snaketail[i];
                                    }
                                }
                                printf("Player1 points %d\n",player1);
                                printf("Player2 points %d\n",player2);
                                //which player having highest points that points will stored in the playermaxpoints
                                if(player1<player2){
                                    playermaxpoints=player2;
                                }else{
                                    playermaxpoints=player1;
                                }
                            }else{
                                printf("Enter th correct choice 1 or 2\n");
                            }

                    }else{
                            printf("-------------------------------------------\n");
                            //if the player1 reached 100 points the game will ended and terminated  else player2 is considered as winner
                            if(player1>=100){
                                printf("Player1 is th winner\n");
                            }else{
                                printf("Player2 is te winner\n");
                            }
                            printf("GAME OVER . . . . . . . . .\n ");
                            break;
                    }
           }

    return 0; 
}
