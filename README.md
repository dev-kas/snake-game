# 🐍 Snake + DLL Injection Playground

A minimal 21×12 snake game… with a twist.

This repo isn’t just about playing snake — it’s a tiny sandbox for experimenting with **DLL injection, runtime manipulation, and game hacking (on your own code, chill)**.

---

## 📁 Project Structure

```
.
├── build.bat
├── exploit
│   ├── godmode
│   │   ├── build.bat
│   │   └── godmode.c
│   └── injector
│       ├── build.bat
│       └── injector.cpp
├── game
│   ├── build.bat
│   ├── compile_commands.json
│   └── main.c
├── LICENSE (MIT)
└── README.md
```

---

## 🎮 Game

* Classic snake
* Grid size: **21×12**
* Written in C
* Minimal, no overengineering (for once)

---

## 💉 Exploit System

This repo includes a basic DLL injection setup:

### `godmode.dll`

* Built from `godmode.c`
* Injected into the running game process
* Modifies behavior at runtime (aka “cheating but academically”)

### `injector.exe`

* Built from `injector.cpp`
* Generic DLL injector

#### Usage:

```
injector.exe <PID> <path_to_dll>
```

Example:

```
injector.exe 1234 godmode.dll
```

* `PID` → target process ID
* `path_to_dll` → DLL to inject

⚠️ This is a **generic injector**, meaning it can be used outside this project too. Don’t be stupid with it.

---

## 🛠️ Building

Each component has its own `build.bat`.

### Build everything (lazy mode):

```
build.bat
```

### Or manually:

#### Game

```
cd game
build.bat
```

#### Godmode DLL

```
cd exploit/godmode
build.bat
```

#### Injector

```
cd exploit/injector
build.bat
```

---

## 🚀 Usage Flow

1. Build the game and exploit tools
2. Run the snake game
3. Get its PID (Task Manager or your hacker brain)
4. Inject:

   ```
   injector.exe <PID> godmode.dll
   ```
5. Enjoy breaking your own game like a responsible chaos engineer

---

## ⚠️ Disclaimer

* This project is for **educational purposes only**
* Don’t use the injector on software you don’t own or have permission to test
* If you get banned somewhere, that’s on you 💀

---

## 🧠 Why This Exists

Because:

* Writing a game is fun
* Breaking your own game is *more* fun
* Understanding how memory manipulation works is useful

Also, let’s be honest — “I hacked my own snake game” sounds cooler than it should.

---

## 📜 License

MIT — do whatever you want, just don’t blame me when you start injecting into everything like it’s a personality trait.

*README.md generated with ChatGPT*
