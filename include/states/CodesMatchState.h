#pragma once
#include "IChestState.h"
#include "ChestStateMachine.h"

class CodesMatchState : public IChestState {
public:
  CodesMatchState(ChestStateMachine& stateMachine);
  void enter() override;
  void update() override;

private:
  ChestStateMachine& stateMachine;
};
