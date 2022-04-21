public class GreatestCommonDivisor{
    public static void main(String[] args){
        int num1=2,num2=34;
        System.out.println(GreatestCommonDivisor.gcd(num1,num2));
    }
    private static int gcd(int num1,int num2){
        if(num2==0){
            return num1;
        }
        else{
            return gcd(num2,num1%num2);
        }
    }
}


