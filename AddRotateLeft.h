#pragma once
#include "Manage.h"
#include "RotateLeft.h"
class AddRotateLeft : public Manage
{
public:
	AddRotateLeft(ListOfSessions*& list);
	void execute() override;
};

