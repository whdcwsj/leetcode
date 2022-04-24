#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

// 一、插入排序
// 每次将一个待排序的记录，按其关键字大小插入到前面已经排好序的子序列中
// 排序n-1次
// 时间复杂度O(n^2)
void insertSort(int a[],int length){
    for(int i=1;i<length;i++){
        int j;
        int temp=a[i];
        //倒着排序，小的放前面
        for(j=i;temp<a[j-1] && j>0;j--){
            //元素移动，大的往后移
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
}

// 二、冒泡排序
// 每次遍历时，它都会从前往后依次的比较相邻两个数的大小；如果前者比后者大，则交换它们的位置。
// 最好的时间复杂度为O(n)。冒泡排序的最坏时间复杂度为O(n^2)。因此冒泡排序总的平均时间复杂度为O(n^2)。
// 算法适用于少量数据的排序，是稳定的排序方法
void bubbleSort(int a[],int length){
    bool flag;
    //比较趟数
    for(int i=0;i<length-1;i++){
        //这样相当于不断把最大的放在最后面
        flag=true;
        for(int j=0;j<length-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=false;
            }
        }
        if(flag) break;
    }
}


//三、选择排序
//基本思想：每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。
//选择排序是不稳定的排序方法。时间复杂度 O(n^2)。
//适用于的元素规模很大的序列，即移动操作十分耗时的操作
//该算法的移动操作比其他算法少
void selectSort(int a[],int length){
    int minIndex;
    for(int i=0;i<length-1;i++){
        minIndex=i;
        //每次找最小的数字和下标并记录
        for(int j=i;j<length;j++){
            if(a[j]<a[minIndex]){
                minIndex=j;
            }
        }
        //判断发生了交换
        if(minIndex!=i){
            swap(a[i],a[minIndex]);
        }
    }
}


//四、堆排序，实现一个最大堆
//最坏，最好，平均时间复杂度均为O(nlogn)
//不稳定排序
//把最大堆堆顶的最大数取出，将剩余的堆继续调整为最大堆，再次将堆顶的最大数取出，这个过程持续到剩余数只有一个时结束。
//1、堆构建函数
//index是当前节点的下标
void heapAdjust(int a[],int length,int index){
    //最大元素ID要作为堆顶元素
    int maxID=index;
    int left=index*2+1;
    int right=index*2+2;
    //找最大数字的ID
    if(left<length && a[left]>a[maxID]){
        maxID=left;
    }
    if(right<length && a[right]>a[maxID]){
        maxID=right;
    }
    if(maxID!=index){
        swap(a[maxID],a[index]);
        //递归调整子堆
        heapAdjust(a,length,maxID);
    }
}
//2、堆排序函数
void heapSort(int a[],int length){
    //建立堆，从每一个非叶子节点开始，从下往上构建
    for(int i=length/2-1;i>=0;i--){
        heapAdjust(a,length,i);
    }
    //从堆顶取出元素，同时不断调整最大堆
    for(int i=length-1;i>=1;i--){
        //最大的数放在最后面
        swap(a[0],a[i]);
        heapAdjust(a,i,0);
    }
}


//五、归并排序
//分治想法
//将待排序的数组分成前后两个部分，再递归的将前半部分数据和后半部分的数据各自归并排序，得到的两部分数据
//然后使用merge合并算法将两部分数组合并到一起。
//归并排序的最好、最坏和平均时间复杂度都是O(nlogn)，而空间复杂度是O(n)
//归并排序算法比较占用内存，但却是效率高且稳定的排序算法
void merge(int a[],int left,int mid, int right){
    int n=right-left+1;
    //暂存合并的有序数组
    int *temp=new int[n];
    //两个区域的第一个元素
    int i=left;
    int j=mid+1;
    //temp数组计数
    int k=0;
    while(i<=mid && j<=right){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
    //将排好序的结果返回原数组
    for(int i=left,k=0;i<=right;i++,k++){
        a[i]=temp[k];
    }
    //释放内存
    delete[]temp;
}

//不断递归
void mergeSort(int a[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}


//六、快速排序
// 如果数组S中元素是0或者1，则返回；
// 数组S中任一元素v，称之为枢纽元；
// 将S-{v}（S中剩余的元素）划分成连个不相交的集合：S1={S-{v}|x<=v}和S2={S-{v}|x>=v};
// 返回{quicksort(s1)}后跟v，继而返回{quicksort(S2)}。

//选取枢纽元（三数中值分割法）
//一般的做法是使用左端、右端和中心位置上的三个元素的中值作为基元。
//分割策略： 在分割阶段吧所有小元素移到数组的左边，大元素移到数组右边。大小是相对于枢纽元素而言的。
//当i在j的左边时，将i右移，移过小于枢纽元的元素，并将j左移，已过大于枢纽元的元素
//当i和j停止时，i指向一个大元素，而j指向一个小元素
//如果i在j的左边，那么将这两个元素交换，其效果是把一个大元素推向右边，而把小元素推向左边。

//快速排序平均时间复杂度为O(nlogn)，最坏情况为O(n^2)，n越大，速度越快。不是稳定的排序算法。

void quickSort3(int a[],int left,int right){
    if(left>=right) return;
    int i=left,j=right;
    //去最左边数值作为边界值
    int pivot=a[i];
    while(i<j){
        while(i<j && a[j]>=pivot){
            j--;
        }
        //i==j的话，就不动了
        if(i<j){
            a[i++]=a[j];
        }
        while(i<j && a[i]<=pivot){
            i++;
        }
        if(i<j){
            a[j--]=a[i];
        }
    }
    a[i]=pivot;
    quickSort3(a,left,i-1);
    quickSort3(a,i+1,right);
}



void quickSort(int a[],int left,int right){
    if(left<right){
        //初始化左右指针i,j，以及枢纽元，取最左边的数值
        int i=left;
        int j=right;
        //这是当前时间为随机数种子
        srand(time(0));
        int rad=rand()%(right-left+1)+left;
        // int pivot=a[i];
        int pivot=a[rad];
        while(i<j){
            //从右到左找第一个比基准值小的数A[j]
            while(i<j && a[j]>pivot){
                j--;
            }
            //判断此时是否要++，因为此时可能i==j，即数组右边的数字都比枢纽元大
            if(i<j){
                //将a[j]放入a[i];
                a[i++]=a[j];
            }
            //从左到右找第一个比基准值大的数
            while(i<j && a[i]<pivot){
                i++;
            }
            //判断此时是否要--，可能此时已经i==j
            //例如[5,1,2]
            if(i<j){
                //把a[j]放入a[i]
                a[j--]=a[i];
            }
        }
        a[i]=pivot;
        quickSort(a,left,i-1);
		quickSort(a,i+1,right);
    }
}

//这个是可以用的
//这个写法更为便捷
void quickSort2(int a[],int left,int right){
	if(left >= right)
		return;
	int i=left, j=right;
    //不指定的话会产生伪随机数，每次都是相同的随机数
    srand(time(0));
    int rad=rand()%(right-left+1)+left;
    swap(a[rad],a[left]);
    int pivot=a[left];  //取最左边的数为基准数
    int temp;
	while (i<j)
	{   
        //从右到左找第一个小于基准值的数字
        //注意大于等于
		while (i<j && a[j]>=pivot)
			j--;
        //从左到右找第一个大于基准值的数字
        //注意小于等于
		while (i<j && a[i]<=pivot)
			i++;
		if(i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	//基准数归位 ，多了一步在这里
	a[left] = a[i];
	a[i] = pivot;

    // for(int i=0;i<6;i++){
	// 	cout<<a[i]<<" ";
	// }
    // cout<<endl;
	quickSort2(a, left, i - 1); //递归左边
	quickSort2(a, i + 1, right); //递归右边
}


int main(){
    
	// int a[]={210,25,49};
    // int a[]={25,8,49,21,16,25};
    int a[]={3,2,1,5,6,4};
	// insertSort(a,6); 
    // bubbleSort(a,6);
    // selectSort(a,6);
    // heapSort(a,6);
    // mergeSort(a,0,5);
    // quickSort(a,0,2);
    quickSort2(a,0,5);
    // quickSort3(a,0,2);
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

    system("pause");
    return 0;
}