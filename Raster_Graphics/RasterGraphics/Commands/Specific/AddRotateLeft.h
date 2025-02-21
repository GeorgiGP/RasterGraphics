#pragma once
#include "../Manage.h"
#include "../Transformations/Specific/RotateLeft.h"
class AddRotateLeft : public Manage
{
public:
	AddRotateLeft(ListOfSessions*& list);
	void execute() override;
};

