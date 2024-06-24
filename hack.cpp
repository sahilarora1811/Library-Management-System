#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class User {
public:
    string username;
    string password;

    User(const string& uname, const string& pwd) : username(uname), password(pwd) {}
};

class UserDatabase {
private:
    vector<User> users;
    string filename; // File to store user data

public:
    UserDatabase(const string& file) : filename(file) {}

    void addUser(const User& user) {
        users.push_back(user);
    }

    bool userExists(const string& username) {
        for (const User& user : users) {
            if (user.username == username) {
                return true;
            }
        }
        return false;
    }

    string getUserPassword(const string& username) {
        for (const User& user : users) {
            if (user.username == username) {
                return user.password;
            }
        }
        return "Bhai jaake sign up karle .";  // Return empty string if user not found (you can handle this case differently)
    }

    void saveToFile() {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const User& user : users) {
                outFile << user.username << " " << user.password << endl;
            }
            outFile.close();
            cout << "User data saved to file." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void loadFromFile() {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string uname, pwd;
            while (inFile >> uname >> pwd) {
                User newUser(uname, pwd);
                users.push_back(newUser);
            }
            inFile.close();
            cout << "User data loaded from file." << endl;
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};
void userLogin(UserDatabase& database) {
    string userName, userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 3) {
        cout << "Please enter your username: ";
        cin >> userName;
        cout << "Please enter your password: ";
        cin >> userPassword;

        if (database.userExists(userName) && userPassword == database.getUserPassword(userName)) {
            cout << "\nWelcome, " << userName << "!" << endl;
            break;
        } else {
            cout << "Invalid login attempt. Please try again." << endl;
            loginAttempt++;
        }
    }

    if (loginAttempt == 3) {
        cout << "Too many login attempts! The program will now terminate." << endl;
        exit(0);
    }

    cout << "Thank you for logging in." << endl;
}
void userSignup(UserDatabase& database) {
    string username, password;

    cout << "Please enter a username: ";
    cin >> username;

    // Check if the username already exists
    if (database.userExists(username)) {
        cout << "Username already exists. Please choose a different one." << endl;
        return;
    }

    cout << "Please enter a password: ";
    cin >> password;

    // Create a new user and add it to the database
    User newUser(username, password);
    database.addUser(newUser);
    database.saveToFile();

    cout << "Account created successfully!" << endl;
}
class node {
public:
    string ISBN;
    int count;
    node *next;
};

class Stack {
private:
public:
    node *top;
    Stack();
    ~Stack();
    bool isEmpty();
    void push(string ISBN, int count);
    void display();
};

Stack::Stack() {
    top = NULL;
}

Stack::~Stack() {
    if (top) {
        node *a = top;
        top = top->next;
        while (top != NULL) {
            delete a;
            a = top;
            top = top->next;
        }
    }
}

bool Stack::isEmpty() {
    return top == NULL;
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack underflow." << endl;
    } else {
        node *a = top;
        while (a != NULL) {
            cout << "ISBN: " << a->ISBN << endl;
            cout << "books: " << a->count << endl;
            a = a->next;
        }
    }
}

void Stack::push(string ISBN, int count) {
    node *b = new node;
    b->ISBN = ISBN;
    b->count = count;
    b->next = NULL;
    if (top != NULL) {
        b->next = top;
    }
    top = b;
    b = NULL;
}

class Node {
public:
    char title[30];
    string ISBN;
    char Author[30];
    char PublishingYear[20];
    Node *next;
};

class List {
private:
    Node *head;

public:
    List();
    ~List();
    bool isEmpty();
    void insert_beg();
    void insert_end();
    void traverse();
    int count();
};

List::List() {
    head = NULL;
}

List::~List() {
    if (head) {
        Node *a = head;
        head = head->next;
        while (head != NULL) {
            delete a;
            a = head;
            head = head->next;
        }
    }
}

bool List::isEmpty() {
    return !head;
}

void List::traverse() {
    if (isEmpty()) {
        cout << "Linked list does not exist." << endl;
    } else {
        Node *a = head;
        while (a != NULL) {
            cout << "Title: " << a->title << endl;
            cout << "ISBN: " << a->ISBN << endl;
            cout << "Author: " << a->Author << endl;
            cout << "Publishing Year: " << a->PublishingYear << endl;
            a = a->next;
        }
    }
}

int List::count() {
    Node *a = head;
    int count = 0;
    while (a != NULL) {
        count++;
        a = a->next;
    }
    return count;
}

void List::insert_beg()
{
    ofstream str;
    cout << "\n\n";
    str.open("C:/Users/sahil/Desktop/hackathon.txt", ios::app);
    if (!"C:/Users/sahil/Desktop/hackathon.txt")
    {
        cout << "\nError while opening the file\n";
    }
    else
    {
        Node *a = new Node;

        cout << "\nISBN: ";
        getline(cin, a->ISBN);
        // cin.getline(a->ISBN, 10);
        cin.ignore();
        str << a->ISBN << "\n";
        cout << "\ntitle: ";
        cin.getline(a->title, 20);
        cin.ignore();
        str << a->title << "\n";
        cout << "\nAuthor: ";
        cin.getline(a->Author, 30);
        cin.ignore();
        str << a->Author << "\n";
        cout << "\nPublishing Year: ";
        cin.getline(a->PublishingYear, 20);
        cin.ignore();
        str << a->PublishingYear << "\n";
        cout << "\nFile saved\n";
        str.close();
        a->next = NULL;
        if (isEmpty() == true)
        {
            head = a;
            a = NULL;
        }
        else
        {
            a->next = head;
            head = a;
        }
    }
}

void List::insert_end()
{
    ofstream str;
    cout << "\n\n";
    str.open("C:/Users/sahil/Desktop/hackathon.txt", ios::app);
    if (!"C:/Users/sahil/Desktop/hackathon.txt")
    {
        cout << "\nError while opening the file\n";
    }
    else
    {
        Node *a = new Node;
        cout << "\nISBN: ";
        getline(cin, a->ISBN);
        // cin.getline(a->ISBN, 10);
        str << a->ISBN << "\n";
        cout << "\ntitle: ";
        cin.getline(a->title, 20);
        str << a->title << "\n";
        cout << "\nAuthor: ";
        cin.getline(a->Author, 30);
        str << a->Author << "\n";
        cout << "\nPublishing Year: ";
        cin.getline(a->PublishingYear, 20);
        cin.ignore();
        str << a->PublishingYear << "\n";
        cout << "\nFile saved\n";
        str.close();
        a->next = NULL;
        if (isEmpty() == true)
        {
            head = a;
            a = NULL;
        }
        else
        {
            Node *b = head;
            while (b != NULL)
            {
                if (b->next == NULL)
                {
                    b->next = a;
                    a = NULL;
                }
                b = b->next;
            }
        }
    }
}
int main() {
    UserDatabase database("C:/Users/sahil/Desktop/data.txt"); // Specify the file to store user data

    // Load existing user data from file
    database.loadFromFile();

    int loginChoice;

    cout << "Welcome to the Library Management System!" << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign Up" << endl;
    cout << "Enter your choice: ";
    cin >> loginChoice;

    if (loginChoice == 1) {
        userLogin(database);
    } else if (loginChoice == 2) {
        userSignup(database);
    } else {
        cout << "Invalid choice. Exiting program." << endl;
        return 0;
    }
    int choice;
    List L;
    do {
        cout << "--------------------------------------------------------------" << endl;
        cout << "1. Add Book." << endl;
        cout << "2. Delete Book." << endl;
        cout << "3. Search Book." << endl;
        cout << "4. Modify record." << endl;
        cout << "5. Display all Books." << endl;
        cout << "6. Quit" << endl;
        cout << "\n\nEnter choice # -> ";
        cin >> choice;
        cin.ignore();
        system("CLS");
        switch (choice) {
        case 1:
            L.insert_end();
            break;
        case 2:
             {
            string temp, ISBN;
            cout << "Enter ISBN: ";
            getline(cin, ISBN);
            ifstream a;
            ofstream b;
            a.open("C:/Users/sahil/Desktop/hackathon.txt");
            b.open("C:/Users/sahil/Desktop/new.txt");
            int i = 4;
            while (getline(a, temp))
            {
                if (temp != ISBN && i == 4)
                {
                    b << temp << endl;
                }
                if (temp == ISBN && i == 4)
                {
                    i--;
                }
                else if (i > 0 && i < 4)
                {
                    i--;
                }
                if (i == 0)
                {
                    i = 3;
                }
            }
            cout << "Record deleted!!" << endl;
            a.close();
            b.close();
            remove("C:/Users/sahil/Desktop/hackathon.txt");
            rename("C:/Users/sahil/Desktop/new.txt", "C:/Users/sahil/Desktop/hackathon.txt");
            break;
        }
        case 3:
            {
            string temp, ISBN;
            cout << "Enter ISBN: ";
            getline(cin, ISBN);
            fstream a;
            int i = 0;
            a.open("C:/Users/sahil/Desktop/hackathon.txt", ios::in);
            if (!a)
            {
                cout << "\nError while opening the file\n";
            }
            else
            {
                cout << "BOOK Record-------->\n\n";
                while (getline(a, temp))
                {
                    if (temp == ISBN)
                    {
                        cout << "ISBN: ";
                        cout << temp << "\n";
                        i = 3;
                    }
                    else if (temp != ISBN && i == 3)
                    {
                        cout << "Title: ";
                        cout << temp << "\n";
                        --i;
                    }
                    else if (temp != ISBN && i == 2)
                    {
                        cout << "Author: ";
                        cout << temp << "\n";
                        --i;
                    }
                    else if (temp != ISBN && i == 1)
                    {
                        cout << "Published Year: ";
                        cout << temp << "\n";
                        --i;
                    }
                }
                cout << endl
                     << endl;
            }
            a.close();
            break;}

        case 4:
            {
            string temp, ISBN;
            cout << "Enter ISBN: ";
            getline(cin, ISBN);
            fstream a;
            int i = 0;
            a.open("C:/Users/sahil/Desktop/hackathon.txt", ios::in);
            if (!a)
            {
                cout << "\nError while opening the file\n";
            }
            else
            {
                cout << "Record------->\n\n";
                while (getline(a, temp))
                {
                    if (temp == ISBN)
                    {
                        cout << "ISBN: ";
                        cout << temp << "\n";
                        i = 3;
                    }
                    else if (temp != ISBN && i == 3)
                    {
                        cout << "Title: ";
                        cout << temp << "\n";
                        --i;
                    }
                    else if (temp != ISBN && i == 2)
                    {
                        cout << "Author: ";
                        cout << temp << "\n";
                        --i;
                    }
                    else if (temp != ISBN && i == 1)
                    {
                        cout << "Publishing Year: ";
                        cout << temp << "\n";
                        --i;
                    }
                }
                cout << endl
                     << endl;
            }
            a.close();
            int choice1;
        re:
            cout << "Press 1 to modify the record\nPress 2 to go back\n\nNote: if you choose to modify the record then previous record will be deleted and new modified record will be saved.\n";
            cin >> choice1;
            cin.ignore();
            if (choice1 == 1)
            {
                ifstream b;
                ofstream c;
                b.open("C:/Users/sahil/Desktop/hackathon.txt");
                c.open("C:/Users/sahil/Desktop/new.txt");
                int i = 4;
                while (getline(b, temp))
                {
                    if (temp != ISBN && i == 4)
                    {
                        c << temp << endl;
                    }
                    if (temp == ISBN && i == 4)
                    {
                        i--;
                    }
                    else if (i > 0 && i < 4)
                    {
                        i--;
                    }
                    if (i == 0)
                    {
                        i = 4;
                    }
                }
                cout << "Record deleted!!" << endl;
                b.close();
                c.close();
                remove("C:/Users/sahil/Desktop/hackathon.txt");
                rename("C:/Users/sahil/Desktop/new.txt", "C:/Users/sahil/Desktop/hackathon.txt");
                L.insert_end();
            }
            else if (choice1 == 2)
            {
                break;
            }
            else
            {
                goto re;
            }
            break;
        }
        case 5:
           {
            ifstream a;
            a.open("C:/Users/sahil/Desktop/hackathon.txt");
            if (!a)
            {
                cout << "\nError while opening the file\n";
            }
            else
            {
                cout << "\n\n\n\n\t\tRecords\n\n\n";
                string temp;
                while (getline(a, temp))
                {
                    cout << temp << "\n";
                }
                cout << endl
                     << endl;
            }
            a.close();
            break;
        }
        case 6:
            cout << "Goodbye! Thank you." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}