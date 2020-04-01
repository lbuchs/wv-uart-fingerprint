

# Waveshare® UART Fingerprint Reader
Arduino Library for [Waveshare® UART Fingerprint Reader](https://www.waveshare.com/wiki/UART_Fingerprint_Reader)

## Methods
#### bool clearAllUser()
deletes all registered fingerprints on the device.

#### bool addUser(uint16_t userId, uint8_t step)
read a new fingerprint and save it to the provided userId. This has to be done three times.

#### uint32_t getSerialNumber()
returns the device serialNo. Normaly the device returns serialNo 0.

#### uint16_t getUserCount()
returns the number of registered fingerprints. 

#### uint8_t getCompareLevel()
returns the compare level (0-9).

#### bool setCompareLevel(uint8_t newLevel)
set the compare level (0-9).

#### uint8_t getTimeout()
get the timeout of the device.

#### bool setTimeout(uint8_t newTimeout)
sets the timeout of the device

#### uint16_t checkForFingerprint()
if there is a finger on the device, read the fingerprint and compare it with the registered fingerprints.
returns 0x0 when no finger is detected, 0xFFFF if a unknown finger is detected, or the userId of the detected fingerprint.

#### bool getEigenvalue(uint16_t userId, byte eigenvalue[])
get a eigenvalue (=fingerprint) from the specified user and write it to the provided byte array.
eigenvalue length is fix 193 bytes.

#### bool setEigenvalue(uint16_t userId, byte eigenvalue[])
set a eigenvalue (=fingerprint) for the specified user and read it from the provided byte array.
eigenvalue length is fix 193 bytes.

#### uint8_t getLastError()
returns the last error code.

