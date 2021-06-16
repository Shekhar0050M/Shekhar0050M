#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
#define MAX 100000
bool Virus(char virus[],char b[],int m,int n)
{
    if(m == 0)
      return false;
    if(n==0)
      return true;

    if(b[n-1]== virus[m-1])
       return Virus(virus,b,m-1,n-1);
    else
       return Virus(virus,b,m-1,n);
                   
}

int main()
{
  char V[MAX];
  int N,v,b;
  cin.getline(V,MAX);
  cin >> N;
  v= sizeof(V)/sizeof(V[0]);

  while(N--){
      char B[MAX];
      cin.getline(B,MAX);
      b= sizeof(B)/sizeof(B[0]);
      if(Virus(V,B,v,b))
        cout<<"POSITIVE";
      else
        cout<<"NEGATIVE";  
  }


 return 0;
}
