## For doing TDD: ##

cd ~/projects/ConwayGameOfLife_CPP/build
cmake ..
(cmake is only needed when filenames change, there are new files or dirs, etc.)
make
make && make test
 OR
make && ./test/arduinotdd


## For compile and deploy: ##
cd ~/projects/ConwayGameOfLife_CPP/src

arduino-cli compile -b arduino:avr:mega

then:
ls /dev/cu.*
to find the port.

then, to deploy:

arduino-cli upload -v -p /dev/cu.usbmodem1412301 -b arduino:avr:mega

NOTE: /dev/cu.usbmodemxxxxxxx might be different

