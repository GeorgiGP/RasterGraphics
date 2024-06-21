#pragma once
#include "Manage.h"
#include "Grayscale.h"
class AddGrayscale : public Manage
{
public:
	AddGrayscale(ListOfSessions*& list);
	void execute() override;
};

