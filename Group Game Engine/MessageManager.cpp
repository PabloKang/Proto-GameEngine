#include "Star Hornet.h"
#include "MessageManager.h"
#include "Message.h"

MessageManager::MessageManager(){}

MessageManager::~MessageManager(){}


Message& MessageManager::getTopMessage()
{
	return messages.top();
}


void MessageManager::send_to(Message message)
{
	messages.push(message);
}

void MessageManager::pop()
{
	messages.pop();
}