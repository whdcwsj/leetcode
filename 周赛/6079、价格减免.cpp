#include<bits/stdc++.h>
using namespace std;


// string DoubleToStr(double num){
// 	ostringstream out;
// 	//设置精度
// 	//out.precision(2);
// 	out << num;
// 	return out.str();
// }

// string discountPrices(string sentence, int discount) {
//     int n=sentence.size();
//     string res="";
//     int i=0;
//     while(i<n){
//         if(sentence[i]=='$'){
//             int start=i;
//             i++;
//             while(stoi(sentence[i])){
//                 i++;
//             }
//             //出现$10$
//             if(sentence[i]=='$'){
//                 res+=sentence.substr(start,i-start+1);
//                 //跳过第二个$
//                 i++;
//             }
//             //单纯的后置$，一个数字都没有找到
//             else if(i-start==1){
//                 res+=sentence.substr(start,i-start);
//             }
//             else{
//                 string temp=sentence.substr(start+1,i-start-1);
//                 double num=(double)stoi(temp);
//                 num=num*(100-discount)/100.0;
//                 num=round(num*100)/100;
//                 res+=DoubleToStr(num);
//             }
//         }
//         else{
//             res+=sentence[i];
//             i++;
//         }
//     }
//     return res;
// }


//使用istringstream和getline来处理空格分隔的每个单词
//用ostringstream来处理输出数据的保留两位小数

string discountPrices(string sentence, int discount){
    string res;
    istringstream iss(sentence);
    string t;
    while(getline(iss,t,' ')){
        bool isPrice=false;
        if(t[0]=='$'){
            isPrice=true;
        }
        if(isPrice){
            for(int i=1;i<t.size();i++){
                //出现第二个$，或者非数字
                if(t[i]=='$' || t[i]<'0' || t[i]>'9'){
                    isPrice=0;
                    break;
                }
            }
        }

        //存在价格，要注意空$的排除
        if(isPrice && t.size()>1){
            string p=t.substr(1);
            double price=stod(p);
            price*=(100-discount)*0.01;

            ostringstream oss;
            oss<<fixed<<setprecision(2)<<price;
            
            res+='$'+oss.str()+' ';
        }else{
            res+=t+' ';
        }
    }
    //去除末尾的多余的一个空格
    res.pop_back();
    return res;
}



int main(){
    string sentence = "there are $1 $2 and 5$ candies in the shop";
    int discount = 50;
    string ans=discountPrices(sentence,discount);
    cout<<ans<<endl;

    system("pause");
    return 0;
}