//BBoard.h

#ifndef BBOARD_H
#define BBOARD_H

#include <string>
#include <vector>

#include "Message.h"
#include "User.h"

class BBoard {
 private:
    std::string title;
    std::vector<User> userList;
    User currentUser;
    std::vector<Message> messageList;

 public:
    // Constructs a board with a default title,
    // empty user & message lists,
    // and the "default" User
    BBoard();

    // Same as the default constructor except
    // it sets the title of the board
    BBoard(const std::string&);

    // Imports all the authorized users from an input file,
    // storing them as User objects in the vector userList
    // The name of the input file is passed in as a parameter to this function.
    // See below for file format.
    bool loadUsers(const std::string&);

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
    bool login();

    // Contains main loop of Bulletin Board.
    // First verifies a User has been logged in.
    // Exits **function** immediately if no User logged in (Default User).
    // Continues to display menu options to user and performs requested action
    // until user chooses to quit.
    // See output samples for exact format of menu.
    void run();

 private:
    void display() const;
    void addMessage();
    bool userExists(const std::string&, const std::string&) const;
};

#endif
