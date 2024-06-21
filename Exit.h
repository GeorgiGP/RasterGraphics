#pragma once
#include "Manage.h"
class Exit : public Manage
{
public:
	Exit(ListOfSessions*& list);
	Exit(const Exit&) = delete;
	Exit& operator=(const Exit&) = delete;
	void execute() override;
};

