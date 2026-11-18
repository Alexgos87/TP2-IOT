#include "states/WrongCodeState.h"
#include "states/ClosedState.h"
#include "gestionMatrice.h"

WrongCodeState::WrongCodeState(ChestStateMachine& stateMachine)
  : stateMachine(stateMachine) {}

void WrongCodeState::enter() {
  flashMatrix(matrix.Color(255, 0, 0));
}

void WrongCodeState::update() {
  if (!isFlashing()) stateMachine.changeState(new ClosedState(stateMachine));
}
