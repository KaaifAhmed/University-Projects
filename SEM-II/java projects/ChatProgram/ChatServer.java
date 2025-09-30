import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

// import clientservercomm.*;

public class ChatServer {
    public static ArrayList<PrintWriter> cliePrintWriters = new ArrayList<PrintWriter>();

    public static void main(String[] args) {
        ServerSocket serverSocket;
        Socket clientSocket;

        int port = 9090;

        try {
            serverSocket = new ServerSocket(port);
            System.out.println("Chat Server has started!");
            try {

                while (true) {
                    clientSocket = serverSocket.accept();
                    handleClients client = new handleClients(clientSocket);
                    client.start();
                }
            } catch (Exception e) {
                System.out.println(e.toString());
            }
        }

        catch (Exception e) {
            System.out.println(e.toString());
        }

    }
}

class handleClients extends Thread {
    Socket clientSocket;
    BufferedReader clientReader;
    PrintWriter clientWriter;

    handleClients(Socket socket) {
        try {
            clientSocket = socket;
            clientReader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            clientWriter = new PrintWriter(clientSocket.getOutputStream(), true);
            ChatServer.cliePrintWriters.add(clientWriter);
        } 
        
        catch (Exception e) {
            System.out.println(e.toString());
        }
    }

    @Override
    public void run() {

        System.out.println("Client connected successfully!");
        String chatMessage;
        try {
            clientWriter.println("Please enter your username: ");
            String username = clientReader.readLine();
            System.out.println("Hello " + username + "! Welcome to our chat server!");
            clientWriter.println("Hello " + username + "! Welcome to our chat server!");

            chatMessage = clientReader.readLine();

            while (!(chatMessage.toLowerCase().trim()).equals("quit")) {
                for (PrintWriter writer : ChatServer.cliePrintWriters) {
                    writer.println(username + ": " + chatMessage);
                }
                chatMessage = clientReader.readLine();
            }

            System.out.println("Client disconnected!");
            clientSocket.close();

        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }
}
