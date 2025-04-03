#include <screens/Common.h>
#include <screens/GT_Screen.h>
#include <screens/Rally_Screen.h>

#define MSG_LENGTH 200
#define MSG_END_CHAR '|'

byte idx = 0;
char msg[MSG_LENGTH];
bool newMsg = false;
char rChar;

void readSerial()
{
    // Reading Serial Message
    while (Serial.available() > 0 && !newMsg)
    {
        rChar = Serial.read();
        if (rChar != MSG_END_CHAR)
        {
            msg[idx] = rChar;
            idx++;
            if (idx >= MSG_LENGTH)
            {
                idx = MSG_LENGTH - 1;
            }
        }
        else
        {
            msg[idx] = '\0';
            idx = 0;
            newMsg = true;
        }
    }

    // Parsing Serial Message
    if (newMsg)
    {
        commonParseMsg(msg);

        switch (screenValue)
        {
        case 0:
            gtParseMsg();
            break;
        case 1:
            rallyParseMsg();
            break;
        }

        newMsg = false;
    }
}

// =========================================================================
// Setup For Core 0
// =========================================================================
void setup()
{
    commonSetup();
}

// =========================================================================
// Loop For Core 0
// =========================================================================
void loop()
{
    commonLoop();
    switch (screenValue)
    {
    case 0:
        if (screenChanged)
        {
            screenChanged = false;
            gtSetup();
        }
        gtLoop();
        break;
    case 1:
        if (screenChanged)
        {
            screenChanged = false;
            rallySetup();
        }
        rallyLoop();
        break;
    }
}

// =========================================================================
// Setup For Core 1
// =========================================================================
void setup1()
{
    Serial.begin(115200);
}

// =========================================================================
// Loop For Core 1
// =========================================================================
void loop1()
{
    readSerial();
}
