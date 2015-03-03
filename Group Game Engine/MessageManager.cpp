#include "Star Hornet.h"


MessageManager::MessageManager(Message *message)
{
	messages = message;
}

Message MessageManager::getMessage(Scene item)
{
	return this->messages[0];
}

// Engine Functions
void MessageManager::interpret_all(int *message_ids)
{

}