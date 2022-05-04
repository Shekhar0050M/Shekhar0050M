import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPClient{
    public static void main(String[] args) throws Exception{
        String sentence;
        String modifiedSentence;
        //Input
        Scanner inputFromUser= new Scanner(System.in);
        //Generate connection on server side
        Socket clientSocket = new Socket("127.0.0.1",6789);
        
        //Transferring of data
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        Scanner inputFromServer = new Scanner(clientSocket.getInputStream());
        sentence=inputFromUser.nextLine();
        outToServer.writeBytes(sentence+"\n");
        modifiedSentence=inputFromServer.nextLine();
        //Post-processing printing
        System.out.println("FROM SERVER: "+modifiedSentence);
        clientSocket.close();
    }
}
