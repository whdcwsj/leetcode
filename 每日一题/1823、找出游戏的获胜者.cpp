#include<bits/stdc++.h>
using namespace std;

//1、flag数组记录
// int findTheWinner(int n, int k) {
//     if(n==1) return 1;
//     vector<bool>flag(n,1);
//     int num=0;
//     int i=0;
//     int count;
//     while(true){
//         count=0;
//         while(true){
//             if(flag[i]==1){
//                 count++;
//                 if(count==k){
//                     break;
//                 }
//                 i=(i+1)%n;
//             }else{
//                 i=(i+1)%n;
//             }
//         }
//         flag[i]=0;
//         // cout<<"删除的元素:"<<endl;
//         // cout<<i<<endl;
//         num++;
//         while(true){
//             i=(i+1)%n;
//             if(flag[i]==1){
//                 break;
//             }
//         }
//         // cout<<"新的开始："<<endl;
//         // cout<<i<<endl;
//         if(num==n-1){
//             break;
//         }
//     }
//     return i+1;
// }


//2、队列+模拟
//时间复杂度：O(nk)
//空间复杂度：O(n)
int findTheWinner(int n, int k){
    queue<int>q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(q.size()>1){
        //将队首元素取出并将该元素在队尾处重新加入队列，重复该操作k−1次
        for(int i=1;i<k;i++){
            q.push(q.front());
            q.pop();
        }
        //此时队首元素就是要弹出的
        q.pop();
    }
    return q.front();
}



//3、约瑟夫环（数学+递归）
//约瑟夫环的范围[0,n-1]
//f(n, m)表示，n个人报数，每报到m时杀掉那个人，返回最终胜利者的编号
//因为每次淘汰之后，数组会往左偏移k个位置，相当于-m，你退的时候要+m
//公式：f(n,m)=(f(n-1,m)+m)%n


//时间复杂度：O(n)，空间复杂度：O(n)
int f(int n,int m){
    if(n==1) return 0;
    return (f(n-1,m)+m)%n;
}

//进一步迭代优化空间
//时间复杂度：O(n)，空间复杂度：O(1)
int f(int n,int m){
    //最后剩下一个人的情况时胜利者的下标是0
    int f=0;
    //开始逆推
    for(int i=2;i<=n;i++){
        f=(f+m)%i;
    }
    return f;
}

int findTheWinner(int n, int k){
    return f(n,m)+1;
}




int main(){
    int n=1;
    int k=1;
    int ans=findTheWinner(n,k);
    cout<<ans<<endl;

    system("pause");
    return 0;
}