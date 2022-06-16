public class GrayCode{
    public static void main(String[] args){
        int n=20;
        int fcg = findGrayCode(n);
        System.out.println(fcg);
        int ifcg = findInverseGrayCode(fcg);
        System.out.println(ifcg);
    }
    private static int findGrayCode(int n) {
        return n ^ (n >> 1);
    }
    private static int findInverseGrayCode(int g) {
        int n=0;
        for(;g>0;g>>=1) {
            n^=g;
        }
        return n;
    }
}
