#pragma once
#include "../Manage.h"
#include "../../Sessions/ElementsSession/Image/Image.h"
class HorizontalCollage :public Manage
{
	Image* lhs;
	Image* rhs;
	char* collageFileName = nullptr;

public:
	HorizontalCollage(ListOfSessions*& list, Image* lhs, Image* rhs, const char* collageFileName);
	HorizontalCollage(const HorizontalCollage&) = delete;
	HorizontalCollage& operator=(const HorizontalCollage&) = delete;

	void execute() override;

	~HorizontalCollage();
};

