#ifndef WvFingerprint_h
#define WvFingerprint_h

#include <Arduino.h>


// Basic response message definition
#define WVFP_ACK_SUCCESS           0x00
#define WVFP_ACK_FAIL              0x01
#define WVFP_ACK_FULL              0x04
#define WVFP_ACK_NO_USER           0x05
#define WVFP_ACK_TIMEOUT           0x08
#define WVFP_ACK_GO_OUT            0x0F     // The center of the fingerprint is out of alignment with sensor

// User information definition
#define WVFP_ACK_ALL_USER          0x00
#define WVFP_ACK_GUEST_USER        0x01
#define WVFP_ACK_NORMAL_USER       0x02
#define WVFP_ACK_MASTER_USER       0x03

#define WVFP_USER_MAX_CNT          1000        // Maximum fingerprint number

// Command definition
#define WVFP_CMD_HEAD              0xF5
#define WVFP_CMD_TAIL              0xF5
#define WVFP_CMD_SERIALNO          0x2A
#define WVFP_CMD_ADD_1             0x01
#define WVFP_CMD_ADD_2             0x02
#define WVFP_CMD_ADD_3             0x03
#define WVFP_CMD_MATCH             0x0C
#define WVFP_CMD_DEL               0x04
#define WVFP_CMD_DEL_ALL           0x05
#define WVFP_CMD_USER_CNT          0x09
#define WVFP_CMD_COM_LEV           0x28
#define WVFP_CMD_GET_EV            0x31
#define WVFP_CMD_SET_EV            0x41
#define WVFP_CMD_LP_MODE           0x2C
#define WVFP_CMD_TIMEOUT           0x2E
#define WVFP_CMD_FINGER_DETECTED   0x14

#define WVFP_IMAGE_LENGTH          9800
#define WVFP_EIGENVALUE_LENGTH     193
#define WVFP_TXRXBUFFER_SIZE       8
#define WVFP_TXRXDATA_SIZE         4

class WvFingerprint {

    public:
        WvFingerprint(HardwareSerial &sr, uint8_t rstPin, uint8_t wakePin);
        uint32_t getSerialNumber();
        uint8_t getCompareLevel(); // Get Compare Level
        bool setCompareLevel(uint8_t compareLevel); // Set Compare Level
        uint16_t getUserCount(); // Get user Count
        uint8_t getTimeout();
        bool setTimeout(uint8_t timeout);
        bool clearAllUser();
        bool addUser(uint16_t userId, uint8_t step);
        uint16_t checkForFingerprint();
        bool getEigenvalue(uint16_t userId, byte eigenvalue[]);
        bool setEigenvalue(uint16_t userId, byte eigenvalue[]);
        bool getImage(byte &image);
        uint8_t getLastError();

    private:
        HardwareSerial * _serial;
        byte _cmdSendBuffer[WVFP_TXRXBUFFER_SIZE]; // Senden-Buffer
        byte _cmdReceiverBuffer[WVFP_TXRXBUFFER_SIZE]; // Empfangen-Buffer
        uint8_t _rstPin;
        uint8_t _wakePin;
        uint8_t _lastError;
        uint8_t _timeout; // timeout in sekunden (0-255)

        bool _waitingForFp;
        void _clearTxBuffer();
        void _clearRxBuffer();
        void _clearSerialBuffer();
        void _setSleepMode(bool sleep);
        void _txCmd(byte commands[]);
        bool _rxCmd(byte response[]);
        bool _rxEigenvalue(byte buffer[]);
        bool _txAndRxCmd(byte commands[], byte response[], uint32_t timeout);
        void _shiftBuffer(byte buffer[], uint16_t bufferSize);

};

#endif