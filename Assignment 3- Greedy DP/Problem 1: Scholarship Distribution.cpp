#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Solve(vector<int> v, int n){
    stable_sort(v.begin(),v.end());
    int ans{};
    for(int i:v){
        n -= i; //find scholarship amount left after distributing a student.
        if(n < 0) //scholarship amount finished
            return ans; 
        ans++; //distribution to a student is succesfull.
    }
    return ans; //this statements executes when scholarship amount is left, but all the students got the scholarship. 


int main(){
    int no_of_students= 5;
    int total_amt= 10;
    vector<int> min_scholarship={3, 5, 7, 2};
    cout << Solve(min_scholarship,total_amt);
}
