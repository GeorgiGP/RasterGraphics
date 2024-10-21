#pragma once
#include "../Manage.h"
#include "../Transformations/Specific/Grayscale.h"
class AddGrayscale : public Manage
{
public:
	AddGrayscale(ListOfSessions*& list);
	void execute() override;
};

