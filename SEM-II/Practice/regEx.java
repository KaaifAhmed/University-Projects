import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class regEx {
    public static void main(String[] args) {
        Pattern pattern = Pattern.compile("\\d");
        String text = "I have 4 vowels.";
        Matcher matcher = pattern.matcher(text);
        if (matcher.find()) {
            System.out.println(matcher.group());
        } else {
            System.out.println("ToT");
        }
    }    
}
