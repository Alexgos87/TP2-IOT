#pragma once
#include "IChestState.h"

extern bool isBLongPressed;
extern bool isAJustPressed;

class ChestStateMachine {
public:
  void start(IChestState* firstState);
  void update();
  void changeState(IChestState* newState);

private:
  IChestState* currentState = nullptr;
};