#include "Message.h"


Message::Message(std::string to_who, std::string do_wha, long delay)
: to_whom{ to_who }, do_what{ to_who }, timeStamp{delay}
{
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

std::string Message::getToWhom() const
{
	return to_whom;
}

std::string Message::getDoMessage() const
{
	return do_what;
}


bool Message::operator == (const Message& rhs) const{
	if (do_what != rhs.getDoMessage())
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



