#pragma once
#include "IChestState.h"
#include "ChestStateMachine.h"

class ClosedState : public IChestState {
public:
  ClosedState(ChestStateMachine& stateMachine);
  void enter() override;
  void update() override;

private:
  ChestStateMachine& stateMachine;
};
