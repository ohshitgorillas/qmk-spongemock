# SpongeMock: mOCkInG tExT for QMK
SpongeMock is a QMK community mod that RandomlY CapItalIzes leTters to mimic the SpongeBob mocking meme.

It works by intercepting alphanumeric keys and randomly applying left shift.

## Adding SpongeMock To Your Keymap
1.  Add the spongemock module to your QMK directory.

    **Option A: Git Submodule (Recommended)**
    ```bash
    cd <qmk directory>
    git submodule add <your-repo-url> modules/ohshitgorillas/spongemock
    ```

    **Option B: Manual Download**
    
    Create a new folder at the following path inside your QMK firmware directory:
    ```
    <qmk directory>/modules/ohshitgorillas/spongemock/
    ```
    Place `spongemock.c`, `spongemock.h`, `qmk_module.json`, and `readme.md` inside this folder.

2.  Add the following to your `keymap.json` file:

```json
{
    "modules": [
        "ohshitgorillas/spongemock"
    ]
}
```

3. Include a way to activate SpongeMock in your `keymap.c` file.

There are two ways to activate SpongeMock: using the built-in keycodes, or by calling the functions directly. These are discussed below.

Once active, RandoM letTers will bE CapitalIZEd until the mode is disabled.

## Built-In Keycodes (easy)
Add the following keycodes to your layout in `keymap.c`:
- `SPONGEMOCK_TOGGLE` [alias `SM_TOGG`]: Toggles SpongeMock mode.
- `SPONGEMOCK_ON` [alias `SM_ON`]: Turns SpongeMock mode on.
- `SPONGEMOCK_OFF` [alias `SM_OFF`]: Turns SpongeMock mode off.

## Use the Functions (advanced)
Call one of the SpongeMock buttons directly, either through a leader key, macros, or otherwise.

Leader key example:
```c
void leader_end_user(void) {
  // Leader + S, M
  if (leader_sequence_two_keys(KC_S, KC_M)) {
    toggle_spongemock();
  }
}
```

The functions available for your `keymap.c` are described below.

### enable_spongemock
```c
void enable_spongemock(void);
```
Enables SpongeMock mode.

### disable_spongemock
```c
void disable_spongemock(void);
```
Disables SpongeMock mode.

### toggle_spongemock
```c
void toggle_spongemock(void);
```
Toggles SpongeMock mode.

### is_spongemock_active
```c
bool is_spongemock_active(void);
```
Returns true if SpongeMock is active.
