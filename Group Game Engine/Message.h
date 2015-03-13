#ifndef MESSAGE_H
#define MESSAGE_H

#include <ctime>
#include "Star Hornet.h"
//#include "MessageManager.h"

class Message{
public:
	Message(std::string to_whom, std::string do_what, long delay = 0);
	~Message();

	void setTimeStamp(long timeStamp);
	virtual long getTimeStamp() const;
	virtual std::string getToWhom() const;
	virtual std::string getDoMessage() const;

	virtual bool operator == (const Message& rhs) const;
	virtual bool operator != (const Message& rhs) const;
	virtual bool operator <= (const Message& rhs) const;
	virtual bool operator <  (const Message& rhs) const;
	virtual bool operator >= (const Message& rhs) const;
	virtual bool operator >  (const Message& rhs) const;

private:
	std::string to_whom;
	std::string do_what;
	long timeStamp;
	// add time and/or delay to send message 
};

#endif
