#pragma once
#include "../Manage.h"
class Undo : public Manage
{
public:
	Undo(ListOfSessions*& list);

	void execute() override;
};

