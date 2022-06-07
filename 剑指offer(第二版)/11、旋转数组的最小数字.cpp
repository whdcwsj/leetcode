#include <bits/stdc++.h>
using namespace std;

// int minArray(vector<int>& numbers) {
//     return *min_element(numbers.begin(),numbers.end());
// }

//二分查找，时间复杂度O(log n)
//以数组的最右边作为分隔点
int minArray(vector<int> &numbers)
{
    if (numbers.size() == 1)
        return numbers[0];
    int left = 0;
    int right = numbers.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        //最小值在左边区域
        if (numbers[mid] < numbers[right])
        {
            right = mid;
        }
        else if (numbers[mid] > numbers[right])
        {
            left = mid + 1;
        }
        //相同的情况，存在重复元素，肯定有最小值，也是循环跳出的判断条件
        else
        {
            right--;
        }
    }
    return numbers[left];
}

int main()
{
    //vector<int> numbers = {3,4,5,1,2};
    vector<int> numbers = {3, 1, 3};
    int ans = minArray(numbers);
    cout << ans << endl;

    system("pause");
    return 0;
}