[![Version](https://img.shields.io/badge/1.0.0-155875)](#)
[![Language](https://img.shields.io/badge/language-C-lightgrey)](#)
[![MCU](https://img.shields.io/badge/platform-AVR-blue)](#)
[![Made with ❤️](https://img.shields.io/badge/Made%20with-%E2%9D%A4-red)](#)
[![Ko-fi](https://img.shields.io/badge/Donate-Ko--fi-orange)](#)

<img src="https://github.com/Aloc08/Pinion/blob/main/logo%2FPinion_logo.png" width=500>

## 🔸 Why use Pinion?

Pinion is a fast, lightweight C library for AVR microcontrollers that replaces `digitalWrite()`, `digitalRead()`, and `pinMode()` of the Arduino Framework. In addition, Pinion adds `digitalToggle()`, a fast and efficient way to toggle pin states, which is not available in the standard Arduino framework. It provides direct access to hardware pins for maximum speed, supports multiple MCUs out-of-the-box, and has a minimal memory footprint. Pinion is ideal for projects that need reliable, consistent, and efficient GPIO control.

---

## 🔸 Key Features

- Works on **ATmega328P, ATmega2560, ATmega32U4** (Uno, Nano, Mega, Leonardo, Micro)  
- Drop-in API compatible with Arduino (`pinMode`, `digitalWrite`, `digitalRead`)
- Added `digitalToggle()`
- Maximum speed: direct access to hardware registers  
- Written in **pure C**, no dependency on `Arduino.h`  
- Easily extendable to other AVR MCUs  

---

## 🔸 Installation

1. Download the latest release.
2. Copy the `Pinion` folder into your project.  
3. Include the library in your source files:

```c
#include "Pinion/src/Pinion.h"
```

---

## 🔸 API

| Function                                          | Description                                      |
| ------------------------------------------------- | ------------------------------------------------ |
| `Pinion_pinMode(uint8_t pin, Pinion_mode mode)`       | Configure pin mode (INPUT, OUTPUT, INPUT_PULLUP) |
| `Pinion_digitalWrite(uint8_t pin, uint8_t value)` | Write HIGH or LOW to a pin                       |
| `Pinion_digitalRead(uint8_t pin)`                 | Read digital value from a pin                    |
| `Pinion_digitalToggle(uint8_t pin)`               | Toggle the pin state atomically                  |

### ↔️ Pin Modes

```c
typedef enum 
{
    PINION_INPUT = 0,
    PINION_OUTPUT,
    PINION_INPUT_PULLUP
} Pinion_mode;
```

### 🔢 Logical Values

```c
#define PINION_LOW   0
#define PINION_HIGH  1
```

---

## 🔸Performance

| Function               | CPU Cycles (approx.)    |
| ---------------------- | ----------------------- |
| Arduino `digitalWrite` | ~4–6 + `if/switch-case` |
| Pinion `digitalWrite`  | ~1–2                    |

check `perfomance.md` for more details.

---

## 🔸 ISR Safety

⚠ Important: All Pinion GPIO functions are ISR-unsafe. Do not call them on pins shared with interrupts, or race conditions may occur.

---

# 🔸 Pinion... An interesting name

In mechanics, a pinion is the small gear that meshes with another and sets the whole system in motion.

Similarly, the pins of a microcontroller are the contact points between the internal logic and the outside world.

The Pinion library is designed exactly like this:
a small software gear — lightweight, fast, and efficient —
that connects your code to the hardware,
giving to your project the fastest bridge between these two worlds.

---

#  💡 Contributing

Found a bug? Have a suggestion? Want to contribute?  
Feel free to [open an issue](https://github.com/Aloc08/Pinion/issues).

---

#  ☕ Donations

If you enjoy this project and want to support its development, consider buying me a coffee!  
Your contribution helps keep the project alive and motivates further updates and features.

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/R5R01HZ2ZF)

---

## Credits

Developed and maintained by [Aloc08](https://github.com/Aloc08) 

---

## License

This project is licensed under the [Apache 2.0](LICENSE).
