# mcpmux

**mcpmux** is a minimalist terminal-based TTRPG shell designed for multiplayer GPT-assisted roleplay over SSH. It allows players to connect to a host-managed session and use structured commands to interact with GPT as a shared narrator.

---

## 🚀 Current Features

- Modular REPL loop (`--client` mode)
- `/help`, `/look`, `/whereami`, `/quit` commands
- World scaffold with room name and description
- Command logging to `sessions/world_state.txt`
- Role-based execution:
  - `--server`: runs GPT routing server (stub for now)
  - `--client`: launches interactive REPL
- Command routing and string utilities
- Fully modular C architecture with separate components

---

## 📦 Project Structure

```
mcpmux/
├── Makefile
├── sessions/               # Game log outputs
├── python/                 # (Future) GPT bridge handler
├── src/                    # Core C code
│   ├── main.c              # Role parser + launcher
│   ├── shell_interface.c/h # Prompt and input
│   ├── log.c/h             # Logging system
│   ├── command.c/h         # Command routing
│   ├── utils.c/h           # String helpers
│   ├── world.c/h           # World state scaffold
│   └── gpt.c/h             # (Planned) GPT subprocess routing
```

---

## 🧪 Running the Project

Build the project:

```bash
make
```

Run as a **client**:

```bash
./mcpmux --client
```

Run as a **server** (GPT handler stub):

```bash
./mcpmux --server
```

---

## 💬 Commands

- `/help` – list available commands
- `/look` – describes current room
- `/whereami` – shows room name
- `/rp <message>` – (coming soon) send message to GPT
- `/quit` – exit program

---

## 🔮 Planned Features

- Python GPT bridge via subprocess or socket
- Server-side input queue and GPT output broadcast
- Named player identity per session
- Save/load world state from disk
- `/end` command for session recap via GPT
- Full multi-user support with Unix sockets or pipes

---

## 📜 License

This project is licensed under the MIT License.  
© 2025 forgnath  
See the LICENSE file for details.
