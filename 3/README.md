# 3

## 题目描述

在Linux Shell命令下通配符'*'表示0个或多个字符, 现编写一段代码实现通配符'*'的功能，注意只需要实现'*', 不用实现其他通配符。

# 输入描述:

第一行输入通配字符串

第二行输入要匹配查找的字符串

# 输出描述:

输出所有匹配的字串起始位置和长度，每行一个匹配输出

如果不匹配，则输出 -1 0

如果有多个按照起始位置和长度的正序输出。

# 示例1

## 输入

shopee*.com

shopeemobile.com

## 输出

0 16

## 说明

0 起始位置，16长度

# 示例2

## 输入

*.com

shopeemobile.com

## 输出

0 16

1 15

2 14

3 13

4 12

5 11

6 10

7 9

8 8

9 7

10 6

11 5

12 4

# 示例3

## 输入

o*m

shopeemobile.com

## 输出

2 5

2 14

7 9

14 2