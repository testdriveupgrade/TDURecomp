## Test Drive Unlimited Recomp (TDUR)
<p align="center">
<img src="https://raw.githubusercontent.com/testdriveupgrade/TDU_rev/refs/heads/main/tdur2.jpg" width="512"/>
 </p>
Recompiled port of Test Drive Unlimited (TDU) 2006 XBOX 360. 

## Why we should work on it?
I have a wish to return the amazing moments, when we was young.
When I was a child it was one of my favourite games, but when I hadn't been enough competent in PC, due to I hadn't played online mode,
but when I remembered about this game, it was to late, servers was closed...
I think, what I'm not alone with this wish...
Now I'm a programmer (in specialities of C++ 3D graphics and nets) and I've no through out this idea out of my mind. 
Then, I'll try to close this goal.

## Advantages of this project:
1)We can understand how works online mode and remake servers for PC and XBox 360

2)Easier and better modding with understanding of source code

3)Port of this game to Mac and Linux (later)

4)Possibility to create global mods for PC and XBox verison 

5)360-version have some new cars, which we are easier to convert to PC-version (and add new cars)

6)360 Graphics sometimes a bit better, due to special shaders (like mw 360 vs PC version)

7)Sequel maybe modified (at this moment fan-made online is not exist on XBOX 360 version, only on PC and PS3 versions) 

In conclusion, we will add 4K, RTX, DLSS and etc. cool modern things and solve the problems with online, traffic AI and CPU-usage

**This project is not a replacement for the game (you still need to own a legal copy of the game); and does not provide any game assets!**
**You should dump your DVD and prepare for this port**

XenonRecompUnlimited - it's special fork of XenonRecomp for TDU engine, like experimental fork-version with fresh updates
 (unfortunattely at this moment XenonRecomp updates long-term :( ) https://github.com/testdriveupgrade/XenonRecompUnlimited

## Project 
Windows 10,11 (32/64)bit
DirectX12+SDL3 C++ 32bit(XenonRecomp target recomp:)

(also Vulkan+SDL3 64bit, but a bit later (and maybe Rust as alternative language), but not soon ?earlier than XenonRecomp will recompile for MacOS and Linux)

**If you specialist in Vulkan, Vulkan pipeline would be greatly appreciated (XenosRecomp suppor tboth recomp to DX12 and Vulkan shaders)**

Goals of the project 

1)kickstart recompiled version

2)convert recompiled machine C++ to "readable" C++

3)understand the net-code and make new server

4)add new graphics

## Project Status
1)Enter to the load screen
2)load 3D
3)load audio
4)test net races



## Setup & Build Configuration

Begin by pointing the build system to `rebluelib/config/EOTConfig.toml` instead of the current Unleashed configuration. Adjust CMake presets accordingly.

Temporarily remove Sonic-specific source files from the CMake lists to ensure the build can compile with TDU pieces first.

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

**Expected Outcome:** TDU graphics render correctly using cached shaders; the renderer initializes without errors.

## Audio & Input

Adjust the APU driver (`reblue/apu/driver`) for any audio format differences and verify buffering logic.

Test HID driver changes for controller differences under `reblue/hid/driver`.

**Expected Outcome:** Audio plays properly and controllers respond as expected.

## Resources and Localization

Replace fonts, images, music, and sounds in `resources/` with TDU assets.

Update localization strings and Windows resources (`reblue/res` and `reblue/res/win32`) so everything references Edge of Time.

**Expected Outcome:** The in-game UI uses TDU branding and assets.

## Tools & Scripts

Update the tools in `tools/` (e.g., `bc_diff`, `fshasher`, `x_decompress`) to handle TDU’s data formats.

Use scripts under `scripts/` for automated extraction and building of game data, modifying them for TDU where necessary.

**Expected Outcome:** Tools correctly process TDU archives and produce the files needed for the game to run.

## Debugging & Labeling

Use the IDA/ghidra scripts in `scripts/ida` to label functions in the TDU binary, aiding debugging when the runtime throws exceptions.

**Expected Outcome:** When a crash occurs, call stacks and debug logs give clear function names, making further fixes straightforward.

## Final Verification

Once all subsystems build and basic functionality works, run through the game to identify remaining issues—such as unimplemented kernel calls, boundary bugs, or missing shaders.

**Expected Outcome:** The PC build loads Edge of Time content and runs with minimal issues. After verifying all features (graphics, sound, input, progression), you can reintroduce or optimize any Sonic-specific elements you may have temporarily removed during initial porting.

Proceeding in this order ensures that the core runtime compiles and loads TDU assets first, then gradually expands support for graphics, audio, and other subsystems. Each stage builds upon the previous one, allowing you to confirm stability before moving on.
