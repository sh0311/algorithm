#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
set<int> tmp;

bool isPrime(int n){
    if(n<2)
        return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}

void make_combination(string current, string rest){
    
    if(current!=""){
        tmp.insert(stoi(current)); //01이랑 1이랑 같은 취급하기 위해 int형으로 변환해 저장
    }
    if(rest.empty()){
        return;
    }
                   
    for(int i=0;i<rest.size();i++){
        make_combination(current+rest[i],rest.substr(0,i)+rest.substr(i+1));
    }
}

int solution(string numbers) {
    int ans=0;
    
    make_combination("",numbers);
    
    for(auto t:tmp){
        if(isPrime(t))
            ans+=1;
    }
    
    return ans;
}