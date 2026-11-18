#pragma once
#include "IChestState.h"
#include "ChestStateMachine.h"

class OpenState : public IChestState {
public:
  OpenState(ChestStateMachine& stateMachine);
  void enter() override;
  void update() override;

private:
  ChestStateMachine& stateMachine;
};
