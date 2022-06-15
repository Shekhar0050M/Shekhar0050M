class Triples{
    int x=0,y=0;
    @Override
    public String toString(){
        return x + " : " + y ;
    }
}

public class ModularInverse{
    public static void main(String[] args){
        int a = 20, m = 4567;
        if(findGCD(a,m)!=1){
            System.out.println("No solution exists.");
            return;
        }
        Triples ans = new Triples();
        euclideanMethod(a,m,ans);
        ans.x=(ans.x%m+m)%m;
        System.out.println(ans);
    }
    private static void euclideanMethod(int a, int b,Triples ans){
        if(b==0){
            ans.x=1;
            ans.y=0;
            return;
        }
        Triples temp = new Triples();
        euclideanMethod(b,a%b,temp);
        ans.x=temp.y;
        ans.y=temp.x-(a/b)*temp.y;
        return;
    }
    private static int findGCD(int a,int b){
        if(b==0){
            return a;
        }
        return findGCD(b,a%b);
    }
}

