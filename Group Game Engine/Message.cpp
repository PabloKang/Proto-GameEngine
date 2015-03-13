#include "Message.h"


Message::Message(std::string to_whom, long delay)
: do_what{to_whom}
{
	timeStamp = delay;
}

Message::~Message(){}

// TimeStamp should equal 
// long t = static_cast<long> time(NULL);
void Message::setTimeStamp(long timeStam)
{
	timeStamp = timeStam;
}


long Message::getTimeStamp() const
{
	return timeStamp;
}


std::string Message::getStringMessage() const
{
	return do_what;
}


bool Message::operator == (const Message& rhs) const{
	if (do_what != rhs.getStringMessage())
		return false;
	if (timeStamp != rhs.getTimeStamp())
		return false;

	return true;
}
bool Message::operator != (const Message& rhs) const{
	return !(*this == rhs);
}
bool Message::operator <= (const Message& rhs) const{
	return timeStamp <= rhs.getTimeStamp();
}
bool Message::operator < (const Message& rhs) const{
	return timeStamp < rhs.getTimeStamp();
}
bool Message::operator >= (const Message& rhs) const{
	return rhs <= *this;
}
bool Message::operator > (const Message& rhs) const{
	return rhs < *this;
}



