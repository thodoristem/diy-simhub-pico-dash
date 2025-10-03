#include <Arduino.h>
#include <TFT_eSPI.h>
#include <fonts/whitrabt9pt7b.h>
#include <fonts/whitrabt11pt7b.h>
#include <fonts/whitrabt12pt7b.h>
#include <fonts/whitrabt14pt7b.h>
#include <fonts/whitrabt16pt7b.h>
#include <fonts/whitrabt20pt7b.h>
#include <fonts/whitrabt70pt7b.h>
#include <fonts/Xanmono_Regular76pt7b.h>

#define FONT_9 &whitrabt9pt7b
#define FONT_9_HEIGHT 13

#define FONT_11 &whitrabt11pt7b
#define FONT_11_HEIGHT 16

#define FONT_12 &whitrabt12pt7b
#define FONT_12_HEIGHT 18

#define FONT_14 &whitrabt14pt7b
#define FONT_14_HEIGHT 21

#define FONT_16 &whitrabt16pt7b
#define FONT_16_HEIGHT 24

#define FONT_20 &whitrabt20pt7b
#define FONT_20_HEIGHT 30

#define FONT_70 &whitrabt70pt7b
#define FONT_70_HEIGHT 104

#define FONT_76 &Xanmono_Regular76pt7b
#define FONT_76_HEIGHT 47

#define COLOR_DEPTH 8
#define CONFIG_DELIMITER "C"
#define RPM_DELIMITER "R"
#define KPH_DELIMITER "S"
#define GEAR_DELIMITER "G"
#define TIME_DELIMITER "T"
#define LAP_DELIMITER "L"
#define INDICATOR_DELIMITER "I"
#define POSITION_DELIMITER "P"

int static TFT_W = 0;
int static TFT_H = 0;
int static TFT_HF_W = 0;
int static TFT_HF_H = 0;

TFT_eSPI TFT = TFT_eSPI();

void drawMessage(String message, int pulseDelay)
{
    TFT.fillScreen(TFT_BLACK);
    TFT.setFreeFont(FONT_16);
    TFT.setTextSize(1);
    TFT.setTextColor(TFT_WHITE, TFT_BLACK);
    TFT.setTextDatum(CC_DATUM);

    delay(pulseDelay / 2);

    TFT.drawString(message, TFT_HF_W, TFT_HF_H);

    delay(pulseDelay / 2);
}

short screenValue = 0;
short screenValuePrev = 0;
bool screenChanged = true;

short dimmerValue = 50;
short dimmerValuePrev = 0;

short rpmPctValue = 0;
short rpmPctValuePrev = 0;

short rpmValue = 0;
short rpmValuePrev = 0;

short shiftLightValue = 0;
short shiftLightValuePrev = 0;
int shiftLightColor = TFT_WHITE;

short kphValue = 0;
short kphValuePrev = 0;

short gearValue = 0;
short gearValuePrev = 0;

float fuelValue = 0;
float fuelValuePrev = 0;

float ersValue = 0;
float ersValuePrev = 0;

short drsValue = 0;
short drsValuePrev = 0;

short pitValue = 0;
short pitValuePrev = 0;

String curLapTimeValue = "00:00:000";
String curLapTimeValuePrev = "00:00:000";

String bstLapTimeValue = "00:00:000";
String bstLapTimeValuePrev = "00:00:000";

String bstSessionLapTimeValue = "00:00:000";
String bstSessionLapTimeValuePrev = "00:00:000";

float bstLapTimeDeltaValue = 0.0f;
float bstLapTimeDeltaValuePrev = 0.0f;

String lapCurrentValue = "00";
String lapCurrentValuePrev = "00";

String lapsTotalValue = "00";
String lapsTotalValuePrev = "00";

String positionValue = "00";
String positionValuePrev = "00";

String positionsTotalValue = "00";
String positionsTotalValuePrev = "00";

short absValue = 0;
short absValuePrev = 0;

short tcValue = 0;
short tcValuePrev = 0;

float brakeBias = 0;
float brakeBiasPrev = 0;

float turboPct = 0;
float turboPctPrev = 0;

float tyreTempFLValue = 0;
float tyreTempFLValuePrev = 0;
float tyreTempFRValue = 0;
float tyreTempFRValuePrev = 0;
float tyreTempRLValue = 0;
float tyreTempRLValuePrev = 0;
float tyreTempRRValue = 0;
float tyreTempRRValuePrev = 0;

float tyrePressureFLValue = 0;
float tyrePressureFLValuePrev = 0;
float tyrePressureFRValue = 0;
float tyrePressureFRValuePrev = 0;
float tyrePressureRLValue = 0;
float tyrePressureRLValuePrev = 0;
float tyrePressureRRValue = 0;
float tyrePressureRRValuePrev = 0;

void changeShiftLightColor()
{
    switch (shiftLightValue)
    {
    case 1:
        shiftLightColor = TFT_GREEN;
        break;
    case 2:
        shiftLightColor = TFT_YELLOW;
        break;
    case 3:
        shiftLightColor = TFT_RED;
        break;
    default:
        shiftLightColor = TFT_WHITE;
        break;
    }
}

void dimmerLoop(bool drawInitial)
{
    if (drawInitial || dimmerValue != dimmerValuePrev)
    {
        dimmerValuePrev = dimmerValue;
        analogWrite(TFT_BL, map(dimmerValue, 0, 100, 51, 255));
    }
}

void commonParseMsg(char *msg)
{
    screenValue = atoi(strtok(msg, CONFIG_DELIMITER));
    if (screenValue != screenValuePrev)
    {
        screenValuePrev = screenValue;
        screenChanged = true;
    }

    dimmerValue = atoi(strtok(NULL, CONFIG_DELIMITER));
}

void commonSetup()
{
    TFT.init();
    TFT.setRotation(3);

    TFT_W = TFT.width();
    TFT_H = TFT.height();
    TFT_HF_W = TFT_W / 2;
    TFT_HF_H = TFT_H / 2;

    while (!Serial)
    {
        drawMessage("No serial connection!", 1000);
    }

    dimmerLoop(true);
}

void commonLoop()
{
    dimmerLoop(false);
}