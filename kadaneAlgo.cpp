#include <iostream>
#include <vector>

using namespace std;

int main(){

    //subarray
    // int n=5;
    // int arr[5]={1,2,3,4,5};
    // for(int st=0;st<n;st++){
    //     for(int end=st;end<n;end++){
    //         for(int i=st ;i<=end;i++){
    //             cout<<arr[i];
    //         }
    //         cout <<" ";
    //     }
    //     cout<<endl;
    // }

    //maximum subarray sum
    //brute force approach
    int n=7;
    int arr[7]={3,-4,5,4,-1,7,-8};
    int maxsum=INT32_MIN;
    for(int st=0;st<n;st++){
        int currentsum=0;
        for(int end=st;end<n;end++){

            currentsum +=arr[end];
            maxsum=max(currentsum,maxsum);
            
        }
    }

    cout<<maxsum;

    return 0;
}