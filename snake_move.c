
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void snakeMovedown();
void snakeMoveup();
void snakeMoveleft();
void snakeMoveright();
void put_money();
void output();
void gameover();
void clean_screen();
int if_wall(int ); 


char map[12][12]=
	{
	"************",
	"*XXXXH     *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************"
	};
	
int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};
int snakelength = 5;
int flag = 1;

int main(){
	
	output();	
	
	while(1){
		
		char ch;
		scanf("%c",&ch);
		
		int ch1 = ch;
		
		switch(ch1){
			case 'A':snakeMoveleft();break;
			case 'W':snakeMoveup();break;
			case 'D':snakeMoveright();break;
			case 'S':snakeMovedown();break;
		}
		
		if(snakelength > SNAKE_MAX_LENGTH || flag == 0){
			gameover();
			break;
		}
		
		clean_screen();
		output();
		
	}
	
	
}

int if_wall(int a){
	
	int ret;
	
	if(a == 0 || a == 11){
		ret = 1;
	}
	else ret = 0;
	
	return ret;
}

void output(void){
	
	int i,j;
	for(i = 0; i < 12; i ++){
		for(j = 0; j < 12; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}

void gameover(){
	printf("Gameover!!\n");
}

void clean_screen(){
	system("cls");
}

void snakeMovedown(){
	
	
	int j = 0;
	int snakeX0 = snakeX[j];
	int snakeY0 = snakeY[j];
	for(j = 0; j < snakelength - 1; j ++){
		snakeY[j] = snakeY[j+1];
		snakeX[j] = snakeX[j+1];
	}
	
	snakeY[snakelength-1] ++;
	
	if(if_wall(snakeY[snakelength-1])){
		flag = 0;
	}
	map[snakeY[snakelength-1]][snakeX[snakelength-1]] = 'H';
	
	
	int i = 0;
	
	while(i < snakelength-2){		
	
		map[snakeY[snakelength-2-i]][snakeX[snakelength-2-i]] = 'X';
		i ++;
	}
	
	map[snakeY0][snakeX0] = ' '; 
}

void snakeMoveup(){
	
	
	int j = 0;
	int snakeX0 = snakeX[j];
	int snakeY0 = snakeY[j];
	for(j = 0; j < snakelength - 1; j ++){
		snakeY[j] = snakeY[j+1];
		snakeX[j] = snakeX[j+1];
	}
	
	snakeY[snakelength-1] --;
	
	if(if_wall(snakeY[snakelength-1])){
		flag = 0;
	}
	
	map[snakeY[snakelength-1]][snakeX[snakelength-1]] = 'H';
	
	
	int i = 0;
	
	while(i < snakelength-2){		
	
		map[snakeY[snakelength-2-i]][snakeX[snakelength-2-i]] = 'X';
		i ++;
	}
	
	map[snakeY0][snakeX0] = ' '; 
	
}

void snakeMoveright(){
	
	
	int j = 0;
	int snakeX0 = snakeX[j];
	int snakeY0 = snakeY[j];
	for(j = 0; j < snakelength - 1; j ++){
		snakeY[j] = snakeY[j+1];
		snakeX[j] = snakeX[j+1];
	}
	
	snakeX[snakelength-1] ++;
	
	if(if_wall(snakeX[snakelength-1])){
		flag = 0;
	}
	
	map[snakeY[snakelength-1]][snakeX[snakelength-1]] = 'H';
	
	
	int i = 0;
	
	while(i < snakelength-2){		
	
		map[snakeY[snakelength-2-i]][snakeX[snakelength-2-i]] = 'X';
		i ++;
	}
	
	map[snakeY0][snakeX0] = ' '; 
	
}

void snakeMoveleft(){
	
	
	int j = 0;
	int snakeX0 = snakeX[j];
	int snakeY0 = snakeY[j];
	for(j = 0; j < snakelength - 1; j ++){
		snakeY[j] = snakeY[j+1];
		snakeX[j] = snakeX[j+1];
	}
	
	snakeX[snakelength-1] --;
	
	if(if_wall(snakeX[snakelength-1])){
		flag = 0;
	}
	
	map[snakeY[snakelength-1]][snakeX[snakelength-1]] = 'H';
	
	
	int i = 0;
	
	while(i < snakelength-2){		
	
		map[snakeY[snakelength-2-i]][snakeX[snakelength-2-i]] = 'X';
		i ++;
	}
	
	map[snakeY0][snakeX0] = ' '; 
	
}





