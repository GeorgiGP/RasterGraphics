#pragma once
#include "Manage.h"
class SwitchSession : public Manage
{
	unsigned id = 0;
public:
	SwitchSession(ListOfSessions*& list, unsigned id);
	SwitchSession(const SwitchSession&) = delete;
	SwitchSession& operator=(const SwitchSession&) = delete;
	void execute() override;
};

