import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class Task {
    String title;
    String description;
    String status = "To Do";
    Date dueDate;

    public Task(String tit, String desc, String time) {
        this.title = tit;
        this.description = desc;
        try {
            this.dueDate = new SimpleDateFormat("dd-MM-yyyy").parse(time);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public void toggleStatus() {
        if (this.status == "To Do") {
            this.status = "In Progress";
        } else if (this.status == "In Progress") {
            this.status = "Completed";
        } else if (this.status == "Completed") {
            this.status = "To Do";
        }
    }

    public void summarize() {
        System.out.println(title.toUpperCase());
        System.out.println(description);
        System.out.println("Due Date: " + dueDate);
        System.out.println("Status: " + status);
    }

    public boolean isOverdue() {
        if (this.status == "Completed") {
            return false;
        }

        else {
            SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
            Date today = null;
            try {
                today = sdf.parse(sdf.format(new Date()));
            } catch (ParseException e) {
                e.printStackTrace();
            }

            if (dueDate.before(today)) {
                return true;
            } else {
                return false;
            }
        }
    }
}