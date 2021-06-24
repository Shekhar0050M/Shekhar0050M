#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int k=0;
    printf("Enter the n to find nth fibonacci number: ");
    scanf("%d",&k);
    int64_t a[k+1];
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=k;i++){
        a[i]=a[i-1]+a[i-2];
    }
    printf("%d fibonacci value:: %ld\n",k,a[k]);
}
