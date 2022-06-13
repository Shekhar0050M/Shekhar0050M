
public class EulerTotient{
    public static void main(String[] args){
        int n=10;
        System.out.println(euler(n));
    }
    private static int euler(int n){
        float result=n;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                while(n%i==0){
                    n/=i;
                }
                result*=(1.0-1.0/(float)i);
            }
        }
        if(n>1){
            result*=(1.0-1.0/(float)n);
        }
        return (int)result;
    }
}


