#include<bits/stdc++.h>
using namespace std;


int main(){
// "SA SK SQ SJ S10 H10 C9"


    system("pause");
    return 0;
}

    int pow(int x,int n, int mod){
        x=x%mod;
        int res=1;
        while(n){
            if(n%2){
                res=(long long)res*x%mod;
            }
            x=(long long)x*x%mod;
            n/=2;
        }
        return res;
    }
    
    int Decrypt(int encryptedNumber, int decryption, int number){
        int ans=1;
        string b=to_string(decryption);
        int n=b.size();
        for(int i=n-1;i>=0;i--){
            ans=(long long)ans*pow(encryptedNumber,b[i],number)%number;
            encryptedNumber=pow(encryptedNumber,10,number);
        }
        return ans;
    }