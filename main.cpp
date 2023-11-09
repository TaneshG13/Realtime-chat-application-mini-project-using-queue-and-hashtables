#include <iostream>
#include <string>
using namespace std;
#define MAX_USERS 100
#define MAX_MESSAGES 100
class ChatApplication {
private:
    string messages[MAX_MESSAGES];
    string users[MAX_USERS];
    int messageCount = 0;
    int userCount = 0;
public:
    void sendMessage(const string& user, const string& message) {
        if (messageCount < MAX_MESSAGES) {
            messages[messageCount++] = message;
            users[userCount++] = user;
            cout<<endl;
        } else {
            cout << "Message limit reached." << endl;
        }
    }

    void displayMessages() {
        for (int i = 0; i < messageCount; i++) {
            cout << users[i] << ": " << messages[i] << endl;
            cout<<endl;
        }
    }

    void displayUserMessages(const string& user) {
        for (int i = 0; i < userCount; i++) {
            if (users[i] == user) {
                cout << users[i] << ": " << messages[i] << endl;
                cout<<endl;
            }
        }
    }
};

int main() {
    ChatApplication chatApp;
    int choice;
    string user, message;

    do {
        cout << "1. Send Message\n";
        cout << "2. Display All Messages\n";
        cout << "3. Display User Messages\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl;

        switch(choice) {
            case 1:
                cout << "Enter User: ";
                cin >> user;
                cout << "Enter Message: ";
                cin.ignore();
                getline(cin, message);
                chatApp.sendMessage(user, message);
                break;
            case 2:
                chatApp.displayMessages();
                break;
            case 3:
                cout << "Enter User: ";
                cin >> user;
                chatApp.displayUserMessages(user);
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}
