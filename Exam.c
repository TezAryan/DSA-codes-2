#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct player{
    char name[50];
    char teamname[50];
    float battingavg ;
};

int main(){

    struct player players[5];

    for(int i = 0 ; i < 5 ; i++){

        printf("Enter player name : ");
        scanf("%s" , &players[i].name);
        printf("Team name : ");
        scanf("%s", &players[i].teamname);
        printf("Enter avg . : ");
        scanf("%f", &players[i].battingavg);

    }

    for(int i = 0 ; i < 5 ; i++){

        printf("Enter player name : %s" , players[i].name);

        printf("Team name : %s" , players[i].teamname);

        printf("Enter avg . : %0.2f" , players[i].battingavg);


    }

    return 0;
}