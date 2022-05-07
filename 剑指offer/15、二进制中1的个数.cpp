#include<bits/stdc++.h>
using namespace std;

//1、常规解法：输入的是二进制的数字，常用移位来处理
//时间复杂度 O(k)：k 为 int 的位数，固定为 32 位
//空间复杂度 O(1)：变量 cnt 使用常数大小额外空间
int hammingWeight(uint32_t n) {
    int count=0;
    while(n){
        if(n&1){
            count++;
        }
        //右边移位并赋值
        n>>=1;
    }
    return count;
}

//2、位运算
//与上面的基本上一样，唯一的区别，由flag来动，n不动
int hammingWeight(uint32_t n){
    int count=0;
    unsigned int flag=1;
    while(flag){
        if(n&flag){
            count++;
        }
        flag<<=1;
    }
    return count;
}