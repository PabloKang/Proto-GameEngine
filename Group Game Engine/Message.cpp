#include "Star Hornet.h"


Message::Message(int message_id)
{
}

int Message::interpret(MessageManager main_queue)
{
	main_queue.messages.push(*this);
}

