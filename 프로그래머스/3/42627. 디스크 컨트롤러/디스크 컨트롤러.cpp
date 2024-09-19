#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct order{
    bool operator()(vector<int> v1, vector<int>v2){      
        return v1[1]>v2[1];
    }
};


int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>, vector<vector<int>>, order> pq;
    
    sort(jobs.begin(),jobs.end()); //요청시간이 작은 순대로 sort
    
    int job_num=jobs.size();
    int j=0;  //다음으로 요청되는 작업번호
    int answer=0;
    
    int currentTime=0; //현재 시점
    int work=0; //작업 소요시간 누적
    
    while(j<job_num||!pq.empty()){
        if(pq.empty()){
            currentTime=jobs[j][0];
            pq.push(jobs[j++]);
        }
        
        work+=(currentTime-pq.top()[0])+pq.top()[1];
        currentTime+=pq.top()[1];
        
        pq.pop();
        
        while(j<job_num && jobs[j][0]<=currentTime){
            pq.push(jobs[j++]);
        }
    }
    answer=int(work/job_num);
    return answer;
}