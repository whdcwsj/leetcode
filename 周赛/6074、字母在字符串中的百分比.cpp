#include<bits/stdc++.h>
using namespace std;


int percentageLetter(string s, char letter) {
    int n=s.size();
    float num=0;
    for(int i=0;i<n;i++){
        if(s[i]==letter){
            num++;
        }
    }
    cout<<"wang"<<endl;
    float res=num*100/n;
    return floor(res);
}



int main(){
    string s = "vmvvvvvzrvvpvdvvvvyfvdvvvvpkvvbvvkvvfkvvvkvbvvnvvomvzvvvdvvvkvvvvvvvvvlvcvilaqvvhoevvlmvhvkvtgwfvvzy";
    char letter = 'v';
    int ans=percentageLetter(s,letter);
    cout<<ans<<endl;

    system("pause");
    return 0;
}