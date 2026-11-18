#include "states/ChestStateMachine.h"

void ChestStateMachine::start(IChestState* firstState) {
  currentState = firstState;
  currentState->enter();
}

void ChestStateMachine::update() {
  currentState->update();
}

void ChestStateMachine::changeState(IChestState* newState) {
  currentState->exit();
  delete currentState;
  currentState = newState;
  currentState->enter();
}