# mastermind

Mastermind is a 2-player boardgame wherein one player the (Codemaster prepares a code of four colours from a set of six, and the other
player (Codebreaker) then repeatedly tries to guess the code and receives feedback from the Codemaster. The feedback given by the
Codemaster is in the form of white and black pegs where each white peg represents a correct colour in the wrong position and a black peg
represents a correct colour in the correct position.

Example: The following playGame call to a Mastermind object that was initialized with 5, 4, 3. L

Welcome to Mastermind! Please enter your first guess.
  >AAAA
  2b, 0w
  2 guesses left. Enter guess:
  >BCDE
  1b,0w
  1 guesses left. Enter guess:
  >bcaa
  3b,0w
  You lost! The password was:
  BFAA
  Would you like to play again? (Y/N): N
