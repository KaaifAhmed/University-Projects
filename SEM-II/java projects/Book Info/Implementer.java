import java.io.IOException;

public class Implementer {
    public static void main(String[] args) {
        // BookInfo book1 = new BookInfo("Benefits of Shawarma", "Meritorious Dr Chandiyo", "abnormalpublishers.pk", 300, 550.0f); // adding "f" with a number typecasts it to be a float instead of a double (default is double)

        EbookInfo eb1 = new EbookInfo("Rules for Being Human", "Cherie Carter-Scott", "Insightful Publishers", "C:\\Users\\Abdullah\\CLionProjects\\java projects\\Book Info\\Rules_for_Being_Human");
        // eb1.displayBookInfo();
        eb1.displayBook();
        // eb1.displayBookPDF();

    }
    
}