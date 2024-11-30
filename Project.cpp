#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isBorrowed;
};

vector<Book> books; // Book collection
int loggedInUser = -1; // Represents librarian's login state (-1 means not logged in)

// Function Prototypes
void login();
void manageBooks();
void addBook();
void updateBook();
void removeBook();
void searchBook();
void borrowBook();
void returnBook();
void checkDueDate();
void viewBooks();

int main() {
    int choice;

    while (true) {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Login as Librarian\n";
        cout << "2. Manage Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Check Due Date\n";
        cout << "6. View Books\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: login(); break;
            case 2: manageBooks(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: checkDueDate(); break;
            case 6: viewBooks(); break;
            case 7: exit(0);
            default: cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}

// Librarian Login Function
void login() {
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Hardcoded login credentials for simplicity
    if (username == "admin" && password == "password") {
        loggedInUser = 1;
        cout << "Login successful!\n";
    } else {
        cout << "Invalid credentials!\n";
    }
}

// Manage Books Functionality
void manageBooks() {
    if (loggedInUser == -1) {
        cout << "Access denied! Please login as librarian.\n";
        return;
    }

    int choice;
    cout << "\n=== Manage Books ===\n";
    cout << "1. Add Book\n";
    cout << "2. Update Book\n";
    cout << "3. Remove Book\n";
    cout << "4. Search Book\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: addBook(); break;
        case 2: updateBook(); break;
        case 3: removeBook(); break;
        case 4: searchBook(); break;
        default: cout << "Invalid choice!\n";
    }
}

// Add Book Function
void addBook() {
    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.id;
    cin.ignore(); // Clear input buffer
    cout << "Enter Book Title: ";
    getline(cin, newBook.title);
    cout << "Enter Book Author: ";
    getline(cin, newBook.author);
    newBook.isBorrowed = false;
    books.push_back(newBook);
    cout << "Book added successfully!\n";
}

// Update Book Function
void updateBook() {
    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;

    for (auto &book : books) {
        if (book.id == id) {
            cin.ignore();
            cout << "Enter New Title: ";
            getline(cin, book.title);
            cout << "Enter New Author: ";
            getline(cin, book.author);
            cout << "Book updated successfully!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

// Remove Book Function
void removeBook() {
    int id;
    cout << "Enter Book ID to remove: ";
    cin >> id;

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            cout << "Book removed successfully!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

// Search Book Function
void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (const auto &book : books) {
        if (book.id == id) {
            cout << "Book ID: " << book.id << "\n";
            cout << "Title: " << book.title << "\n";
            cout << "Author: " << book.author << "\n";
            cout << "Borrowed: " << (book.isBorrowed ? "Yes" : "No") << "\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

// Borrow Book Function
void borrowBook() {
    int id;
    cout << "Enter Book ID to borrow: ";
    cin >> id;

    for (auto &book : books) {
        if (book.id == id && !book.isBorrowed) {
            book.isBorrowed = true;
            cout << "Book borrowed successfully!\n";
            return;
        } else if (book.isBorrowed) {
            cout << "Book is already borrowed!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

// Return Book Function
void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    for (auto &book : books) {
        if (book.id == id && book.isBorrowed) {
            book.isBorrowed = false;
            cout << "Book returned successfully!\n";
            return;
        } else if (!book.isBorrowed) {
            cout << "Book is not currently borrowed!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

// Check Due Date (Simple Placeholder Function)
void checkDueDate() {
    cout << "Due date check feature is under development.\n";
}

// View All Books
void viewBooks() {
    if (books.empty()) {
        cout << "No books available in the library.\n";
        return;
    }

    cout << "\nAvailable Books:\n";
    for (const auto &book : books) {
        cout << "ID: " << book.id << ", Title: " << book.title
             << ", Author: " << book.author
             << ", Borrowed: " << (book.isBorrowed ? "Yes" : "No") << "\n";
    }
}
