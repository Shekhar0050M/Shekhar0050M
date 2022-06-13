public class SieveOfEratosthenes{
    public static void main(String[] args){
        int n=2000000;
        printAllPrimes(n);
    }
    private static void printAllPrimes(int n){
        int[] sets = new int[n+1];
        sets[0]=sets[1]=1;
        for(int i=2;i<=Math.sqrt(n);i++){
            if(sets[i]==0){
                for(int j=i*i;j<=n;j=j+i){
                    sets[j]=1;
                }
            }
        }
        for(int i=0;i<=n;i++){
            if(sets[i]==0)
                System.out.print(i+" ");
        }
    }
}

