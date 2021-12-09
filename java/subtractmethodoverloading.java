public class subtractmethodoverloading {
    void subtractmethodoverloading(int a,int b){
        System.out.println(a-b);
    }
    void subtractmethodoverloading(int a,int b,int c){
        System.out.println(a-b-c);
    }
    void subtractmethodoverloading(int a){
        System.out.println(a);
    }
    public static void main(String[] args) {
        subtractmethodoverloading ss = new subtractmethodoverloading();
        ss.subtractmethodoverloading(10);
        ss.subtractmethodoverloading(10,2);
        ss.subtractmethodoverloading(10,2,3);
    }
}