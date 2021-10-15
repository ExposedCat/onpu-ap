#include <stdio.h>
#include <string.h>
void main() {
    struct Book {
        char author[51];
        char name[51];
        char publisher[51];
        unsigned year;
        unsigned pages_number;
    };

    struct Book books[50];
    unsigned index = 0;
    struct Book book;

    printf("Input data of 5 books, for each new line by template:\n");
    printf("Book_author book_name book_publisher year pages_number\n");
    printf("P.S. Avoid spaces: scanf function is terrible. All text values must be less than 51 characters.\n");
    do {
        printf("%d) ", index + 1);
        scanf("%s %s %s %d %d", book.author, book.name, book.publisher, &book.year, &book.pages_number);
        books[index] = book;
        index++;
    } while (index < 5);

    char author[50];
    unsigned author_found = 0;
    char name[50];
    unsigned max_pages_number = 0;
    char author2[50];
    char publisher[50];
    unsigned year;
    printf("Input author to check for him/her books: ");
    scanf("%s", &author);
    printf("Input author to search him/her books: ");
    scanf("%s", &author2);
    printf("Input year to search books: ");
    scanf("%d", &year);
    printf("Input publisher to search books: ");
    scanf("%s", &publisher);

    struct Book found_books[50];
    unsigned index2 = 0;

    for (unsigned i = 0; i < index; ++i) {
        struct Book book = books[i];
        if (!author_found && !strcmp(book.author, author)) {
            author_found = 1;
        }
        if (book.pages_number > max_pages_number) {
            max_pages_number = book.pages_number;
            strcpy(name, book.name);
        }
        if (!strcmp(book.author, author2) && !strcmp(book.publisher, publisher) && year == book.year) {
            found_books[index2] = books[i];
            index2++;
        }
    }

    printf("\n\n%s's books found: %s.\n", author, author_found ? "Yes" : "No");
    printf("Biggest book is \"%s\" with %d pages.\n", name, max_pages_number);
    if (index2) {
        printf("%s's books published by %s in %d:\n", author2, publisher, year);
        for (unsigned i = 0; i < index2; ++i) {
            struct Book book = books[i];
            printf("%d)\n", i + 1);
            printf("   Author: %s\n", book.author);
            printf("   Book name: %s\n", book.name);
            printf("   Book publisher: %s\n", book.publisher);
            printf("   Publish year: %d\n", book.year);
            printf("   Number of pages: %d\n", book.pages_number);
        }
    } else {
        printf("Books of specified author, year and publisher not found.\n");
    }

    printf("\n");
}