import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

// import clientservercomm.*;

public class ChatClient {
    public static void main(String[] args) {
        String ipAddress = "localhost";
        int port = 9090;
        Socket clientSocket;
        BufferedReader servReader;
        PrintWriter servWriter;
        Scanner scanner = new Scanner(System.in);

        // String message = "";

        try {
            clientSocket = new Socket(ipAddress, port);
            servReader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            servWriter = new PrintWriter(clientSocket.getOutputStream(), true);
            System.out.println("Client connected to Chat Server (" + ipAddress + ":" + port + ") successfully");

            String msg = servReader.readLine();
            System.out.print(msg);
            String username = scanner.nextLine();
            servWriter.println(username);
            msg = servReader.readLine();
            System.out.println(msg);
            clientMsgs clientMsgs = new clientMsgs(servReader);
            clientMsgs.start();
            String chatMessage = scanner.nextLine();


            while (!((chatMessage.toLowerCase().trim()).equals("quit"))) {
                servWriter.println(chatMessage);
                chatMessage = scanner.nextLine();
            }

            System.out.println("Chat server ended!");

            clientSocket.close();
            scanner.close();
        } catch (Exception e) {
            System.out.println(e.toString());
        }

    }
}

class clientMsgs extends Thread {
    BufferedReader servReader;

    clientMsgs (BufferedReader sReader) {
        servReader = sReader;
    }

    @Override
    public void run() {
        while (true) {
            try {
                System.out.println(servReader.readLine());
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
}