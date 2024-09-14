#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <queue>

using namespace std;

int isSimilar(vector<char> wordList, string &candidate){
    int cnt=0;
    int i;
    for(i=0;i<candidate.length();i++){
        if(wordList.empty()){
            cnt+=candidate.length()-i;
            break;
        }
        //벡터에 있는 문자라면 삭제
        auto it=find(wordList.begin(), wordList.end(), candidate[i]);
        if(it!=wordList.end()){
            wordList.erase(it);
        }
        else{
            cnt+=1;
        }
    }
    if((wordList.empty() || wordList.size()==1 ) &&
    ((i==candidate.length()&&cnt<=1) || (cnt==1 && i==candidate.length()-1))){
        return 1;
    }
    else{
        return 0;
    }


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    string word, candidate;
    cin>>word;

    vector<char> wordList(word.begin(), word.end());


    int cnt=0;

    for(int i=0;i<n-1;i++){
        cin>>candidate;

        cnt+=isSimilar(wordList, candidate);
    }

    cout<<cnt;

}