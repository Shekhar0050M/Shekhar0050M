import java.io.*;
import java.net.*;
import java.util.*;

class DateClient{
    public static void main(String[] args) throws Exception{
        Socket soc = new Socket(InetAddress.getLocalHost(),5217);
        Scanner sc = new Scanner(soc.getInputStream());
        System.out.println(sc.nextLine());
    }
}

