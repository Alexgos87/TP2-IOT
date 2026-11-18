#include "states/CodesMismatchState.h"
#include "states/ChestStateMachine.h"
#include "states/ProgramEntryState.h"
#include "gestionMatrice.h"

CodesMismatchState::CodesMismatchState(ChestStateMachine& stateMachine)
  : stateMachine(stateMachine) {}

void CodesMismatchState::enter() {
  flashMatrix(matrix.Color(255, 0, 0));
}

void CodesMismatchState::update() {
  if (!isFlashing()) stateMachine.changeState(new ProgramEntryState(stateMachine));
}
