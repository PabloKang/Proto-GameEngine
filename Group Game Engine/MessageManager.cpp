#include "Star Hornet.h"
#include "MessageManager.h"
#include "Message.h"

MessageManager::MessageManager()
{
}

Message& MessageManager::getTopMessage()
{
	return messages.top();
}


void MessageManager::send_to(Message message, std::queue<Message> class_queue)
{
	class_queue.push(message);
}

// Engine Functions
void MessageManager::interpret_all()
{
	//std::queue<Message> queue_from_class; // This actually wont be here it would call the classes' actual queue. 
	//while (!messages.empty())
	//{
	//	if (messages.top().id == 1010101){
	//		send_to(messages.top(), queue_from_class); // here
	//	}
	//	messages.pop();
	//}
}