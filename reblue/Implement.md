# Porting reblue Runtime

The `reblue` folder contains the runtime used to launch the game. Changes needed for Edge of Time include:

- Update `main.cpp` to mount the Edge of Time content directory and load its XEX.
- Replace Unleashed titles and registry keys with Edge of Time equivalents.
- Remove or refactor Sonic specific UI and resource references.
- Ensure GPU and APU modules handle Edge of Time assets correctly.
- Additional kernel and memory mapping work may be required as offsets differ.
