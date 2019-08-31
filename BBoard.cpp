#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

#include "BBoard.h"
#include "User.h"

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::streamsize;
using std::numeric_limits;

// private:
// std::string title;
// std::vector<User> userList;
// User currentUser;
// std::vector<Message> messageList;

// public:
// Constructs a board with a default title,
// empty user & message lists,
// and the "default" User
BBoard::BBoard() : title("CS12 Bulletin Board") {}

// Same as the default constructor except
// it sets the title of the board
BBoard::BBoard(const string& title) : title(title) {}

// Imports all the authorized users from an input file,
// storing them as User objects in the vector userList
// The name of the input file is passed in as a parameter to this function.
// See below for file format.
bool BBoard::loadUsers(const string& fileName) {
  ifstream inFS;
  inFS.open(fileName);
  if (!inFS.is_open()) {
    return false;
  }

  string dataName;
  string dataPass;

  while (inFS >> dataName && inFS >> dataPass) {
    User x(dataName, dataPass);
    userList.push_back(x);
  }

  return true;
}

// Asks for and validates a user/password.
// Always asks for both user and password combo unless 'q' or 'Q' entered.
// Checks userList to validate user and password.
// If valid, sets currentUser to this User, outputs welcome message,
// then returns true.
// Otherwise outputs error message and then repeats request
// for username/password.
// Continues until valid user/password
// or until 'q' or 'Q' is entered for username.
// If 'q' or 'Q' is entered, does not ask for password, outputs "Bye!"
// and then returns false.
bool BBoard::login() {
  cout << "Welcome to " << title << endl;
  while (true) {
    string uName, uPass;
    cout << "Enter your username ('Q' or 'q' to quit): " << endl;
    cin >> uName;

    if (uName == "Q" || uName == "q") {
      cout << "Bye!" << endl;
      return false;
    }

    cout << "Enter your password: " << endl;
    cin >> uPass;

    if (userExists(uName, uPass)) {
      currentUser = User(uName, uPass);
      cout << "Welcome back " << uName << "!" << endl;
      return true;
    }

    cout << "Invalid Username or Password!" << endl << endl;
    //
  }
}

// Contains main loop of Bulletin Board.
// First verifies a User has been logged in.
// Exits **function** immediately if no User logged in (Default User).
// Continues to display menu options to user and performs requested action
// until user chooses to quit.
// See output samples for exact format of menu.
void BBoard::run() {

  if (currentUser.getUsername() != "") {
    string action;

    while (true) {
      cout << endl;
      cout <<
      "Menu" << endl <<
      "- Display Messages ('D' or 'd')" << endl <<
      "- Add New Message ('N' or 'n')" << endl <<
      "- Quit ('Q' or 'q')" << endl <<
      "Choose an action: " << endl;
      cin >> action;

      if (action == "D" || action == "d") {
        display();
      }
      else if (action == "N" || action == "n") {
        addMessage();
      }
      else if (action == "Q" || action == "q") {
        cout << "Bye!" << endl;
        //
        return;
      }
    }
  }
  return;
}

// private:
void BBoard::display() const {
  if (messageList.size() == 0) {
    cout << "Nothing to Display." << endl;
    //
    return;
  }
  cout << "---------------------------------------------------------" << endl;
  for (unsigned int i = 0; i < messageList.size(); ++i) {
    cout <<
            "Message #" << (i + 1) << ": ";
    messageList.at(i).display();
    cout << "---------------------------------------------------------" << endl;
  }
}

void BBoard::addMessage() {
  string subject;
  string body;

  /* Note: Why don't you need cin.ignore() behind each cin statement?
     Because cin discards leading whitespace. So each previous \n was discarded
     except there is one \n before getline and because getline doesn't discard
     leading whitespace we need cin.ignore() */
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter Subject: ";
  getline(cin, subject);
  cout << endl;
  cout << "Enter Body: ";
  getline(cin, body);
  cout << endl;
  cout << "Message Recorded!" << endl;
  //

  Message newMess(currentUser.getUsername(), subject, body);
  messageList.push_back(newMess);
}

bool BBoard::userExists(const string& uName, const string& uPass) const {
  for (unsigned int i = 0; i < userList.size(); ++i) {
    if (userList.at(i).getUsername() == uName) {
      if (userList.at(i).check(uName, uPass)) {
        //currentUser = userList.at(i);
        //Note: It doesn't work not because of the implicitly created copy constructor,
        //but because the function is a const function you donut. Maybe you should
        //stop coding in half screen.
        return true;
      }
    }
  }
  return false;
}
