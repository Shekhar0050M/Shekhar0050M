public class binaryexponentiation
{
    public static void main(String[] args){
        int n=3,power=13;
        binaryexponentiation tt = new binaryexponentiation();
        System.out.println(tt.logarithmic(n,power));
        System.out.println(tt.multiplicative(n,power));
    }
    public long logarithmic(int n,int power){
        long ans=1;
        while(power>0){
            if(power%2==1){
                ans*=n;
            }
            power/=2;
            n*=n;
        }
        return ans;
    }
    public long multiplicative(int n,int power){
        if(power==0){
            return 1L;
        }
        long tmp=multiplicative(n,power/2);
        if(power%2==1){
            return n*tmp*tmp;
        }
        else{
            return tmp*tmp;
        }
    }
}


