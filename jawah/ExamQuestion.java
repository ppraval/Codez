public class ExamQuestion {
    public class Book() {
        Book book;
        public Book() {
            if(book == null)
            {
                this.book = new Book();
                return this.book;
            }
        }
        string bookName;
        string authorName;
        int bookISBN;
        public Book createBook(string bookName, string authorName, int bookISBN) {
            Book newBook = new Book();
            newBook.bookName = bookName;
            newBook.authorName = authorName;
            newBook.bookISBN = bookISBN;
            return newBook;
        }
    }

    public class Author {
        Author Author;
        public Author {
            // Contains code for Author class constructor
        }
        string authorName;
        ArrayList<Book> bookList;
        public void writeBook(string bookName, int bookISBN) {
            Book temp = new Book();
            Book newBook = temp.createBook(bookName, this.authorName, bookISBN)
            this.bookList.append(newBook);
        }
    }
}