#pragma once
#include "Manage.h"
#include "RotateRight.h"
class AddRotateRight : public Manage
{
public:
	AddRotateRight(ListOfSessions*& list);
	void execute() override;
};
