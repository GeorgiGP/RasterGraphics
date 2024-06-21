#pragma once
#include "Manage.h"
class CloseSession : public Manage
{
	unsigned id = 0;
public:
	CloseSession(ListOfSessions*& list, unsigned id);
	CloseSession(const CloseSession&) = delete;
	CloseSession& operator=(const CloseSession&) = delete;
	void execute() override;
};

