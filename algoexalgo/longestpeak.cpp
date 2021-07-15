#include <iostream>

using namespace std;

inline int longestpeak(int arr[],int n){
    int maxpeak=0,j=0,k=0,cnt=0,peak=0;
    for(int i=1;i<n-1;i++){
        if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
            j=i;
            while(j--){
                if(arr[j]<=arr[j-1]){
                    break;;
                }
            }
            k=i;
            while(k++ && k<n){
                if(arr[k]<=arr[k+1]){
                    break;;
                }
            }
            cnt=k-j;
            if(cnt>peak){
                peak=cnt;
                maxpeak=arr[i];
            }
            cnt=0;
            i=k;
        }
    }
    return maxpeak;
}
int main(){
    int arr[]={1,2,3,3,4,0,10,6,5,-1,-3,2,3},n=sizeof(arr)/sizeof(arr[0]);
    cout<<longestpeak(arr,n);
}
