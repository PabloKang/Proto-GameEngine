#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include "Star Hornet.h"
#include "Message.h"
#include "Scene.h"

struct MessageCompare : public std::binary_function<Message&, Message&, bool>
{
	bool operator()(const Message& lhs, const Message& rhs) const
	{
		return lhs < rhs;
	}
};

typedef std::priority_queue<Message, std::vector<Message>, MessageCompare> message_queue;



class MessageManager
{
public:

	// Engine Constructors
	MessageManager();
	~MessageManager();

	Message& getTopMessage();

	// Queue functionality
	void send_to(Message message);

	void pop();

private:
	message_queue messages;
	long timeStamp;
};

#endif