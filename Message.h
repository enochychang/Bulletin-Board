//Message.h

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {

private:
	std::string author;
	std::string subject;
	std::string body;

public:
	// default constructor
	Message();

	// Parameterized constructor;
	Message(const std::string& athr,
	     const std::string& sbjct,
	     const std::string& body);

	// displays Message.
	void display() const;

};

#endif
