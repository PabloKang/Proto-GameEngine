#pragma once

#include "Star Hornet.h"


class Message{
public:
	Message(int message_id);
	~Message();

	// Used in interpret_all
	int interpret();
private:
	int message_id;
};

