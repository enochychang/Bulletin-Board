#include <iostream>
#include <string>

#include "Message.h"

using std::string;
using std::endl;
using std::cout;

// private:
// string author;
// string subject;
// string body;

// public:
// default constructor
Message::Message() : author(""), subject(""), body("") {};

// Parameterized constructor;
Message::Message(const string& athr,
      const string& sbjct,
      const string& body)
      : author(athr),
        subject(sbjct),
        body(body)
{};

// displays Message.
void Message::display() const {
  cout << subject << endl;
  cout << "from " << author << ": " << body << endl;
}
