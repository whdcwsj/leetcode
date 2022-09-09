#include<bits/stdc++.h>
using namespace std;



//举个例子19/2,19大于2，也大于4(2*2^(1))，也大于8(2*2^(2))，也大于16(2*2^(3)),但是小于32(2*2^(4))
//于是将19-16得到3，并记录此时的答案8，此时被除数变为3，除数还是2
//重复上述结果得到此时答案为1，剩下被除数1，已经小于 2，最终结果为 8 + 1 = 9。
//这样，算法复杂度为 O(logn)。

//整数相除，求商。不用乘，除，取余

// unsigned int divideCore(int a,int b);
// int divide(int a, int b) {
//     //除法结果溢出，返回2^31-1
//     if(a==INT_MAX && b==-1){
//         return INT_MAX;
//     }
//     if(a==INT_MIN && b==-1){
//         return INT_MAX;
//     }
//     //负数，转换为正数，存在溢出问题
//     //因此采用负数进行除法的运算
//     int negative=2;
//     if(a>0){
//         negative--;
//         a=-a;
//     }
//     if(b>0){
//         negative--;
//         b=-b;
//     }
//     unsigned int res=divideCore(a,b);
//     return negative==1?-1*res:res;
// }


// //十进制负数转化为16进制
// unsigned int divideCore(int a,int b){
//     unsigned int num=0;
//     //a,b均为负数,a<=b，就是可以继续除
//     while(a<=b){
//         int value=b;
//         unsigned int wang=1;
//         //正数的补是它本身；负数的补码是它本身的值每位求反,最后再加一。
//         //例如:求-3的十六进制
//         //3的十六进制为0003，3求反之后是C，再加1，成D，所以-3的十六进制就是：FFFD
//         //0xc0000000 是十进制 -2^30 的十六进制的表示
//         while(value>=0xc0000000 && a<=value+value){
//             //记录有几个b
//             wang+=wang;
//             value+=value;
//         }
//         num+=wang;
//         a-=value;
//     }
//     return num;
// }


int divide(int a,int b){
    if(a==INT_MIN && b==-1) return INT_MAX;
    //异或操作
    int sign=(a>0)^(b>0)?-1:1;
    //负数进行处理
    if(a>0) a=-a;
    if(b>0) b=-b;
    int res=0;
    //a,b均为负数,a<=b，就是可以继续除
    while(a<=b){
        int value=b;
        int k=1;
        while(value>=0xc0000000 && a<=value+value){
            value+=value;
            // 代码优化：如果 k 已经大于最大值的一半的话，那么直接返回最小值
            if (k > INT_MAX / 2) return INT_MIN;
            k+=k;
        }
        a-=value;
        res+=k;
    }
    return sign==1?res:-res;
}



int main(){
    int a = 15, b = 2;
    int ans=divide(a,b);
    cout<<ans<<endl;

    system("pause");
    return 0;
}