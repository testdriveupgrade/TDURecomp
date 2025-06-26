# Edge of Time Porting Notes

This repository currently targets **Sonic Unleashed**. To adapt it for *Spider-Man: Edge of Time* some high level tasks are required:

- Replace all references to the Unleashed XEX with the Edge of Time XEX.
- Update build scripts and configuration files with function addresses for the new game.
- Remove Sonic-specific assets and localisation entries.
- Review each subfolder for additional changes; see the Implement.md in each directory for specifics.

Known general work items:

- Start finding kernel call offsets.
- Fix boundary issues in guest memory handling.
- Ensure base XEX is mapped correctly so guest/host exchanges work.
- Strip Sonic specific code from everything except the GPU modules when starting.
- Label every possible function in Ghidra/IDA for easier debugging.
- Implement missing kernel calls and objects.
- Reverse engineer where shaders are and add extraction tooling.
- Extend the build system to run shader extraction and recompilation.
