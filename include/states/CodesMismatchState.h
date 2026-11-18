#pragma once
#include "IChestState.h"
#include "ChestStateMachine.h"

class CodesMismatchState : public IChestState {
public:
  CodesMismatchState(ChestStateMachine& stateMachine);
  void enter() override;
  void update() override;

private:
  ChestStateMachine& stateMachine;
};
