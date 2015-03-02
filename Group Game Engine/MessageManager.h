#pragma once

#include "Star Hornet.h"

class MessageManager
{
public:
	std::string resPath;

	// Engine Constructors
	MessageManager(SceneManager scenes);
	~MessageManager();

	Message getMessage(Scene item);

	// Engine Functions
	void interpret_all(int *message_ids);

private:
	SceneManager scenes;
};