## Performance

<img src="https://github.com/Aloc08/Pinion-test/blob/893b0d3dff317f0a7d9c653489dc3a5ec625b244/performance/performance.jpeg" width=500>

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
