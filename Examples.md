# Examples

## Blink an LED
```c
#include <Arduino.h>
#include "Pinion.h" // Check your file path

#define PIN 13

int 
main(void)
{
  init();
  Pinion_pinMode(PIN, PINION_OUTPUT);

  while(1)
  {
    Pinion_digitalWrite(PIN, PINION_HIGH);
    delay(1000);
    Pinion_digitalWrite(PIN, PINION_LOW);
    delay(1000);
  }
}
```

## Blink an LED - alternative
```c
#include <Arduino.h>
#include "Pinion.h" // Check your file path

#define PIN 13

int 
main(void)
{
  init();
  Pinion_pinMode(PIN, PINION_OUTPUT);

  while(1)
  {
    Pinion_digitalToggle(PIN);
    delay(1000);
    Pinion_digitalToggle(PIN);
    delay(1000);
  }
}
```

## Create the fastest clock
```c
#include "Pinion.h" // Check your file path

#define PIN 13

int 
main(void)
{
  Pinion_pinMode(PIN, PINION_OUTPUT);

  while(1)
  {
    Pinion_digitalToggle(PIN);
  }
}
```


## Read a button
```c
#include "Pinion.h" // Check your file path

#define PIN 13

int 
main(void)
{
  Pinion_pinMode(PIN, PINION_INPUT_PULLUP);

  while(1)
  {
    if (Pinion_digitalRead(PIN) == PINION_LOW)
    {
      /* button pressed */
    }
  }
}
```
