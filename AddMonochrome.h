#pragma once
#include "Manage.h"
#include "Monochrome.h"
class AddMonochrome : public Manage
{
public:
	AddMonochrome(ListOfSessions*& list);
	void execute() override;
};
