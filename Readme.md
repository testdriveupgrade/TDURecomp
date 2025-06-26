# Roadmap

## Setup & Build Configuration

Begin by pointing the build system to `rebluelib/config/EOTConfig.toml` instead of the current Unleashed configuration. Adjust CMake presets accordingly.

Temporarily remove Sonic-specific source files from the CMake lists to ensure the build can compile with EOT pieces first.

**Expected Outcome:** A basic build that compiles using the Edge of Time configuration, even if it doesn’t run yet.

## Runtime Path Updates

Modify `reblue/main.cpp` and `reblue/user/paths.h` to reference the Edge of Time game directory and user folder.

Update registry strings and any hard-coded paths under `reblue/os/win32` or `reblue/os/linux`.

**Expected Outcome:** The executable looks for Edge of Time files and creates/reads user data from the new directory.

## Kernel & CPU Adjustments

Fill in or adjust kernel call offsets in the configuration files under `rebluelib/config`.

Implement missing kernel functions or objects in `reblue/kernel` (and subfolders) if Edge of Time relies on them.

Verify guest thread creation, stack sizes, and memory mapping within `reblue/cpu`.

**Expected Outcome:** The game’s guest code can run against the emulated kernel without crashing due to missing calls or mismatched addresses.

## GPU & Shader Work

Strip out Unleashed-specific hacks from `reblue/gpu`.

Integrate shader extraction and caching logic described in `reblue/gpu/shader` and `tools/*` (e.g., using quickbms, file_to_c, and cache tools).

Ensure pipeline caches (`reblue/gpu/cache`) and the RHI layer (`reblue/gpu/rhi`) support Edge of Time’s render states.

**Expected Outcome:** EOT graphics render correctly using cached shaders; the renderer initializes without errors.

## Audio & Input

Adjust the APU driver (`reblue/apu/driver`) for any audio format differences and verify buffering logic.

Test HID driver changes for controller differences under `reblue/hid/driver`.

**Expected Outcome:** Audio plays properly and controllers respond as expected.

## Resources and Localization

Replace fonts, images, music, and sounds in `resources/` with EOT assets.

Update localization strings and Windows resources (`reblue/res` and `reblue/res/win32`) so everything references Edge of Time.

**Expected Outcome:** The in-game UI uses EOT branding and assets.

## Tools & Scripts

Update the tools in `tools/` (e.g., `bc_diff`, `fshasher`, `x_decompress`) to handle EOT’s data formats.

Use scripts under `scripts/` for automated extraction and building of game data, modifying them for EOT where necessary.

**Expected Outcome:** Tools correctly process EOT archives and produce the files needed for the game to run.

## Debugging & Labeling

Use the IDA/ghidra scripts in `scripts/ida` to label functions in the EOT binary, aiding debugging when the runtime throws exceptions.

**Expected Outcome:** When a crash occurs, call stacks and debug logs give clear function names, making further fixes straightforward.

## Final Verification

Once all subsystems build and basic functionality works, run through the game to identify remaining issues—such as unimplemented kernel calls, boundary bugs, or missing shaders.

**Expected Outcome:** The PC build loads Edge of Time content and runs with minimal issues. After verifying all features (graphics, sound, input, progression), you can reintroduce or optimize any Sonic-specific elements you may have temporarily removed during initial porting.

Proceeding in this order ensures that the core runtime compiles and loads EOT assets first, then gradually expands support for graphics, audio, and other subsystems. Each stage builds upon the previous one, allowing you to confirm stability before moving on.
