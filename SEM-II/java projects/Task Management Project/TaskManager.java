import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.Scanner;
import java.io.*;

public class TaskManager {
    public static void main(String[] args) {
        boolean cont = true;
        Scanner reader = new Scanner(System.in);
        System.out.println("Welcome to task manager, task manager allows you to track your tasks.");
        do {
            System.out.println("Please select any one of the following options to proceed:");
            System.out.println("\t1. Create a new task");
            System.out.println("\t2. Show all current tasks");
            System.out.println("\t3. Edit any existing task");
            System.out.println("\t4. Quit");
            int choice = reader.nextInt();

            switch (choice) {
                case 1:
                    newTask();
                    break;
                case 2:
                    showAllTasks();
                    break;
                case 3:
                    // editTask();
                    break;
                case 4:
                    cont = false;
                    System.out.println("Thank you for using task manager!");
                    break;
                default:
                    System.out.println("Invalid option, please try again!");
                    break;
            }

        } while (cont);

        // Task task_1 = new Task("Abnormal Assignment",
        //         "Statistics assignment of calculating abnormality due to our abnormal behaviour.", "10-07-2025");

        // task_1.toggleStatus();
        // // task_1.toggleStatus();

        // task_1.summarize();

        // System.out.println("\nThe task " + ((task_1.isOverdue()) ? "is" : "is not") + " overdue!");
    }

    public static void newTask() {
        Scanner reader = new Scanner(System.in);
        System.out.println("Please enter the task name: ");
        String tname = reader.nextLine();
        System.out.println("Please enter the task description: ");
        String tdesc = reader.nextLine();
        System.out.println("Please enter the task due date (dd-MM-yyyy): ");
        String ttime = reader.nextLine();

        Task t = new Task(tname, tdesc, ttime);
        try {
            FileWriter writer = new FileWriter("tasks.txt", true);
            writer.append("Task Name: "+tname+"\nTask Description: "+tdesc+"\nTask Due Date: "+ttime+"\nTask Status: "+t.status+"\n\n");
            writer.close();
            System.out.println("Task created successfully!\n");
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public static void showAllTasks() {
        File taskFile = new File("tasks.txt");
        Scanner reader;
        System.out.println("\nTASK MANAGER (ALL TASKS)");
        try {
            reader = new Scanner(taskFile);

            while (reader.hasNextLine()) {
                System.out.println(reader.nextLine());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
