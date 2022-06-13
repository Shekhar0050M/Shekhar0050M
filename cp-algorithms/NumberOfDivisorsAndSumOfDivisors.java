public class NumberOfDivisorsAndSumOfDivisors{
    public static void main(String[] args){
        int n=10;
        NumberOfDivisors(n);
        SumOfDivisors(n);
    }
    private static void NumberOfDivisors(int n){
        int xx=n;
        int count=0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                while(n%i==0){
                    n/=i;
                    count++;
                }
            }
        }
        if(n>1){
            count++;
        }
        System.out.println("Number of divisors for " + xx + " is " + count);
    }
    private static void SumOfDivisors(int n){
        int xx=n;
        int sum=0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                while(n%i==0){
                    n/=i;
                    sum+=i;
                }
            }
        }
        if(n>1){
            sum+=n;
        }
        System.out.println("Sum of divisors for " + xx + " is " + sum);
    }
}


