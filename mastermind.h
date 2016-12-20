#ifndef _MASTERMIND_H_
#define _MASTERMIND_H_

struct Mastermind {
  int seed;
  int codeLength;
  int guessLimit;
  char* code;
  Mastermind(int seed, int codeLength, int guessLimit);
  ~Mastermind();
  void playGame();
  void setPasscode();
};

#endif
