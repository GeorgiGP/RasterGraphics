#pragma once
#include "../Manage.h"
#include "../Transformations/Specific/Negative.h"
class AddNegative : public Manage
{
public:
	AddNegative(ListOfSessions*& list);
	void execute() override;
};

