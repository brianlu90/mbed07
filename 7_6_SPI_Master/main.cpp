#include "mbed.h"

Thread thread1;

//master

SPI spi(D11, D12, D13); // mosi, miso, sclk
DigitalOut cs(D9);

void master()
{
   int number = 0 ;

   while(1){
   // Chip must be deselected
   cs = 1;

   // Setup the spi for 8 bit data, high steady state clock,
   // second edge capture, with a 1MHz clock rate
   spi.format(8, 3);
   spi.frequency(1000000);

   // Select the device by seting chip select low
   cs = 0;

   printf("send number = %d\n", number);

   int response = spi.write(number);
   ThisThread::sleep_for(500ms);
   printf("response from slave = %d\n",response);
   //cs = 1; // Deselect the device
   number += 1 ;
   }

}


int main()
{
   thread1.start(master);
}
