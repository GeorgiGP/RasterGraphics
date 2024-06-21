#include <iostream>
#include "FactorySessions.h"
#include "FactoryCommand.h"

int main()
{
	ListOfSessions* base = nullptr;
	while (!base)
	{
		try
		{
			factoryListOfSessions(base);
		}
		catch (std::exception& e)
		{
			if (!strcmp(e.what(), "exit"))
			{
				return 0;
			}
			std::cout << e.what();
		}
		catch (...)
		{
			std::cout << "Couldn't execute commant!";
		}
		
	}
	while (base)
	{
		Command* command = nullptr;
		try
		{
			command = createCommand(base);
			if (command)
			{
				command->execute();
				delete command;
				command = nullptr;
			}
			else
			{
				std::cout << "Invalid command!" << std::endl;
			}
			
		}
		catch (std::exception& e)
		{
			delete command;
			command = nullptr;
			std::cout << e.what();
		}
		catch (...)
		{
			delete command;
			command = nullptr;
			std::cout << "Couldn't execute commant!";
		}
	}

	

}
