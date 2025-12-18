import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class AttendanceHelper {
    static class ClassConfig {
        String name;
        int numStudents;
        String attendanceDir;
        public ClassConfig(String name, int numStudents, String attendanceDir) {
            this.name = name;
            this.numStudents = numStudents;
            this.attendanceDir = attendanceDir;
        }
    }

    public static List<ClassConfig> loadClassConfigs(String configPath) {
        List<ClassConfig> classConfigs = new ArrayList<>();
        try (Scanner sc = new Scanner(new File(configPath))) {
            while (sc.hasNextLine()) {
                String line = sc.nextLine().trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] parts = line.split(",");
                if (parts.length >= 3) {
                    String name = parts[0].trim();
                    int numStudents = Integer.parseInt(parts[1].trim());
                    String attendanceDir = parts[2].trim();
                    classConfigs.add(new ClassConfig(name, numStudents, attendanceDir));
                }
            }
        } catch (Exception e) {
            System.out.println("Error reading config: " + e.getMessage());
        }
        return classConfigs;
    }

    
    public static boolean[] takeAttendance(int numStudents, Scanner scanner) {
        boolean[] attendance = new boolean[numStudents];
        System.out.println("\n--- Attendance Entry ---");

        for (int i = 0; i < numStudents; i++) {
            while (true) {
                System.out.printf("Seat # %2d (p/a/r): ", i + 1);

                String att = scanner.nextLine().trim().toLowerCase();

                if (att.equals("p")) {
                    attendance[i] = true;
                    break;
                } 
                
                else if (att.equals("a")) {
                    attendance[i] = false;
                    break;
                } 
                
                else if (att.equals("r")) {
                    if (i > 1) {
                        i -= 2;
                        System.out.println("Redoing previous seat.");
                        break;
                    } else {
                        System.out.println("No previous seat to redo.");
                    }
                } 
                
                else {
                    System.out.println("Invalid input! Enter 'p' for present, 'a' for absent, or 'r' to redo previous seat.");
                }
            }
        }
        return attendance;
    }

    
    public static void showAttendanceSummary(boolean[] attendance, Scanner scanner, ClassConfig selectedClass) {
        while (true) {
            int totalPresent = 0;

            System.out.println("\n--- Attendance Summary ---");

            for (int i = 0; i < attendance.length; i++) {
                char status = attendance[i] ? 'p' : 'a';
                System.out.printf("Seat # %2d: %s\n", i + 1, status);

                if (attendance[i]) totalPresent++;
            }

            System.out.printf("Total Present: %d / %d\n", totalPresent, attendance.length);
            System.out.printf("Attendance Percentage: %.2f%%\n", (attendance.length == 0) ? 0 : (double) totalPresent / attendance.length * 100);
            
            System.out.print("Would you like to toggle any student's attendance? (y/n): ");
            String resp = scanner.nextLine().trim().toLowerCase();

            if (!resp.equals("y")) break;
            
            int seatNum = -1;
            while (true) {
                System.out.print("Enter seat number to toggle (1-" + attendance.length + "): ");
                String input = scanner.nextLine().trim();
                try {
                    seatNum = Integer.parseInt(input);
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input!");
                    continue;
                }
                if (seatNum < 1 || seatNum > attendance.length) {
                    System.out.println("Seat number out of range!");
                    continue;
                }
                break;
            }
            attendance[seatNum - 1] = !attendance[seatNum - 1];
            System.out.println("Seat # " + seatNum + " attendance toggled.");
        }
        System.out.print("Save this attendance? (y/n): ");
        if (scanner.nextLine().trim().equalsIgnoreCase("y")) {
            saveAttendanceToFile(attendance, selectedClass);
        }
    }

    public static void saveAttendanceToFile(boolean[] attendance, ClassConfig selectedClass) {
        String dirPath = selectedClass.attendanceDir;
        // if (!dirPath.endsWith("\\") && !dirPath.endsWith("/")) dirPath += File.separator;

        File dir = new File(dirPath);
        if (!dir.exists()) dir.mkdirs();

        java.time.LocalDateTime now = java.time.LocalDateTime.now();
        java.time.format.DateTimeFormatter dtfFile = java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd_hh-mm");
        java.time.format.DateTimeFormatter dtfText = java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd hh:mm");

        String filename = dirPath + "attendance_" + dtfFile.format(now) + ".txt";

        try (FileWriter writer = new FileWriter(filename)) {
            writer.write("Attendance Record\n");
            writer.write("Date & Time: " + dtfText.format(now) + "\n");

            for (int i = 0; i < attendance.length; i++) {
                char status = attendance[i] ? 'p' : 'a';
                writer.write(String.format("Seat # %2d: %s\n", i + 1, status));
            }

            writer.write("-----------------------------\n");
            System.out.println("Saved to: " + filename);

        } catch (IOException e) {
            System.out.println("Error saving attendance: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<ClassConfig> classConfigs = loadClassConfigs("config.txt");

        if (classConfigs.isEmpty()) {
            System.out.println("No classes found. Exiting.");
            return;
        }

        System.out.println("Available Classes:");
        for (int i = 0; i < classConfigs.size(); i++) {
            System.out.printf("%d. %s\n", i + 1, classConfigs.get(i).name);
        }

        int classChoice = -1;
        while (classChoice < 1 || classChoice > classConfigs.size()) {
            System.out.print("Select a class by number: ");
            try {
                classChoice = Integer.parseInt(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.println("Invalid input!");
            }
        }
        
        ClassConfig selectedClass = classConfigs.get(classChoice - 1);
        boolean[] attendance = takeAttendance(selectedClass.numStudents, scanner);
        showAttendanceSummary(attendance, scanner, selectedClass);
        scanner.close();
    }
}