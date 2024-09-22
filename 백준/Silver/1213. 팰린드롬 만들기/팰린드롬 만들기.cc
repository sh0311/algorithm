#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

string palindrom(vector<char> word){

    string result="";

    map<char, int> word_dict;
    for(int i=0;i<word.size();i++){
        if(word_dict.find(word[i]) != word_dict.end()) {
            word_dict[word[i]]++;  // 이미 있으면 증가
        } else {
            word_dict[word[i]] = 1;  // 없으면 추가
        }
    }

    // string 길이가 짝수일때
    if(word.size()%2==0){
        // 각 단어가 모두 짝수개 존재해야 펠린드롬수 될수있다
        for(auto itr:word_dict){
            if(itr.second%2==1){
                return "I'm Sorry Hansoo";
            }
        }
    }

    // string 길이가 홀수일 때
    if(word.size()%2==1){
        // 한 글자만 소수갯수이고 나머지는 짝수여야 팰린드롬수 될수있다
        int cnt=0;
        for(auto itr:word_dict){
            if(cnt==2){
                return "I'm Sorry Hansoo";
            }
            if(itr.second%2==1){
                cnt++;
            }
        }
    }
    char tmp;
    bool isHolsu=false;
    //팰린드롬 처리
    for(auto itr:word_dict){
        if(itr.second%2==1){
            tmp=itr.first;
            isHolsu=true;
        }
        int num=itr.second/2;
        while(num--){
            result=result+(itr.first);
        }
    }
    string temp=result;
    if(isHolsu){
        result=result+tmp;
        reverse(temp.begin(),temp.end());
        result=result+temp;
    }
    else{
        reverse(temp.begin(),temp.end());
        result=result+temp;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string name;
    cin>>name;

    vector<char> word(name.length());

    for(int i=0;i<name.length();i++){
        word[i]=name[i];
    }

    string res=palindrom(word);

    cout<<res;


}
