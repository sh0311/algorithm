#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int sol(vector<pair<int, int>>& ground){
    int max_hor=0;
    int max_ver=0;
    int max_hor_idx=0;
    int max_ver_idx=0;
    int target_hor=0;
    int target_ver=0;

    for(int i=0;i<6;i++) {
        if (ground[i].first == 1 || ground[i].first == 2) {
            max_hor=max(max_hor, ground[i].second);
        } else if (ground[i].first == 3 || ground[i].first == 4) {
           max_ver=max(max_ver, ground[i].second);
        }
    }

    for(int i=0;i<6;i++){
        int prev_idx=(i+5)%6;
        int next_idx=(i+1)%6;

        if (ground[i].first == 3 || ground[i].first == 4) {
            // target_ver 설정
            if (ground[prev_idx].second != max_hor && ground[next_idx].second != max_hor) {
                target_ver = ground[i].second;
            }
        } else if (ground[i].first == 1 || ground[i].first == 2) {
            // target_hor 설정
            if (ground[prev_idx].second != max_ver && ground[next_idx].second != max_ver) {
                target_hor = ground[i].second;
            }
        }

    }

    return max_hor*max_ver-target_hor*target_ver;
}


int main() {

    int k;
    cin>>k;
    vector<pair<int, int>> ground;

    for(int i=0;i<6;i++){
        int dir, len;
        cin>>dir>>len;

        ground.push_back(make_pair(dir, len));

    }

    int width=sol(ground);

    cout<<width*k;


    return 0;
}
