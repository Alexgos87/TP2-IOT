#include "states/OpenState.h"
#include "states/ChestStateMachine.h"
#include "states/ProgramEntryState.h"
#include "states/ClosedState.h"
#include "gestionMatrice.h"
#include "gestionCode.h"
#include "gestionServo.h"

OpenState::OpenState(ChestStateMachine& stateMachine)
  : stateMachine(stateMachine) {}

void OpenState::enter() {
  fillMatrix(matrix.Color(0, 255, 0));
  display.clear();
}

void OpenState::update() {
  if (isBLongPressed) {
    stateMachine.changeState(new ProgramEntryState(stateMachine));
  } else if (isAJustPressed) {
    lockServo();
    stateMachine.changeState(new ClosedState(stateMachine));
  }
}
