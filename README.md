# 🎯 Guess The Number Game (C Project)

A fun and interactive **console-based number guessing game** written in C.  
The player has to guess a randomly generated number within a limited number of attempts depending on the selected difficulty level.

---

## 📌 Project Overview

This project demonstrates:
- Use of loops and conditional statements
- Random number generation
- File handling (for high score)
- Time tracking
- Basic user interface in terminal

---

## ✨ Features

- 🎮 Menu-driven system (Play / Exit)
- 🎚️ Three difficulty levels:
  - Easy → Range (1–10), 5 attempts
  - Medium → Range (1–50), 7 attempts
  - Hard → Range (1–100), 10 attempts
- 🔥 Smart hint system:
  - Very Hot (difference ≤ 3)
  - Warm (difference ≤ 10)
  - Cold (difference > 10)
- 📊 Guess history tracking
- ⏱️ Time taken to complete the game
- 🏆 High score system (stored in file)
- 🎨 Colored text (Windows only)
- ⏳ Loading animation
- 🔁 Replay option

---

## 🛠️ Technologies Used

- Language: **C**
- Libraries:
  - `stdio.h` → Input/Output
  - `stdlib.h` → Random numbers, memory, abs()
  - `time.h` → Time tracking & random seed
- OS Specific:
  - `windows.h` → Color & delay (Windows)
  - `unistd.h` → sleep() (Linux/macOS)

---

## 📂 File Structure

```
Guess-The-Number-Game/
│
├── game.c
├── high score.txt   (auto-created)
└── README.md
```

---

## 🚀 How to Compile & Run

### 🔹 Compile

```bash
gcc game.c -o game
```

### 🔹 Run (Linux / Mac)

```bash
./game
```

### 🔹 Run (Windows)

```bash
game.exe
```

---

## 🎮 Gameplay Instructions

1. Start the program
2. Choose **Play Game**
3. Select difficulty level
4. Enter your guesses
5. Follow hints:
   - 🔥 Very Hot → Very close
   - 🌤️ Warm → Close
   - ❄️ Cold → Far
6. Win by guessing correctly within attempts
7. Try to beat the best score!

---

## 🧠 Game Logic

- Random number is generated using:
  ```c
  srand(time(0));
  number = rand() % range + 1;
  ```

- Each guess:
  - Compared with actual number
  - Hint is given based on difference

- Game ends when:
  - Player guesses correctly OR
  - Attempts are finished

---

## 🏆 High Score System

- Stored in file:
  ```
  high score.txt
  ```
- Tracks **minimum attempts**
- Updated when player performs better

---

## ⏱️ Time Tracking

- Game start and end time recorded using:
  ```c
  time_t start, end;
  ```
- Total time calculated using:
  ```c
  difftime(end, start);
  ```

---

## 🎨 Color Feature

- Windows:
  - Uses `SetConsoleTextAttribute()`
- Linux/macOS:
  - Colors are not supported in current version

---

## ⚠️ Limitations

- No input validation (user must enter integers)
- Colors not supported on Linux/macOS
- File handling is basic
- UI is text-based only

---

## 💡 Future Improvements

- ✅ Input validation
- 🎵 Sound effects
- 🖥️ GUI version (using C++/Java/Python)
- 👥 Multiplayer mode
- 🌐 Online leaderboard
- 🎨 Cross-platform color support

---

## 👨‍💻 Author

**Shanto**

---

## 📜 License

This project is open-source and free for educational purposes.

---

## 🙌 Acknowledgement

This project is created as part of learning **C programming** and basic game development concepts.
