#pragma once
#include "Manage.h"
class SessionInfo : public Manage
{
public:
	SessionInfo(ListOfSessions*& list);
	SessionInfo(const SessionInfo&) = delete;
	SessionInfo& operator=(const SessionInfo&) = delete;
	void execute() override;
};

