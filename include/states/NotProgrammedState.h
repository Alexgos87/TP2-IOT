#pragma once
#include "IChestState.h"
#include "ChestStateMachine.h"

class NotProgrammedState : public IChestState {
public:
  NotProgrammedState(ChestStateMachine& stateMachine);
  void enter() override;
  void update() override;

private:
  ChestStateMachine& stateMachine;
};
