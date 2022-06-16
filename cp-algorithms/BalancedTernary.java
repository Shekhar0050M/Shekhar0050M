
public class BalancedTernary{
    public static void main(String[] args){
        String s="237";
        String ternaryValue = DecimalToTernary(s);
        System.out.println(ternaryValue);
        int decimalValue = TernaryToDecimal(ternaryValue);
        System.out.println(decimalValue);
    }
    private static String DecimalToTernary(String s){
        int a = Integer.parseInt(s);
        String ter="";
        while(a>0){
            ter+=a%3;
            a/=3;
        }
        StringBuffer sb = new StringBuffer();
        sb.append(ter);
        sb.reverse();
        for(int i=sb.length()-1 ; i>=0 ; i--) {
        	if(sb.charAt(i)=='2') {
        		sb.setCharAt(i, 'Z');
        		if(i==0) {
        			sb.reverse();
        			sb.append(1);
        			sb.reverse();
        		}
        		else{
        			sb.setCharAt(i-1, (Integer.parseInt(sb.charAt(i-1)+"")+1+"").charAt(0));
        		}
        	}
        	else if(sb.charAt(i)=='3') {
        		sb.setCharAt(i, '0');
        		if(i==0) {
        			sb.reverse();
        			sb.append(1);
        			sb.reverse();
        		}
        		else{
        			sb.setCharAt(i-1, (Integer.parseInt(sb.charAt(i-1)+"")+1+"").charAt(0));

        		}
        	}
        }
        return sb.toString();
    }
	private static int TernaryToDecimal(String s){
        StringBuffer sb = new StringBuffer();
        sb.append(s);
        sb.reverse();
        int value=0,dd=1;
        for(int i=0;i<sb.length();i++) {
        	if(sb.charAt(i)=='Z') {
        		value+=dd*-1;
        	}
        	else{
        		value+=dd*Integer.parseInt(sb.charAt(i)+"");
        	}
        	dd*=3;
        }
        return value;
    }
}


