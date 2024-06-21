#pragma once
#include "Command.h"
#include <iostream>

#include "Load.h"
#include "AddImage.h"
#include "SaveAs.h"
#include "Save.h"
#include "Help.h"
#include "CloseImage.h"
#include "CloseSession.h"
#include "Exit.h"
#include "Undo.h"
#include "SessionInfo.h"
#include "SwitchSession.h"
#include "HorizontalCollage.h"
#include "VerticalCollage.h"
#include "AddGrayscale.h"
#include "AddMonochrome.h"
#include "AddRotateLeft.h"
#include "AddRotateRight.h"
#include "AddNegative.h"


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

