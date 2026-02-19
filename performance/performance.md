## Performance

<img src="https://github.com/Aloc08/Pinion/blob/main/performance%2Fperformance.jpeg" width=500>

Tested on Arduino Uno with this code:

```c
#include "Pinion.h"

#define PIN 13

int 
main(void)
{
  Pinion_pinMode(PIN, PINION_OUTPUT);

  while(1)
    Pinion_digitalToggle(PIN);
}
```


## Details
Max Freq: 2.68MHz
