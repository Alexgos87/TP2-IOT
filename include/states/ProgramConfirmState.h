#pragma once
#include "IChestState.h"
#include "ChestStateMachine.h"

class ProgramConfirmState : public IChestState {
public:
  ProgramConfirmState(ChestStateMachine& stateMachine, const int firstCode[4]);
  void enter() override;
  void update() override;

private:
  ChestStateMachine& stateMachine;
  int firstCode[4];
};
