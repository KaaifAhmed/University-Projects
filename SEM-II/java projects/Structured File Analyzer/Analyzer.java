import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;

/*

ASSUMPTIONS:
 - I am assuming that the files will always contain the final two fields which will have the qty and the price of the products.
 - Also that the date field would include a "date" title.
 - And that the date would be formatted as "XX-MONTH-XX" and the user would want the answer month wise.
 - Only .tab, .csv, and .txt files are allowed

 */

public class Analyzer {
    public static void main(String[] args) {
        System.out.print("Please give the file path: ");
        Scanner scanner = new Scanner(System.in);
        String path = scanner.nextLine();

        try {
            File dataFile = new File(path);
            Scanner read = new Scanner(dataFile);
            String ext = giveFileExt(path);

            if (ext.equalsIgnoreCase("tab") || ext.equalsIgnoreCase("csv")) {

                String regExt = "";
                if (ext.equals("csv")) {
                    regExt = ",";
                } else {
                    regExt = "\t";
                }

                String fieldHead = read.nextLine();
                String fieldHeads[] = fieldHead.split(regExt);

                System.out.println("\nYour data contains the following fields:");
                for (int i = 0; i < (fieldHeads.length - 2); i++) {
                    System.out.println(" " + i + ". " + fieldHeads[i]);
                }
                System.out.print("Please select a field to filter the data with (0-" + (fieldHeads.length - 3) + "): ");

                int fieldI = scanner.nextInt();

                if (fieldHeads[fieldI].equalsIgnoreCase("date")) {
                    HashMap<String, Double> data = filterDatewiseTotal(read, fieldI, regExt);
                    printMapData(data);

                } else {
                    HashMap<String, Double> data = filteredTotal(read, fieldI, regExt);
                    printMapData(data);

                }
            } else {
                System.out.println("File format not supported!");
            }

        } catch (FileNotFoundException fnfe) {
            System.out.println("No file found at \"" + path + "\"");
        }
        scanner.close();

    }

    public static String giveFileExt(String path) {
        if (path == null || path.isEmpty()) {
            return "";
        }

        File f = new File(path);
        String name = f.getName();

        int lastDot = name.lastIndexOf('.');
        if (lastDot == -1 || lastDot == name.length() - 1) {
            return "";
        }

        return name.substring(lastDot + 1);
    }

    public static void printMapData(HashMap<String, Double> data) {
        double total = 0;
        System.out.println("\n");
        System.out.println("FILTERED DATA:");
        for (HashMap.Entry<String, Double> entry : data.entrySet()) {
            String name = entry.getKey();
            Double sales = entry.getValue();
            total += sales;
            System.out.println(name + ":\t" + sales);
        }
        System.out.println("\nTotal:\t" + total);
    }

    public static HashMap<String, Double> filterDatewiseTotal(Scanner fileReader, int fieldInd, String regExt) {
        HashMap<String, Double> data = new HashMap<>();

        while (fileReader.hasNextLine()) {
            String line = fileReader.nextLine();
            String[] fields = line.split(regExt);
            String filter = fields[fieldInd].split("-")[1];

            if (data.containsKey(filter)) {
                double am = data.get(filter);
                double price = Double.parseDouble(fields[fields.length - 1]);
                int qty = Integer.parseInt(fields[fields.length - 2]);
                am += price - qty;
                data.replace(filter, am);
            } else {
                double price = Double.parseDouble(fields[fields.length - 1]);
                int qty = Integer.parseInt(fields[fields.length - 2]);
                double am = price - qty;
                data.put(filter, am);
            }
        }

        return data;
    }

    public static HashMap<String, Double> filteredTotal(Scanner fileReader, int fieldInd, String regExt) {
        HashMap<String, Double> data = new HashMap<>();
        fileReader.nextLine();

        while (fileReader.hasNextLine()) {
            String line = fileReader.nextLine();
            String[] fields = line.split(regExt);

            if (data.containsKey(fields[fieldInd])) {
                double am = data.get(fields[fieldInd]);
                double price = Double.parseDouble(fields[fields.length - 1]);
                int qty = Integer.parseInt(fields[fields.length - 2]);
                am += price - qty;
                data.replace(fields[fieldInd], am);
            } else {
                double price = Double.parseDouble(fields[fields.length - 1]);
                int qty = Integer.parseInt(fields[fields.length - 2]);
                double am = price - qty;
                data.put(fields[fieldInd], am);
            }
        }

        return data;
    }
}