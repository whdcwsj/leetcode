#include<bits/stdc++.h>
using namespace std;

//题目：若当前数字大于下一个数字，则删除下一个数字
//使用单调递减栈

//1、元素x会被左边某个比他大的元素y给移除（如果存在的话）。
//我们需要计算在移除x之前，移除了多少个比y小的元素，从而算出移除x的时间（第几步操作）。

//2、注意移除操作是可以「接力」的，例如[9,1,2,3,4,1,5]
//5应该被9移除，所以在删除5之前，我们需要知道9到5之间的所有元素被移除的时间的最大值，从而算出移除5的时间。

//3、对于一串非降的序列（序列前有个更大的元素），该序列每个元素被删除的时间是单调递增的。
//利用这一单调性，只需要存储这串非降序列的最后一个元素被删除的时间，这些时间的最大值就是提示2中所需要计算的最大值。

//4、可以用一个单调递减栈存储元素及其被删除的时间，当遇到一个不小于栈顶的元素x时，就不断弹出栈顶元素，并取弹出元素被删除时间的最大值，这样就得到了提示2中所需要计算的时间的最大值maxT。
//然后将x及maxT+1入栈（如果此时栈为空，则说明前面没有比x大的元素，此时maxT=0，我们可以将x及0入栈）。


//时间复杂度：O(n)
//空间复杂度：O(n)
int totalSteps(vector<int>& nums) {
    int res=0;
    stack<pair<int,int>>s;
    for(auto num:nums){
        int maxT=0;
        //栈不为空，新的num≥栈顶元素
        //相当于每当出现非递减元素时，就进行迭代
        while(!s.empty() && num>=s.top().first){
            maxT=max(maxT,s.top().second);
            s.pop();
        }
        if(!s.empty()) maxT++;
        res=max(res,maxT);
        s.push(make_pair(num,maxT));
    }
    return res;
}


int main(){
    vector<int>nums = {5,3,4,4,7,3,6,11,8,5,11};
    // vector<int>nums = {4,5,7,7,13};
    // vector<int>nums ={10,1,2,3,4,5,6,1,2,3};

    int ans=totalSteps(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}