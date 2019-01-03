public class Library {

    String address;
    Book[] catalog = new Book[100];
    int num;
    public Library(String libraryAddr) {
        address = libraryAddr;
        num=0;

    }

    public void addBook(Book newbook) {
        catalog[num]=newbook;
        num++;
    }

    public static void printOpeningHours() {
        System.out.println("libraries are open daily from 9am to 5pm.");
    }

    public void printAddress() {
        System.out.println(address);
    }

    public void borrowBook(String bookTitle) {
        for(int i=0;i<num;i++)
            if(catalog[i].title.equals(bookTitle)) {
                if(catalog[i].borrowed) {
                    System.out.println("Sorry, this book is already borrowed.");
                    return;
                }
                catalog[i].borrowed=true;
                System.out.println("You successfully borrowed "+bookTitle);
                return;
            }
        System.out.println("Sorry, this book is not in our catalog.");
    }

    public void printAvailableBooks() {
        for(int i=0;i<num;i++) 
            if(!catalog[i].borrowed)
                System.out.println(catalog[i].title);
    }

    public void returnBook(String bookTitle) {
        for(int i=0;i<num;i++) {
            if(catalog[i].title.equals(bookTitle)) {
                catalog[i].borrowed=false;
                System.out.println("You successfully returned " + bookTitle);
            }
        }

    }


    // Add the missing implementation to this class

    public static void main(String[] args) {
        // Create two libraries
        Library firstLibrary = new Library("10 Main St.");
        Library secondLibrary = new Library("228 Liberty St.");

        // Add four books to the first library
        firstLibrary.addBook(new Book("The Da Vinci Code"));
        firstLibrary.addBook(new Book("Le Petit Prince"));
        firstLibrary.addBook(new Book("A Tale of Two Cities"));
        firstLibrary.addBook(new Book("The Lord of the Rings"));

        // Print opening hours and the addresses
        System.out.println("Library hours:");
        printOpeningHours();
        System.out.println();

        System.out.println("Library addresses:");
        firstLibrary.printAddress();
        secondLibrary.printAddress();
        System.out.println();

        // Try to borrow The Lords of the Rings from both libraries
        System.out.println("Borrowing The Lord of the Rings:");
        firstLibrary.borrowBook("The Lord of the Rings");
        firstLibrary.borrowBook("The Lord of the Rings");
        secondLibrary.borrowBook("The Lord of the Rings");
        System.out.println();

        // Print the titles of all available books from both libraries
        System.out.println("Books available in the first library:");
        firstLibrary.printAvailableBooks();
        System.out.println();
        System.out.println("Books available in the second library:");
        secondLibrary.printAvailableBooks();
        System.out.println();

        // Return The Lords of the Rings to the first library
        System.out.println("Returning The Lord of the Rings:");
        firstLibrary.returnBook("The Lord of the Rings");
        System.out.println();

        // Print the titles of available from the first library
        System.out.println("Books available in the first library:");
        firstLibrary.printAvailableBooks();
    }
} 