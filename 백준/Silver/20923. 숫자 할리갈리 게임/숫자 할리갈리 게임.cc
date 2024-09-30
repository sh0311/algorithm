#include <iostream>
#include <vector>
#include <queue>


using namespace std;

string solve(deque<int> &dosu, deque<int> &su, int m){
    //그라운드에 놓인 카드더미
    deque<int> d_tmp;
    deque<int> s_tmp;

    int game=0;

    bool dodoTurn=true;

    while(true) {

        if (dodoTurn) {
            d_tmp.push_back(dosu.back());
            dosu.pop_back();
        } else {
            s_tmp.push_back(su.back());
            su.pop_back();
        }


        if (dosu.empty()) {
            return "su";
        }
        if (su.empty()) {
            return "do";
        }


        if (!d_tmp.empty() && d_tmp.back() == 5 || !s_tmp.empty() && s_tmp.back() == 5) {
            while (!s_tmp.empty()) {
                dosu.push_front(s_tmp.front());
                s_tmp.pop_front();
            }
            while (!d_tmp.empty()) {
                dosu.push_front(d_tmp.front());
                d_tmp.pop_front();
            }
        } else if (!s_tmp.empty() && !d_tmp.empty() && (d_tmp.back() + s_tmp.back()) == 5) {
            while (!d_tmp.empty()) {
                su.push_front(d_tmp.front());
                d_tmp.pop_front();
            }
            while (!s_tmp.empty()) {
                su.push_front(s_tmp.front());
                s_tmp.pop_front();
            }
        }
        game += 1;

        if (game >= m){
            if(dosu.size()>su.size()){
                return "do";
            }
            else if(dosu.size()<su.size()){
                return "su";
            }
            else{
                return "dosu";
            }

        }
        dodoTurn=!dodoTurn;

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    deque<int> dosu;
    deque<int> su;

    for(int i=0;i<n;i++){
        int d, s;
        cin >> d >> s;
        dosu.push_back(d);
        su.push_back(s);
    }

    string res=solve(dosu, su, m);

    cout<<res;
}
