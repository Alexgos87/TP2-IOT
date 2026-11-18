#include "states/ProgramConfirmState.h"
#include "states/CodesMatchState.h"
#include "states/CodesMismatchState.h"
#include "gestionCode.h"
#include "gestionFirestore.h"

ProgramConfirmState::ProgramConfirmState(ChestStateMachine& stateMachine, const int firstCode[4])
  : stateMachine(stateMachine) {
  for (int i = 0; i < 4; i++) this->firstCode[i] = firstCode[i];
}

void ProgramConfirmState::enter() {
  startEnteringCode();
}

void ProgramConfirmState::update() {
  if (enterCode()) {
    display.clear();
    if (sameCode(code, firstCode)) {
      for (int i = 0; i < 4; i++) savedCode[i] = code[i];
      stateMachine.changeState(new CodesMatchState(stateMachine));
      logEvent("CHANGEMENT_CODE");
    } else {
      stateMachine.changeState(new CodesMismatchState(stateMachine));
    }
  }
}
