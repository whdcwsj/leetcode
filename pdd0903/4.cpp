#include<bits/stdc++.h>
using namespace std;

// vector<pair<int,int>>student_score;

// bool cmp(const pair<int,int>&a,const pair<int,int>&b){
//     if(a.second!=b.second){
//         return a.second>b.second;
//     }else{
//         return a.first<b.first;
//     }
// }


// int main(){
//     int n,shangxian,rank;
//     cin>>n>>shangxian>>rank;
//     for(int i=0;i<n;i++){
//         int id;
//         int score;
//         cin>>id>>score;
//         student_score.push_back(pair<int,int>(id,score));
//     }
//     int kaochang=ceil(double(n)*1.0/double(shangxian));
//     sort(student_score.begin(),student_score.end());
//     int count=0;
//     int temp=rank;
//     while(temp>kaochang){
//         count++;
//         temp-=kaochang;
//     }
//     //无剩余的
//     int rest;
//     if(temp==1){
//         rest=0;
//     }else{
        
//     }


//     system("pause");
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

int main() {
    double sum = 0;
    int n, c, r;
    cin >> n >> c >> r;
    vector<vector<int>> score(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> score[i][0] >> score[i][1];
    }
    sort(score.begin(), score.end(), [&](vector<int> i, vector<int> j) {
        if (i[1] == j[1])
            return i[0] < j[0];
        return i[1] > j[1];
    });
    int m = ceil(n * 1.0 / c);
    int start = (r - 1) / m * m;
    int end = start + c;
    for (int i = 0; i < start; ++i) {
        sum += score[i][1];
    }
    if (end >= n) {
        double res = sum / m + score[r - 1][1];
        res /= c;
        cout << fixed << setprecision(2) << res << endl;
    } else {
        for (int i = end; i < n / c * c; ++i) {
            sum += score[i][1];
        }
        double res = sum / m + score[r - 1][1];
        res /= c;
        cout << fixed << setprecision(2) << res << endl;
    }
    return 0;
}