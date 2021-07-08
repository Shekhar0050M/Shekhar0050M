#include <iostream>

using namespace std;

inline void nestedloop(int arr1[],int arr2[],int arr1size,int arr2size){
    int diff=INT_MAX,num1=0,num2=0;
    for(int i=0;i<arr1size;i++){
        for(int j=0;j<arr2size;j++){
            if(abs(arr1[i]-arr2[j])<diff){
                diff=abs(arr1[i]-arr2[j]);
                num1=arr1[i];
                num2=arr2[j];
            }
        }
    }
    cout<<num1<<" "<<num2<<endl;
}

inline void somekindofdifferentlogicidkname(int arr1[],int arr2[],int arr1size,int arr2size){
    int diff=INT_MAX,num1=0,num2=0,start1=0,start2=0,temp=0;
    for(int i=0;i<arr1size+arr2size;i++){
        temp=abs(arr1[start1]-arr2[start2]);
        if(temp<diff){
            diff=temp;
            num1=arr1[start1];
            num2=arr2[start2];
        }
        if(arr1[start1]>arr2[start2]){
            start2++;
        }
        else if(arr1[start1]<arr2[start2]){
            start1++;
        }
        else{
            break;
        }
    }
    cout<<num1<<" "<<num2<<endl;
}

int main(){
    int arr1[]={-1,5,10,20,28,3},arr2[]={26,134,135,15,17},arr1size=sizeof(arr1)/sizeof(arr1[0]),arr2size=sizeof(arr2)/sizeof(arr2[0]);
    //nestedloop(arr1,arr2,arr1size,arr2size);
    somekindofdifferentlogicidkname(arr1,arr2,arr1size,arr2size);
}
