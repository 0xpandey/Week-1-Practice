#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> twoSum(vector<int>& a , int t){
    unordered_map<int,int> mp;
    for(int i = ; i<a.size(),i++ ){
        if(mp.count(t-a[i])) return {mp[t-a[i]],i};
        mp[a[i]]=i;
    }
    return{};
}