#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int find_candidate(vector<int> v,int visited[]){ // finds the next topic with maximum points, which isn't not already visited and not consecutive to any visited topic. 
    int ans = INT_MIN;
    int value = INT_MIN;
    for(int i=0; i < v.size(); i++){
        if(v[i] > value && visited[i] == 0){
            ans = i;
            value = v[i];
        }
    }
    return ans;
}

int Solve(vector<int> v){
    int total_pts{};
    int visited[v.size()]= {0};
    for(int i=0; i < v.size(); i++){
        int temp = find_candidate(v,visited);
        if(temp<0){//when no topic is left which can be visited, find_candidate function will return initializing value which is INT_MIN, which will be stored in temp.
            return total_pts;
        }
        
        total_pts += v[temp];
        visited[temp] = 1;
        if(temp != 0)
            visited[temp-1] = 1;
        if(temp != v.size()-1)
            visited[temp+1] = 1;
    }
    
    return 1;   
}

//"visited" array stores, the value of the topics which are already visited or which are consecutive to visited topics as 1, and the topics which can yet be visited as 0.


int main(){
    vector<int> learning_points= {3, 2, 7, 10, 12};
    int ans =Solve(learning_points);
    cout << ans;
}
