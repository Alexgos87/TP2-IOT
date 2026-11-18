#include "states/ProgramEntryState.h"
#include "states/ProgramConfirmState.h"
#include "gestionMatrice.h"
#include "gestionCode.h"

ProgramEntryState::ProgramEntryState(ChestStateMachine& stateMachine)
  : stateMachine(stateMachine) {}

void ProgramEntryState::enter() {
  flashMatrix(matrix.Color(255, 165, 0), true);
  startEnteringCode();
}

void ProgramEntryState::update() {
  if (enterCode()) stateMachine.changeState(new ProgramConfirmState(stateMachine, code));
}
