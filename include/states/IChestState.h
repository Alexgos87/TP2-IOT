#pragma once

class IChestState {
public:
  virtual ~IChestState() {}
  virtual void enter() {}
  virtual void update() = 0;
  virtual void exit() {}
};