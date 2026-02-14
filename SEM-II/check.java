import java.time.*;
import java.util.*;

public class check {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter year: ");
        int year = sc.nextInt();

        System.out.print("Enter month (1-12): ");
        int month = sc.nextInt();

        LocalDate date = LocalDate.of(year, month, 1);
        String monthName = date.getMonth().toString().substring(0, 1)
                + date.getMonth().toString().substring(1).toLowerCase();

        System.out.println("\nCalendar for the month of " + monthName + ", " + year);
        System.out.println("Su  Mo  Tu  We  Th  Fr  Sa");

        int dayOfWeek = date.getDayOfWeek().getValue();
        int spaces = (dayOfWeek % 7);
        for (int i = 0; i < spaces; i++) {
            System.out.print("    ");
        }
        int daysInMonth = date.lengthOfMonth();

        for (int day = 1; day <= daysInMonth; day++) {
            System.out.printf("%2d  ", day);
            if ((day + spaces) % 7 == 0) {
                System.out.println();
            }
        }

        sc.close();
    }
}