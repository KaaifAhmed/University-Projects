import java.util.Scanner;

public class practice {
    public static String input(String prompt) {
        System.out.print(prompt);
        Scanner scanner = new Scanner(System.in);
        scanner.close();
        return scanner.nextLine();
    }

    public static boolean checkAnagram(String str1, String str2) {
        if (str1.length() != str2.length()) return false;
        int[] occ = new int[26];
        for (int i = 0; i < str1.length(); i++) {
            occ[str1.charAt(i) - 'a']++;
            occ[str2.charAt(i) - 'a']--;
        }
        for (int count : occ) {
            if (count != 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        String str1 = input("Please enter string # 1: ");
        String str2 = input("Please enter string # 2: ");
        boolean result = checkAnagram(str1, str2);
        System.out.println("The strings " + (result ? "are" : "are not") + " an anagram");
    }
}
