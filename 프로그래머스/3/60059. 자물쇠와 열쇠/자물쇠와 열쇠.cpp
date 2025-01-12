#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &key, int m){
    vector<vector<int>> duplicate(m, vector<int>(m,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            duplicate[i][j]=key[i][j];
        }
    
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            key[j][m-1-i]=duplicate[i][j];
        }
}


bool check(vector<vector<int>> &all, vector<vector<int>> &lock, int m, int n){
 
    for(int i=m-1;i<m+n-1;i++){
        for(int j=m;j<m+n-1;j++){
            if(all[i][j]!=1)
                return false;
        }
    }
    return true;
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    int m=key.size();
    int n=lock.size();
    
    int nLen=2*m+n-2;
    //늘린 지도
    vector<vector<int>> all(nLen, vector<int>(nLen,0));
    

    //늘린 지도 값 채워넣기
    for(int i=m-1;i<m-1+n;i++){
        for(int j=m-1;j<m-1+n;j++){
            all[i][j]=lock[i-m+1][j-m+1];
       } 
    }
    
    for(int i=0;i<nLen-m+1;i++){
        for(int j=0;j<nLen-m+1;j++){
            
            for(int p=0;p<4;p++){
                rotate(key,m);
            
                for(int x=0;x<m;x++)
                    for(int y=0;y<m;y++){
                        all[i+x][j+y]+=key[x][y];
                    }
                //자물쇠 영역이 모두 1인지
                if(check(all, lock, m, n)){
                    return true;
                }
                for(int x=0;x<m;x++)
                    for(int y=0;y<m;y++){
                    all[i+x][j+y]-=key[x][y];
                    } 
                }
            }
        }
       
    return false;
}