#ifndef MESSAGE_H
#define MESSAGE_H

#include "Star Hornet.h"
//#include "MessageManager.h"


class Message{
public:
	Message();
	~Message();

	void setTimeStamp(long time);
	long getTimeStamp();

	int id;
private:
	long timeStamp;
	// add time and/or delay to send message 
};

#endif
