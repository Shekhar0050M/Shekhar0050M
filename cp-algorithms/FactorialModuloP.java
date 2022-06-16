public class FactorialModuloP{
    public static void main(String[] args){
        int a=7,p=3;
        int xx=FactorialModuloP(a,p);
        System.out.println(xx);
    }
    private static int FactorialModuloP(int a, int p){
        int[] stepCalc = new int[a];
        stepCalc[0]=1;
        for(int i=1;i<a;i++){
            stepCalc[i]=(stepCalc[i-1]*i)%p;
        }
        int res=1;
        while(a>1){
            if((a/p)%2==1){
                res=p-res;
            }
            res=res*stepCalc[a%p]%p;
            a/=p;
        }
        return res;
    }
}

