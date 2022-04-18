import java.util.*;

public class binaryexponentiation{
    public static void main(String[] args){
        int num=3,pow=13;

        //Binary exponentiation

        long ans=1;
        int tmp=num,tmppow=13;
        while(tmppow>0){
            if(tmppow%2==1){
                ans*=tmp;
            }
            tmp*=tmp;
            tmppow/=2;
        }
        System.out.println(ans);
    }
}
