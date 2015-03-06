#ifndef MESSAGE_H
#define MESSAGE_H

#include "Star Hornet.h"


class Message{
public:
	Message(int message_id, int time_send = 0);
	~Message();

	// Used in interpret_all this will send_to the priority queue in the manager
	int interpret(MessageManager main_queue);

	int message_id;

	int time_to_send;
	// add time and/or delay to send message 
};

#endif
