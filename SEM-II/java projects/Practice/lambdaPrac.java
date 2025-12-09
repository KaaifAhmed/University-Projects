@FunctionalInterface
interface prac {
    public int dumbness = 10;

    public String dumbo(String str);
}

interface Cool {
    int giveCoolness(int age);

    int findCooler(int[] ages);

    String typeCoolString(String coolerName);
}

class Trash {
    public void displayTrash () {
        System.out.println("Your face.");
    }
}

public class lambdaPrac {
    public static void main (String[] args) {
        // prac s = str -> str + " LOL!";
        // System.out.println(s.dumbo("Hi bro,"));
        // System.out.println(prac.dumbness);

        Cool c = new Cool() {

            @Override
            public int giveCoolness(int age) {
                if (age >= 16 && age <= 28) {
                    return age + 100;
                } else {
                    return age - 100;
                }
            }

            @Override
            public int findCooler(int[] ages) {
                for (int age : ages) {
                    if (age >= 16 && age <= 28) {
                        return age;
                    }
                }
                return -1;
            }

            @Override
            public String typeCoolString(String coolerName) {
                return "Sup Bro!";
            }
            
        };

        c.giveCoolness(18);

        // System.out.println(c.giveCoolness(38));

        Trash tr = new Trash() {
            @Override
            public void displayTrash () {
                System.out.println("Please die! ToT");
            }
        };

        tr.displayTrash();

    }
}