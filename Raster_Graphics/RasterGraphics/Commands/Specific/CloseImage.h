#pragma once
#include "../Manage.h"
class CloseImage : public Manage
{
public:
	CloseImage(ListOfSessions*& list);
	CloseImage(const CloseImage&) = delete;
	CloseImage& operator=(const CloseImage&) = delete;
	void execute() override;
};

