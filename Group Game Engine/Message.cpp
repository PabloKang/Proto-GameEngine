#include "Star Hornet.h"


Message::Message(int message_id, int time_send)
: time_to_send{ time_send }
{
}

int Message::interpret(MessageManager main_queue)
{
	main_queue.messages.push(*this);
}

