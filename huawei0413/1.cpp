#include<bits/stdc++.h>
#include<sstream>
using namespace std;

struct service{
    int id;
    int cpuNum;
    int memoryNum;
    int structure;
    int NPfast;
}services[1001];

//cpu优先
bool cmp1(service a,service b){
    if(a.cpuNum!=b.cpuNum){
        return a.cpuNum<b.cpuNum;
    }else{
        if(a.memoryNum!=b.memoryNum){
            return a.memoryNum<b.memoryNum;
        }else{
            return a.id<b.id;
        }
    }
}
//内存优先
bool cmp2(service a,service b){
    if(a.memoryNum!=b.memoryNum){
        return a.memoryNum<b.memoryNum;
    }else{
        if(a.cpuNum!=b.cpuNum){
            return a.cpuNum<b.cpuNum;
        }else{
            return a.id<b.id;
        }
    }
}

//检测服务器是否满足条件
bool check(service a,int cpuset,int memoryset,int structureset,int NPset){
    if(a.cpuNum<cpuset){
        return false;  
    } 
    if(a.memoryNum<memoryset){
        return false;
    }
    if(a.structure!=structureset && structureset!=9){
        return false;
    }
    if(a.NPfast!=NPset && NPset!=2){
        return false;
    }
    return true;
}

bool cmp3(int a,int b){
    return a<b;
}


int main(){
    int m;
    cin>>m;
    int num=0;
    // int inputID,inputCPU,inputMemory,inputStructure,inputNP;
    string s;
    vector<string>record;
    while(m--){
        cin>>s;
        stringstream ss(s);
        string temp;
        record.clear();
        while(getline(ss,temp,',')){
            record.push_back(temp);
        }
        // cin>>inputID>>inputCPU>>inputMemory>>inputStructure>>inputNP;
        services[num].id=stoi(record[0]);
        services[num].cpuNum=stoi(record[1]);
        services[num].memoryNum=stoi(record[2]);
        services[num].structure=stoi(record[3]);
        services[num].NPfast=stoi(record[4]);
        num++;
    }
    int maxfenpei,strategy,cpuCount,memSize,cpuArch,supportNP;
    cin>>maxfenpei>>strategy>>cpuCount>>memSize>>cpuArch>>supportNP;
    vector<service>wang;
    for(int i=0;i<num;i++){
        if(check(services[i],cpuCount,memSize,cpuArch,supportNP)){
            wang.push_back(services[i]);
        }
    }
    if(strategy==1){
        sort(wang.begin(),wang.end(),cmp1);
    }else{
        sort(wang.begin(),wang.end(),cmp2);
    }
    int wang_size=wang.size();
    // cout<<"wang"<<wang_size<<endl;
    int maxlength=min(maxfenpei,wang_size);

    if(maxlength==0) cout<<"0";
    else{
        vector<int>shuchu;
        for(int j=0;j<maxlength;j++){
            shuchu.push_back(wang[j].id);
        }
        sort(shuchu.begin(),shuchu.end(),cmp3);
        cout<<maxlength<<" ";
        for(int j=0;j<maxlength;j++){
            cout<<shuchu[j];
            if(j<maxlength-1) cout<<" ";
        }
    }

    system("pause");
    return 0;
}

