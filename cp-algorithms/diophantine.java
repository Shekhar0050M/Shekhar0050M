class biplet{
    int x=0,y=0,gcd=0;
}

public class diophantine{
    public static void main(String[] args){
        int a=21,b=15,c=6;
        biplet ans = new biplet();
        diophantine de = new diophantine();
        de.gcd(a,b,ans);
        ans.x*=c/ans.gcd;
        ans.y*=c/ans.gcd;
        System.out.println(a+" "+ans.x+" + "+b+" "+ans.y+" = "+c);
    }
    public void gcd(int a,int b,biplet ans){
        if(b==0){
            ans.x=1;
            ans.y=0;
            ans.gcd=a;
            return;
        }
        biplet tmp = new biplet();
        gcd(b,a%b,tmp);
        ans.x=tmp.y;
        ans.y=tmp.x-(a/b)*tmp.y;
        ans.gcd=tmp.gcd;
        return;
    }
}


