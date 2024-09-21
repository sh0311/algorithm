#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int friend_num=friends.size();
    
    map<string, int> friend_dict; //이름을 인덱스로 표현하기 위해 (muzi를 0으로, ryan을 1로,...)
    vector<vector<int>> gift_table(friend_num,vector<int>(friend_num,0)); //주고받은 선물 표
    
    vector<int> gift_score(friend_num,0);  //선물지수
    
    vector<int> total_gift(friend_num,0);  //최종적으로 받는 선물 갯수
    
    for(int i=0;i<friend_num;i++){
        friend_dict[friends[i]]=i;
    }
    
    for(string gift : gifts){
        string a,b;
        
        stringstream ss(gift);  // gift 문자열을 stream으로 반환
        ss>>a>>b;   //문자열을 공백 기준으로 분리
        
        gift_table[friend_dict[a]][friend_dict[b]]++;
        gift_score[friend_dict[a]]++;
        gift_score[friend_dict[b]]--;
     }
    
    // 각자 받는 선물 갯수 계산
    for(int i=0;i<friend_num;i++){
        for(int j=0;j<friend_num;j++){
            if(i==j)
                continue;
            // 둘이 점수 다른 경우
            if(gift_table[i][j]!=gift_table[j][i]){
                if(gift_table[i][j]>gift_table[j][i])
                    total_gift[i]+=1;
            }
            // 둘이 점수 같은 경우(선물지수)
            else if(gift_table[i][j]==gift_table[j][i]){
                if(gift_score[i]>gift_score[j]){
                    total_gift[i]+=1;
                }
                else
                    continue;
            }
        }
    }
    
    int max_value=*max_element(total_gift.begin(), total_gift.end());

    return max_value;
}