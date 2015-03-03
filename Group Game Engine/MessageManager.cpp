#include "Star Hornet.h"


MessageManager::MessageManager()
{
}

int MessageManager::getTopMessage()
{
	return messages.top().message_id;
}


Message MessageManager::send_to(Message message, std::queue<Message> class_queue)
{
	class_queue.push(message);
}

// Engine Functions
void MessageManager::interpret_all()
{
	std::queue<Message> queue_from_class;
	while (!messages.empty())
	{
		if (messages.top().message_id == 1010101){
			send_to(messages.top(), queue_from_class);
		}
		messages.pop();
	}
}