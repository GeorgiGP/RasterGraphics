#pragma once
#include "../Manage.h"

class Save : public Manage
{
public:
	Save(ListOfSessions*& list);
	Save(const Save&) = delete;
	Save& operator=(const Save&) = delete;

	void execute() override;
};

