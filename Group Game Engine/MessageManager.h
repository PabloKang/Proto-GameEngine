#pragma once

#include "Star Hornet.h"

class MessageManager
{
public:

	// Engine Constructors
	MessageManager(Message *messages);
	~MessageManager();

	Message getMessage(Scene item);

	// Engine Functions
	void interpret_all(int *message_ids);

private:
	Message * messages;
	int *message_ids;
};