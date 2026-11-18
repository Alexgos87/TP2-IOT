#pragma once
#include "IChestState.h"
#include "ChestStateMachine.h"

class WrongCodeState : public IChestState {
public:
  WrongCodeState(ChestStateMachine& stateMachine);
  void enter() override;
  void update() override;

private:
  ChestStateMachine& stateMachine;
};
