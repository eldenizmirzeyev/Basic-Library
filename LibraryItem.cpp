#include <iostream>
#include <string>

using namespace std;

class LibraryItem {
    public:
        LibraryItem(const string& title) : title(title) {}

        virtual double calculateLateFee(int daysLate) const = 0;

        virtual void displayInfo() const {
            cout << "Title: " << title << endl;
        }

        static int totalItems;

    protected:
        string title;
};

int LibraryItem :: totalItems = 0;

class Book : public LibraryItem {
    public:
        Book(const string& title, const string& author) : LibraryItem(title), author(author) {
            LibraryItem::totalItems++;
        }

        double calculateLateFee(int daysLate) const override {
            return (daysLate * 5);
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Author: " << author << std::endl;
        }

    private:
        string author;
};

class DVD : public LibraryItem {
    public:
        DVD(const string& title, int duration) : LibraryItem(title), duration(duration) {
            LibraryItem::totalItems++;
        }

        double calculateLateFee(int daysLate) const override {
            return (daysLate * 10);
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Duration: " << duration << " minutes" << endl;
        }

    private:
        int duration;
};

int main() {
    system("cls");

    // Create objects
    Book book1("Clean Code", "Robert Martin");
    Book book2("The Pragmatic Programmer", "Andy Hunt");

    DVD dvd1("Inception", 148);
    DVD dvd2("Interstellar", 169);

    // Display info
    cout << "=== BOOKS ===" << endl;
    book1.displayInfo();
    cout << "Late Fee: " << book1.calculateLateFee(5) << endl;

    cout << endl;

    book2.displayInfo();
    cout << "Late Fee: " << book2.calculateLateFee(2) << endl;

    cout << "\n=== DVDS ===" << endl;
    dvd1.displayInfo();
    cout << "Late Fee: " << dvd1.calculateLateFee(3) << endl;

    cout << endl;

    dvd2.displayInfo();
    cout << "Late Fee: " << dvd2.calculateLateFee(7) << endl;

    cout << "\n=== TOTAL ITEMS ===" << endl;
    cout << "Total Library Items: " << LibraryItem::totalItems << endl;
}
