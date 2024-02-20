# Lecture 2

Link to RS485: https://docs.google.com/presentation/d/1GKTP4TUWJ7rMhNlLNVpqQYzPrSSy4SViH-u3MAo7rj4/edit?usp=sharing

* RS232

  * Simple to implement, quite popular
  * First one created for public use
  * Most commonly in printers
  * Unidirectional transfer, no electromagnetic shielding

* Onewire

  * Data and power over a single wire.
  * Temp sensors, smart keys/tickets etc
  * Wires: 2 - data and ground
  * Low-cost, half-duplex connection

* I2C

  * Inter-integrated circuit
  * Multi-master, multi-slave
  * Used for attaching lower-speed peripheral ICs to processors, microcontrollers, for connecting internal components (sensors, touch screens etc) ICs to the main processor.
  * 2 signal wires - SDA, SCL

* SPI

  * Serial peripheral
  * Communication with sensors, wired short distances
  * Typically 4 wires - SCLK, MICO, MOCI, CS
  * Full duplex communication

# Reflection

* Learned new terms such as fog, edge, and swarm computing
    * And that these are often used interchangeably
* Good overview of how different concepts and how they are generally connected
* Also did not know anything about buses, it was good that we had a little overview (still don't know much :( tho)
