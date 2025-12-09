import java.util.*;

public class HashMapSetPrac {
    public static void main(String[] args) {
        HashMap<String, String> hm = new HashMap<>();

        hm.put("Kaaif", "Pro");
        hm.put("Bro", "Noob"); 

        for (String key: hm.keySet()) {
            System.out.println(key + " : " + hm.get(key));
        }

        // Hash Set
        HashSet<String> hs = new HashSet<>();

        hs.add("Kaaif");
        hs.add("Kaaif");
        hs.add("Kaaifooo");
        hs.add("Kaaifeee");

        for (String string : hs) {
            System.out.println(string);
        }
    }
}
