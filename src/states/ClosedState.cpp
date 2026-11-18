#include "states/ClosedState.h"
#include "states/ChestStateMachine.h"
#include "states/OpenState.h"
#include "states/WrongCodeState.h"
#include "gestionMatrice.h"
#include "gestionCode.h"
#include "gestionServo.h"
#include "gestionFirestore.h"

ClosedState::ClosedState(ChestStateMachine& stateMachine)
  : stateMachine(stateMachine) {}

void ClosedState::enter() {
  fillMatrix(matrix.Color(255, 0, 0));
  startEnteringCode();
}

void ClosedState::update() {
  if (enterCode()) {
    display.clear();
    if (sameCode(code, savedCode)) {
      unlockServo();
      stateMachine.changeState(new OpenState(stateMachine));
      logEvent("OUVERTURE");
    } else {
      stateMachine.changeState(new WrongCodeState(stateMachine));
    }
  }
}
