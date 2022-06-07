#include <bits/stdc++.h>
using namespace std;

//为了时间效率
//查找元素插入位置O(logN)（二分查找）、向数组某位置插入元素O(N)（插入位置之后的元素都需要向后移动一位）
//借助堆可进一步优化时间复杂度。

//建立两个堆：小顶堆(保存较大的一半)和大顶堆(保存较小的一半)
//这样每次在较大数字中的小顶堆寻找，在较小数字中的大顶堆寻找

//查找中位数O(1):获取堆顶元素使用O(1)时间
//添加数字O(logN):堆的插入和弹出操作使用O(logN)时间
//空间复杂度O(N)


//最大堆，保存小的数字
priority_queue<int,vector<int>,less<int>>maxHeap;
//最小堆，保存大的数字
priority_queue<int,vector<int>,greater<int>>minHeap;

MedianFinder()
{

}

//数字不是直接插入，需要调整后再插入
//相当于最次，大顶堆长度先增加，小顶堆长度在增加
void addNum(int num)
{   
    //长度相同时，现在最小堆插入，比较完后，插入最大堆
    if(maxHeap.size()==minHeap.size()){
        minHeap.push(num);
        int top=minHeap.top();
        minHeap.pop();
        maxHeap.push(top);
    }
    else{
        maxHeap.push(num);
        int top=maxHeap.top();
        maxHeap.pop();
        minHeap.push(top);
    }
}

double findMedian()
{
    if(maxHeap.size()==minHeap.size()){
        return (maxHeap.top()+minHeap.top())*1.0/2.0;
    }else{
        return maxHeap.top()*1.0;
    }
}