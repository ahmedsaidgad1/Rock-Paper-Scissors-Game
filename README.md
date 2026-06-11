# ✂️ Rock Paper Scissors (C++)

A console-based Rock Paper Scissors game built in C++ with multi-round support, score tracking, and color-coded results.

## 📸 Preview

```
Enter number of rounds [ 1 to 10 ] : 3

==================== Round [1] ======================
Enter your Choice [1]Stone, [2]Paper, [3]Scissors: 1
Player choice       : Stone
Computer choice     : Scissors
Result              : Player Wins!

==================== Round [2] ======================
Enter your Choice [1]Stone, [2]Paper, [3]Scissors: 2
Player choice       : Paper
Computer choice     : Paper
Result              : Draw!

=============================================
              GAME OVER - FINAL RESULTS
=============================================
Total Rounds Played : 3
---------------------------------------------
Player Wins   : 2
Computer Wins : 0
Draws         : 1
---------------------------------------------
CONGRATULATIONS! YOU ARE THE FINAL WINNER! .

Do you want to play again? (y/n):
```

## ✨ Features

- **Multi-Round Mode** — Choose between 1 to 10 rounds per game
- **Color-Coded Console** — Green for win, Red for loss, Yellow for draw
- **Sound Alert** — Beep sound when the computer wins
- **Score Tracking** — Tracks wins, losses, and draws across all rounds
- **Input Protection** — Handles invalid input (letters instead of numbers) without crashing
- **Play Again** — Replay without restarting the program

## 🛠️ How to Build & Run

### Requirements
- C++ compiler (g++ / MSVC / Clang)
- Windows (for `system("color ...")` console coloring)

### Compile
```bash
g++ -o rps_game main.cpp
```

### Run
```bash
./rps_game
```

## 🗂️ Project Structure

```
rock-paper-scissors-cpp/
│
├── main.cpp       # Full source code
└── README.md
```

## 🧠 Game Logic

| Player    | Computer  | Result        |
|-----------|-----------|---------------|
| Stone     | Scissors  | Player Wins   |
| Paper     | Stone     | Player Wins   |
| Scissors  | Paper     | Player Wins   |
| Any       | Same      | Draw          |
| Otherwise | —         | Computer Wins |

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
