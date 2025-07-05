#include <stdio.h>
#include <stdlib.h> 
struct Book {
    int id;
    char title[100];
    char author[100];
    struct Book* next;
};
void addBook(struct Book** head) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    printf("Enter Book ID: ");
    scanf("%d", &newBook->id);
    printf("Enter Title: ");
    scanf(" %[^\n]", newBook->title);
    printf("Enter Author: ");
    scanf(" %[^\n]", newBook->author);

    newBook->next = *head;
    *head = newBook;

    printf("Book added successfully!\n");
}
void displayBooks(struct Book* head) {
    if (head == NULL) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n-Library Books-\n");
    while (head != NULL) {
        printf("ID: %d\nTitle: %s\nAuthor: %s\n\n", head->id, head->title, head->author);
        head = head->next;
    }
}
void searchBook(struct Book* head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            printf("Book Found:\nID: %d\nTitle: %s\nAuthor: %s\n", head->id, head->title, head->author);
            return;
        }
        head = head->next;
    }
    printf("Book with ID %d not found.\n", id);
}
void deleteBook(struct Book** head, int id) {
    struct Book *temp = *head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("Book deleted successfully.\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Book deleted successfully.\n");
}
int main() {
    struct Book* head = NULL;
    int choice, id;

    while (1) {
        printf("\nLibrary Menu:\n1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(&head); break;
            case 2: displayBooks(head); break;
            case 3: 
                printf("Enter Book ID to search: "); 
                scanf("%d", &id);
                searchBook(head, id); 
                break;
            case 4: 
                printf("Enter Book ID to delete: "); 
                scanf("%d", &id);
                deleteBook(&head, id); 
                break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

