#pragma once

#include "Star Hornet.h"

class MessageManager
{
public:

	// Engine Constructors
	MessageManager();
	~MessageManager();

	int getTopMessage();

	// Engine Functions
	void interpret_all();

	// returns message that was sent for debugging purposes
	Message send_to(Message message, std::queue<Message> class_queue);

	std::priority_queue<Message> messages;
};