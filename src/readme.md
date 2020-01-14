To compile from this directory:
arduino-cli compile -b arduino:avr:mega

then:
ls /dev/cu.*
to find the port.

then:

arduino-cli upload -v -p /dev/cu.usbmodem1412301 -b arduino:avr:mega

to deploy. (/dev/cu.usbmodemxxxxxxx might be different)


