public class ChineseRemainderTheorem{
    public static void main(String[] args){
        int[] rems = new int[]{2,3,1};
        int[] mods = new int[]{99993,99994,99995};
        long x = ChineseRemainderTheorem(rems,mods);
        System.out.println(x);
    }
    private static long ChineseRemainderTheorem(int[] rems, int[] mods){
        long value = rems[0]+mods[0];
        for(int i=1;i<mods.length;i++){
            while(value%mods[i]!=rems[i]){
                value+=mods[i-1];
            }
        }
        return value;
    }
}

