#include <iostream>
#include <algorithm> //sort 사용하기 위한 헤더
#include <vector>
#include <cmath>

using namespace std;

int sumThat(int col, int row, vector<vector<int>>& arr, int n){
    if (col <= 0 || col >= n-1 || row <= 0 || row >= n-1) return 200 * 15; // 경계 밖이면 불가능한 값 반환
    return arr[col][row]+arr[col][row+1]+arr[col][row-1]+arr[col-1][row]+arr[col+1][row];
}

int solution(vector<vector<int>>& arr, int n){
    int result=200*15; //최대 가격
    for(int i=n+1;i<=(n+1)*(n-2);i++){
            int col=i%n;
            int row=i/n;
            int sum1=sumThat(col, row, arr, n);
            for(int j=i+1;j<=(n+1)*(n-2);j++){
                if((abs(j%n-col)+abs(j/n-row))>2){
                    int col2=j%n;
                    int row2=j/n;
                    int sum2=sumThat(col2, row2, arr, n);
                    for(int k=j+1;k<=(n+1)*(n-2);k++){
                        if((abs(k%n-col2)+abs(k/n-row2))>2 && (abs(k%n-col)+abs(k/n-row))>2){
                            int col3=k%n;
                            int row3=k/n;
                            int sum3=sumThat(col3, row3, arr, n);
                            result=min(result, sum1+sum2+sum3);
                        }
                    }
                }
            }
        }
    return result;

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int>(n,0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];

    int res=solution(arr, n);

    cout<<res;
}