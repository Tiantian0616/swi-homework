# 贪吃蛇实验报告

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

```

### (3)写出 main 函数 

  