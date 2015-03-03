#pragma once

#include "Star Hornet.h"


class Message{
public:
	Message(int message_id);
	~Message();

	// Used in interpret_all this will send_to the priority queue in the manager
	int interpret(MessageManager main_queue);

	int message_id;

};

