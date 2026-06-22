#include <Keyboard.h>

const int buttons[] = {4, 5, 6, 7, 8};

bool lastState[5] = {HIGH, HIGH, HIGH, HIGH, HIGH};

void setup() {

  for (int i = 0; i < 5; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  Keyboard.begin();
}

void loop() {

  for (int i = 0; i < 5; i++) {

    bool currentState = digitalRead(buttons[i]);

    if (currentState == LOW && lastState[i] == HIGH) {

      switch (i) {

        case 0: // Copy
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('c');
          delay(20);
          Keyboard.releaseAll();
          break;

        case 1: // Paste
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('v');
          delay(20);
          Keyboard.releaseAll();
          break;

        case 2: // Discord Mute
          Keyboard.press(KEY_F13);
          delay(20);
          Keyboard.releaseAll();
          break;

        case 3: // Discord Deafen
          Keyboard.press(KEY_F14);
          delay(20);
          Keyboard.releaseAll();
          break;

        case 4: // OBS Replay Buffer
          Keyboard.press(KEY_F15);
          delay(20);
          Keyboard.releaseAll();
          break;
      }
    }

    lastState[i] = currentState;
  }
}