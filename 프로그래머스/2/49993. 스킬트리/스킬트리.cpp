#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int cnt=0;
    
    map<char,int> tree;
    for(int i=0;i<skill.length();i++){
        tree[skill[i]]=i;
    }
        
    for(int i=0;i<skill_trees.size();i++){
        string target=skill_trees[i];
        
        bool flag=true;
        int idx=0;
        for(int j=0;j<target.size();j++){
            if(tree.find(target[j])!=tree.end()){
                if(idx>tree[target[j]] || idx<tree[target[j]]){
                    flag=false;
                    break;
                }
                else if(idx==tree[target[j]])
                    idx=tree[target[j]]+1;
            }
        }
        if(flag){
            cnt++;
        }
    }
    
    return cnt;
}