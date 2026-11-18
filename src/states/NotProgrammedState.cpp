#include "states/NotProgrammedState.h"
#include "states/ChestStateMachine.h"
#include "states/ProgramEntryState.h"
#include "gestionMatrice.h"
#include "gestionCode.h"

NotProgrammedState::NotProgrammedState(ChestStateMachine& stateMachine)
  : stateMachine(stateMachine) {}

void NotProgrammedState::enter() {
  fillMatrix(matrix.Color(0, 255, 0));
  display.clear();
}

void NotProgrammedState::update() {
  if (isBLongPressed) stateMachine.changeState(new ProgramEntryState(stateMachine));
}
