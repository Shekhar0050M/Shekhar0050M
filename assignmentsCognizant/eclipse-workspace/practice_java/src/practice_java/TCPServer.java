
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPServer {
	public static void main(String[] args) throws Exception{
		String clientSentence;
		String capitalizedSentence;
		//Generate connection on client side
		ServerSocket welcomeSocket = new ServerSocket(6789);
		while(true) {
			Socket connectionSocket = welcomeSocket.accept();
			Scanner inputFromClient = new Scanner(connectionSocket.getInputStream());
			//Transferring of data
			DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
			clientSentence=inputFromClient.nextLine();
			capitalizedSentence=clientSentence.toUpperCase()+"\n";
			outToClient.writeBytes(capitalizedSentence);
		}
	}
}
