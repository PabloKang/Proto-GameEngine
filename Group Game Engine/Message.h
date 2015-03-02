#pragma once

#include "Star Hornet.h"


class Message{
public:
	Message(int message_id);
	~Message();

	// Used in interpret_all
	int interpret(int message_id);
};

