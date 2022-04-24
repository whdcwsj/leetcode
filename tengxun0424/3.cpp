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
                left=mid+0.000000001;
            }else if(temp-c>=1e-7){
                right=mid-0.000000001;
            }
            cout<<mid<<endl;
        }
        // C=b*b;
        // B=a*b;
        // A=B*B-3*b;
        // y1=A*a+3*((-B+sqrt(B*B-4*A*C))/2.0);
        // cout<<y1<<endl;
        // cout<<pow(abs(y1),1.0/3)<<endl;
        // y2=A*a+3*((-B-sqrt(B*B-4*A*C))/2.0);
        // cout<<y2<<endl;
        // cout<<pow(abs(y2),1.0/3)<<endl;
        // x=(-a+pow(abs(y1),1.0/3)+pow(abs(y2),1.0/3))/3.0;
        // res.push_back(x);
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }

    system("pause");
    return 0;
}