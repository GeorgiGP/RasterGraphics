#pragma once
#include <iostream>
#include "../Commands/Command.h"

#include "../Commands/Specific/Load.h"
#include "../Commands/Specific/AddImage.h"
#include "../Commands/Specific/SaveAs.h"
#include "../Commands/Specific/Save.h"
#include "../Commands/Help.h"
#include "../Commands/Specific/CloseImage.h"
#include "../Commands/Specific/CloseSession.h"
#include "../Commands/Specific/Exit.h"
#include "../Commands/Specific/Undo.h"
#include "../Commands/Specific/SessionInfo.h"
#include "../Commands/Specific/SwitchSession.h"
#include "../Commands/Specific/HorizontalCollage.h"
#include "../Commands/Specific/VerticalCollage.h"
#include "../Commands/Specific/AddGrayscale.h"
#include "../Commands/Specific/AddMonochrome.h"
#include "../Commands/Specific/AddRotateLeft.h"
#include "../Commands/Specific/AddRotateRight.h"
#include "../Commands/Specific/AddNegative.h"


AddRotateRight* createRotateRight(ListOfSessions*& list);

AddRotateLeft* createRotateLeft(ListOfSessions*& list);

AddNegative* createNegative(ListOfSessions*& list);

AddMonochrome* createMonochrome(ListOfSessions*& list);

AddGrayscale* createGrayscale(ListOfSessions*& list);

VerticalCollage* createVerticalCollage(ListOfSessions *& list, std::stringstream & ss);

HorizontalCollage* createHorizontalCollage(ListOfSessions *& list, std::stringstream & ss);

SwitchSession* createSwitchSession(ListOfSessions *& list, std::stringstream & ss);

SessionInfo* createSessionInfo(ListOfSessions*& list);

Undo* createUndo(ListOfSessions*& list);

Exit* createExit(ListOfSessions*& list);

CloseSession* createCloseSession(ListOfSessions*& list, std::stringstream & ss);

CloseImage* createCloseImage(ListOfSessions*& list);

Help* createHelp();

Save* createSave(ListOfSessions*& list);

SaveAs* createSaveAs(ListOfSessions*& list, std::stringstream& ss);

AddImage* createAdd(ListOfSessions*& list, std::stringstream& ss);

Load* createLoad(ListOfSessions*& list, std::stringstream& ss);

Command* createCommand(ListOfSessions*& list);

