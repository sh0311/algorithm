#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int play(vector<char>& vec, int change, char alph, int idx){
    idx+=change;
    idx%=vec.size();
    if(vec[idx]!='?'&&vec[idx]!=alph){
            vec[0]='!';
            return -1;
    }

    vec[idx]=alph;
    return idx;
}

void output(int idx, int room, vector<char>& vec){

    if(vec[0]=='!'){
        cout<<"!";
        return;
    }
    for(int i=0;i<room-1;i++){
        for(int j=i+1;j<room;j++){
            if(vec[i]==vec[j]&&vec[i]!='?'){
                cout<<"!";
                return;
            }
        }
    }

    for(int i=0;i<room;i++){
        cout << vec[idx];
        idx = (idx - 1 + room) % room;
    }
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int room, turn, change;
    cin>>room>>turn;

    char alph;

    vector<char> vec(room,'?');
    int idx=0;

    for(int i=0;i<turn;i++){
        cin>>change>>alph;
        idx=play(vec, change, alph,idx);
        if(idx==-1){
            break;
        }
    }

    output(idx, room, vec);
}




