#pragma once
#include "../Manage.h"
#include "../../Sessions/ElementsSession/Image/Image.h"
#include "../../Collection.hpp"

class Load : public Manage
{
	Collection<Image> images;
public:
	Load(ListOfSessions*& receiver);
	Load(const Load&) = delete;
	Load& operator=(const Load&) = delete;

	void addImage(const char* img);

	void execute() override;
};

