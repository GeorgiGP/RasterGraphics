#pragma once
#include "Command.h"
class Help : public Command
{
	void printInfo() const;
public:
	Help() = default;
	Help(const Help&) = delete;
	Help& operator=(const Help&) = delete;

	void execute() override;
};

