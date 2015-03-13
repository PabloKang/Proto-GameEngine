#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include "Star Hornet.h"
#include "Message.h"


class MessageManager
{
public:

	// Engine Constructors
	MessageManager();
	~MessageManager();

	Message& getTopMessage();

	// Engine Functions
	void interpret_all();

	// returns message that was sent for debugging purposes
	void send_to(Message message, std::queue<Message> class_queue);

	std::priority_queue<Message> messages;

private:
	long timeStamp;
};

#endif