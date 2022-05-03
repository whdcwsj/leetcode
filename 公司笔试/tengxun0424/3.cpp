#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    int a,b,c;
    vector<double>res;
    double y1;
    double y2;
    double A,B,C;
    double x;
    while(q--){
        cin>>a>>b>>c;
        double left=0.0;
        double right=1000.0;
        double temp;
        while(left<right){
            double mid=left+(right-left)/2.0;
            temp=mid*mid*mid+a*mid*mid+b*mid;
            if(abs(c-temp)<1e-7){
                res.push_back(mid);
                cout<<"haha"<<endl;
                break;
            }else if(c-temp>=1e-7){
                left=mid;
            }else if(temp-c>=1e-7){
                right=mid;
            }
            cout<<mid<<endl;
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<fixed << setprecision(8)<<res[i]<<endl;
    }

    system("pause");
    return 0;
}