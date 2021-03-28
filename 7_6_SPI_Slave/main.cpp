#include "mbed.h"

SPISlave device(D11, D12, D13, D9); //mosi, miso, sclk,cs

DigitalOut led(LED3);

int main()
{
   //device.reply(0x00); // Prime SPI with first reply
   while (1)
   {
      device.frequency(1000000);
      //device.reply(0x00);

      if (device.receive())
      {
            int v = device.read(); // Read byte from master
            printf("read from master : v = %d\n", v);
            v = v + 1 ;
            device.reply(v);
            led = !led; // led turn blue/orange if device receive

      }
   }
}
