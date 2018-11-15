# 洗衣机算法设计

通过“自顶而下，逐步求精”的编程方法研究洗衣机的算法设计。首先，我们先来了解一下“自顶向下，逐步求精”，是一种计算机编程使用的算法思想，顾名思义，这种方法的思想就是对现在遇到的复杂或者抽象化的问题，进行纵向深入分解并使其被分解为多个简单的、具体化的、可解决的问题。   
![](https://github.com/Tiantian0616/swi-homework/raw/gh-pages/images/top-down.jpg)

(1)    
将洗衣机的洗衣步骤根据“自顶而下，逐步求精”的方法，我们先初步的将洗衣机分为以下六步：   

**设置洗衣模式**

**注水**   

**洗衣**   

**排水**   
 
**脱水**    

**结束洗衣**

   

翻译出对应的伪代码:
```
GET INFORMATION  //设置洗衣模式

WATER IN  //注水

WASH  //洗衣

WATER OUT  //排水

DEHYDRATION  //脱水   

FINISHI //完成洗衣


```


(2)     
再将每一步细化成单个需要完成的动作    

**设置洗衣模式**   

获取 水位、洗衣时间、脱水时间    


**注水**   

判断洗衣机内水位是否小于标准值   
是：打开注水开关   
否：关闭注水开关   

**洗衣**   

重复   
转机向左转动十秒   
转机向右转动十秒   

直到达到标准洗衣时间   

**排水**   

判断洗衣机内水位是否大于零   
是：打开排水开关   
否：关闭排水开关   

**脱水**

重复   
转机向左转动十秒   
转机向右转动十秒   
直到达到标准脱水时间 

**完成洗衣**   



写出相应的伪代码
```
GET waterline,timeofwash,timeofwaterout  //获取 获取 水位、洗衣时间、脱水时间信息
WHILE get_water_volume < waterline   //判断洗衣机内水位是否达到标准
    water_in_switch(open)   //打开注水开关
ENDWHILE   
    water_in_switch(close)   //当洗衣机内水位高于标准水位时关闭注水开关

REPAET    
    motor_run(left)  for 10s  //滚筒向左向右交替转动十秒直到计时达到标准洗衣时间
    motor_run(right)  for 10s  
UNTILL
    time_counter == timeofwash

motor_run(stop) //时间到时转机停止

WHILE get_water_volume > 0   //判断洗衣机内水位是否大于0
    water_out_switch(open)  //洗衣机内水位大于零时打开排水开关
ENDWHILE
    water_out_switch(close)  //洗衣机内水位为零时关闭排水开关

REPAET    
    motor_run(left) for 10s   //滚筒向左向右交替转动十秒直到计时达到标准脱水时间
    motor_run(right)  for 10s 
UNTILL
    time_counter == timeofwaterout
motor_run(stop)   //时间到时转机停止

halt(success)  //结束洗衣
```