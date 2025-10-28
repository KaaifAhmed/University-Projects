the file path: ");
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