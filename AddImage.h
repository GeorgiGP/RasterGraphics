#pragma once
#include "Manage.h"

class AddImage : public Manage
{
	Image* img = nullptr;

public:
	AddImage(ListOfSessions*& list, Image* img);
	AddImage(const AddImage&) = delete;
	AddImage& operator=(const AddImage&) = delete;

	void execute() override;

	~AddImage();
};

