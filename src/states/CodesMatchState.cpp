#include "states/CodesMatchState.h"
#include "states/OpenState.h"
#include "gestionMatrice.h"

CodesMatchState::CodesMatchState(ChestStateMachine& stateMachine)
  : stateMachine(stateMachine) {}

void CodesMatchState::enter() {
  flashMatrix(matrix.Color(0, 255, 0));
}

void CodesMatchState::update() {
  if (!isFlashing()) stateMachine.changeState(new OpenState(stateMachine));
}
