#ifndef MESSAGE_H
#define MESSAGE_H

#include <ctime>
#include "Star Hornet.h"
//#include "MessageManager.h"

class Message{
public:
	Message(std::string to_whom, long delay = 0);
	~Message();

	void setTimeStamp(long timeStamp);
	virtual long getTimeStamp() const;
	virtual std::string getStringMessage() const;

	virtual bool operator == (const Message& rhs) const;
	virtual bool operator != (const Message& rhs) const;
	virtual bool operator <= (const Message& rhs) const;
	virtual bool operator <  (const Message& rhs) const;
	virtual bool operator >= (const Message& rhs) const;
	virtual bool operator >  (const Message& rhs) const;

private:
	std::string do_what;
	long timeStamp;
	// add time and/or delay to send message 
};

#endif
