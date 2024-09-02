#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sosu(int n){
    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;

    for(int i=2;i<=sqrt(n);i++)
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i)
                is_prime[j]=false;
        }
    return is_prime;
}
void gold(int n, vector<bool>& is_prime){
    int a=0,b=0;

    //2는 짝수라 합이 짝수되려면 나머지 수도 짝수라 소수 아님
    for(int i=3;i<=n/2;i++){
        if(is_prime[i]&&is_prime[n-i]){
            a=i;
            b=n-i;
            break;
        }
    }
    cout<<n<<" = "<<a<<" + "<<b<<'\n';
}


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> vec;

    while(true){
       cin>>n;

       if(n==0)
           break;
        vec.push_back(n);
   }

    int max=*max_element(vec.begin(), vec.end());
    vector<bool> is_prime=sosu(max); //제일 큰 n으로 한번만 구하기

    for(int num:vec)
        gold(num, is_prime);




}




