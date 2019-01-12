# 贪吃蛇实验报告

下面是完整程序：
 [snake_move.c](snake_move.c)   
 [snake_eat.c](snake_eat.c)   
   

下面是实验过程：   


## 会动的蛇 

### (1)程序结构（伪代码）

```
输出字符矩阵
	WHILE not 游戏结束 DO
		ch＝等待输入
		CASE ch DO
		‘A’:左前进一步，break 
		‘D’:右前进一步，break    
		‘W’:上前进一步，break    
		‘S’:下前进一步，break    
		END CASE
		输出字符矩阵
	END WHILE
	输出 Game Over!!! 

```  
### (2)写出所需函数 和 全局变量
```c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20    // 给蛇的长度、身体、头部、食物、墙的构成做出定义
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void snakeMovedown();    // 蛇向下移动一步
void snakeMoveup();       // 蛇向上移动一步
void snakeMoveleft();     // 蛇向左移动一步
void snakeMoveright();      // 蛇向右移动一步
void put_money(void);     // 放出食物
void output(void);        // 输出游戏界面
void gameover(void);        // 显示游戏结束
void clean_screen();       // 清空屏幕
int if_wall(int );         // 判断是否撞墙

char map[12][12]=           
	{
	"************",
	"*XXXXH     *",
	"*          *",
	"*          *",
	"*          *",             // 游戏界面组成
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************"
	};
	
int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};      //蛇的坐标
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};
int snakelength = 5;       //蛇的长度
int flag = 1;         // 全局变量...QAQ用来辅助判断撞墙
```

### (3)写出 main 函数 

```c
int main(){
	
	output();	
	int i = 1;
	while(i){
		char ch;
		scanf("%c",&ch);
		
		int ch1 = ch;
		
		switch(ch1){
			case 'A':snakeMoveleft();break;
			case 'W':snakeMoveup();break;
			case 'D':snakeMoveright();break;
			case 'S':snakeMovedown();break;
		}
		
        if(snakelength > SNAKE_MAX_LENGTH || flag == 0){    //如果撞墙 结束游戏
			gameover();
			break;
		}
		
		clean_screen();
		output();
		
	}
		
}
```

### (4)给出函数定义

```c

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

void output(){
	
	int i,j;
	for(i = 0; i < 12; i ++){
		for(j = 0; j < 12; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
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
	
	map[snakeY[snakelength-1]][snakeX[snakelength-1]] = 'H';
	
	
	int i = 0;
	
	while(i < snakelength-2){		
	
		map[snakeY[snakelength-2-i]][snakeX[snakelength-2-i]] = 'X';
		i ++;
	}
	
	map[snakeY0][snakeX0] = ' '; 
	
}

```

## 会吃的蛇 

会吃的蛇比会动的蛇需要多出的内容：
(1)随机出现食物
(2)蛇头碰到食物，食物消失，蛇身变长



  