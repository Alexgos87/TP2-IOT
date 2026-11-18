#pragma once
#include "IChestState.h"
#include "ChestStateMachine.h"

class ProgramEntryState : public IChestState {
public:
  ProgramEntryState(ChestStateMachine& stateMachine);
  void enter() override;
  void update() override;

private:
  ChestStateMachine& stateMachine;
};
