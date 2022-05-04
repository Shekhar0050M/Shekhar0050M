import java.net.*;
import java.io.*;
import java.util.*;

class DateServer{
    public static void main(String[] args) throws Exception{
        ServerSocket ss = new ServerSocket(5217);
        while(true){
            System.out.println("Waiting for connection...");
            Socket soc = ss.accept();
            DataOutputStream out = new DataOutputStream(soc.getOutputStream());
            out.writeBytes("Server Date: " + (new Date()).toString()+"\n");
            out.close();
            soc.close();
        }
    }
}

