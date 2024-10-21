#pragma once
#include "../Manage.h"
#include "../Transformations/Specific/Monochrome.h"
class AddMonochrome : public Manage
{
public:
	AddMonochrome(ListOfSessions*& list);
	void execute() override;
};
