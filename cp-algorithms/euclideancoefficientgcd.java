class biplet{
    int x=0;
    int y=0;
}

public class euclideancoefficientgcd{
    public static void main(String[] args){
        euclideancoefficientgcd ecg = new euclideancoefficientgcd();
        biplet ans = new biplet();
        int a=33,b=12;
        ecg.gcd(a,b,ans);
    }
    public int gcd(int a, int b,biplet ans) {
        if (b == 0) {
            ans.x = 1;
            ans.y = 0;
            return a;
        }
        biplet tmp = new biplet();
        int d = gcd(b, a % b,tmp);
        ans.x=tmp.y;
        ans.y=tmp.x-tmp.y*(a/b);
        System.out.println(a + "  " + ans.x + " + " + b + " " + ans.y + " = " + d);
        return d;
    }
}


