# 大鱼吃小鱼游戏设计技术博客

## 游戏策划
首先，我决定制作一个简单的大鱼吃小鱼的游戏，该游戏应该实现主角鱼可以吃掉比自己小的鱼，也会被比自己大的鱼吃掉，并且吃掉不同大小的鱼时主角鱼可以获得相应的加分。

### 1.设计形象
使用电脑自带的画图画几种不同的小鱼作为游戏的元素。
![](https://github.com/Tiantian0616/swi-homework/raw/gh-pages/images/画鱼.png)
### 2.插入元素
依次插入背景，主角鱼和其他几种鱼。
![](https://github.com/Tiantian0616/swi-homework/raw/gh-pages/images/放置元素.png)
### 3.为各种元素设置行为
1.主角鱼:   
(1)可由键盘控制主角鱼游动   
(2)不能游出游戏界面
![](https://github.com/Tiantian0616/swi-homework/raw/gh-pages/images/元素行为.png
)
2.其他鱼   
(1)分别能以不同的速度游动

### 4.设置事件
如图所示
![](https://github.com/Tiantian0616/swi-homework/raw/gh-pages/images/events.png
)
### 5.运行游戏展示   
![](https://github.com/Tiantian0616/swi-homework/raw/gh-pages/images/游戏展示.gif
)

## 游戏设计

object：主角鱼   
attribute：![](https://github.com/Tiantian0616/swi-homework/raw/master/images/yourfish.png)
collaborator：精灵   
events & actions：    
1)碰撞小鱼 & 加分      
2)碰撞大鱼 & 消失   
3)键盘操纵 & 移动        

object：小鱼   
attribute：   
![](https://github.com/Tiantian0616/swi-homework/raw/gh-pages/images/yellow%20fish.png)   

![](https://github.com/Tiantian0616/swi-homework/raw/gh-pages/images/green%20fish.png)   

collaborator：精灵   
events & actions：    
1)碰撞主角鱼 & 消失      
2)每隔一段时间 & 随机出现新的小鱼   
                    


object:大鱼   
attribute:   
![](https://github.com/Tiantian0616/swi-homework/raw/gh-pages/images/big%20fish.png)   
collaborator:精灵   
events & actions：   
1)碰撞主角鱼 

