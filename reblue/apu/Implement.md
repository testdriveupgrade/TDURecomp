# Audio System Tasks

Edge of Time may use different channel layouts or audio initialization. Work here includes:

- Update `SDL_SetHint` values to use the Edge of Time name.
- Verify the audio callback behaves correctly with Edge of Time's XMA streams.
- Fix any buffer boundary issues when streaming music or sound effects.
