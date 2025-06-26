# Porting rebluelib to Edge of Time

`rebluelib` contains the recompiler and configuration used to load the original XEX. To target Edge of Time:

- Replace `private/default.xex` with the Edge of Time executable.
- Update `config/config.toml` with new PPC function addresses.
- Review `CMakeLists.txt` for any hard coded paths or Unleashed references.
- Enable shader extraction in the build once the pack format is understood.
