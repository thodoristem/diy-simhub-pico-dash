#include <Arduino.h>
#include <TFT_eSPI.h>
#include <fonts/whitrabt9pt7b.h>
#include <fonts/whitrabt11pt7b.h>
#include <fonts/whitrabt12pt7b.h>
#include <fonts/whitrabt14pt7b.h>
#include <fonts/whitrabt16pt7b.h>
#include <fonts/whitrabt70pt7b.h>

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

#define FONT_70 &whitrabt70pt7b
#define FONT_70_HEIGHT 104

#define DEFAULT_FONT FONT_11

#define MSG_LENGTH 160
#define MSG_END_CHAR '|'
#define RPM_DELIMITER "R"
#define KPH_DELIMITER "S"
#define GEAR_DELIMITER "G"
#define TIME_DELIMITER "T"
#define LAP_DELIMITER "L"
#define INDICATOR_DELIMITER "I"
#define CONFIG_DELIMITER "C"

byte idx = 0;
char msg[MSG_LENGTH];
bool newMsg = false;
char rChar;

volatile short rpmPctValue = 0;
volatile short rpmPctValuePrev = 0;

volatile short rpmValue = 0;
volatile short rpmValuePrev = 0;

volatile short shiftLightValue = 0;
volatile short shiftLightValuePrev = 0;
volatile int shiftLightColor = TFT_WHITE;

volatile short kphValue = 0;
volatile short kphValuePrev = 0;

volatile short gearValue = 0;
volatile short gearValuePrev = 0;

volatile float fuelValue = 0;
volatile float fuelValuePrev = 0;

volatile float ersValue = 0;
volatile float ersValuePrev = 0;

volatile short drsValue = 0;
volatile short drsValuePrev = 0;

volatile short pitValue = 0;
volatile short pitValuePrev = 0;

String curLapTimeValue = "00:00:000";
String curLapTimeValuePrev = "00:00:000";

String bstLapTimeValue = "00:00:000";
String bstLapTimeValuePrev = "00:00:000";

String bstSessionLapTimeValue = "00:00:000";
String bstSessionLapTimeValuePrev = "00:00:000";

volatile float bstLapTimeDeltaValue = 0.0f;
volatile float bstLapTimeDeltaValuePrev = 0.0f;

String lapCurrentValue = "00";
String lapCurrentValuePrev = "00";

String lapsTotalValue = "00";
String lapsTotalValuePrev = "00";

String positionValue = "00";
String positionValuePrev = "00";

String positionsTotalValue = "00";
String positionsTotalValuePrev = "00";

volatile short absValue = 0;
volatile short absValuePrev = 0;

volatile short tcValue = 0;
volatile short tcValuePrev = 0;

volatile float brakeBias = 0;
volatile float brakeBiasPrev = 0;

volatile float turboPct = 0;
volatile float turboPctPrev = 0;

volatile float tyreTempFLValue = 0;
volatile float tyreTempFLValuePrev = 0;
volatile float tyreTempFRValue = 0;
volatile float tyreTempFRValuePrev = 0;
volatile float tyreTempRLValue = 0;
volatile float tyreTempRLValuePrev = 0;
volatile float tyreTempRRValue = 0;
volatile float tyreTempRRValuePrev = 0;

volatile float tyrePressureFLValue = 0;
volatile float tyrePressureFLValuePrev = 0;
volatile float tyrePressureFRValue = 0;
volatile float tyrePressureFRValuePrev = 0;
volatile float tyrePressureRLValue = 0;
volatile float tyrePressureRLValuePrev = 0;
volatile float tyrePressureRRValue = 0;
volatile float tyrePressureRRValuePrev = 0;

volatile short dimmerValue = 50;
volatile short dimmerValuePrev = 0;

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
        char *temp = msg;

        // Serial.print(msg);
        // Serial.println(" -> OK");

        rpmValue = atoi(strtok(temp, RPM_DELIMITER));
        rpmPctValue = atoi(strtok(NULL, RPM_DELIMITER));
        kphValue = atoi(strtok(NULL, KPH_DELIMITER));
        gearValue = atoi(strtok(NULL, GEAR_DELIMITER));
        shiftLightValue = atoi(strtok(NULL, GEAR_DELIMITER));

        fuelValue = atof(strtok(NULL, INDICATOR_DELIMITER));
        ersValue = atof(strtok(NULL, INDICATOR_DELIMITER));

        drsValue = atoi(strtok(NULL, INDICATOR_DELIMITER));
        pitValue = atoi(strtok(NULL, INDICATOR_DELIMITER));

        curLapTimeValue = strtok(NULL, LAP_DELIMITER);
        bstLapTimeValue = strtok(NULL, LAP_DELIMITER);
        bstSessionLapTimeValue = strtok(NULL, LAP_DELIMITER);
        bstLapTimeDeltaValue = atof(strtok(NULL, LAP_DELIMITER));

        lapCurrentValue = strtok(NULL, LAP_DELIMITER);
        lapsTotalValue = strtok(NULL, LAP_DELIMITER);

        positionValue = strtok(NULL, LAP_DELIMITER);
        positionsTotalValue = strtok(NULL, LAP_DELIMITER);

        absValue = atoi(strtok(NULL, INDICATOR_DELIMITER));
        tcValue = atoi(strtok(NULL, INDICATOR_DELIMITER));
        brakeBias = atof(strtok(NULL, INDICATOR_DELIMITER));
        turboPct = atof(strtok(NULL, INDICATOR_DELIMITER));

        tyreTempFLValue = atof(strtok(NULL, INDICATOR_DELIMITER));
        tyreTempFRValue = atof(strtok(NULL, INDICATOR_DELIMITER));
        tyreTempRLValue = atof(strtok(NULL, INDICATOR_DELIMITER));
        tyreTempRRValue = atof(strtok(NULL, INDICATOR_DELIMITER));

        tyrePressureFLValue = atof(strtok(NULL, INDICATOR_DELIMITER));
        tyrePressureFRValue = atof(strtok(NULL, INDICATOR_DELIMITER));
        tyrePressureRLValue = atof(strtok(NULL, INDICATOR_DELIMITER));
        tyrePressureRRValue = atof(strtok(NULL, INDICATOR_DELIMITER));

        dimmerValue = atoi(strtok(NULL, CONFIG_DELIMITER));

        newMsg = false;
    }
}

int static TFT_HF_W = 0;
int static TFT_HF_H = 0;

#define COLOR_DEPTH 8

#define PADDING_DB 8
#define PADDING 4
#define PADDING_HF 2

#define RPM_BAR_SP_W 480
#define RPM_BAR_SP_H 20

#define RPM_SP_W 184
#define RPM_SP_H 58
#define RPM_SP_HF_W 92
#define RPM_SP_HF_H 29

#define GEAR_SP_W 108
#define GEAR_SP_H 120
#define GEAR_SP_HF_W 54
#define GEAR_SP_HF_H 60

#define KPH_SP_W 184
#define KPH_SP_H 58
#define KPH_SP_HF_W 92
#define KPH_SP_HF_H 29

#define LAP_TIME_SP_W 152
#define LAP_TIME_SP_H 26
#define LAP_TIME_SP_HF_W 76
#define LAP_TIME_SP_HF_H 13

#define INDICATOR_SP_W 46
#define INDICATOR_SP_H 24
#define INDICATOR_SP_HF_W 23
#define INDICATOR_SP_HF_H 12

#define NUM_SP_W 72
#define NUM_SP_H 30
#define NUM_SP_HF_W 36
#define NUM_SP_HF_H 15

#define MINI_NUM_SP_W 72
#define MINI_NUM_SP_H 24
#define MINI_NUM_SP_HF_W 36
#define MINI_NUM_SP_HF_H 12

#define LAP_SP_W 50
#define LAP_SP_H 36
#define LAP_SP_HF_W 25
#define LAP_SP_HF_H 18

TFT_eSPI TFT = TFT_eSPI();

TFT_eSprite rpmBarSp = TFT_eSprite(&TFT);
TFT_eSprite rpmSp = TFT_eSprite(&TFT);
TFT_eSprite kphSp = TFT_eSprite(&TFT);
TFT_eSprite gearSp = TFT_eSprite(&TFT);
TFT_eSprite lapTimeSp = TFT_eSprite(&TFT);
TFT_eSprite indicatorSp = TFT_eSprite(&TFT);
TFT_eSprite numSp = TFT_eSprite(&TFT);
TFT_eSprite miniNumSp = TFT_eSprite(&TFT);

void changeShiftLightColor()
{
    switch (shiftLightValue)
    {
    default:
        shiftLightColor = TFT_WHITE;
        break;
    case 1:
        shiftLightColor = TFT_GREEN;
        break;
    case 2:
        shiftLightColor = TFT_YELLOW;
        break;
    case 3:
        shiftLightColor = TFT_RED;
        break;
    }
}

void drawRpmBar(bool drawInitial)
{
    if (drawInitial || rpmPctValue != rpmPctValuePrev)
    {
        rpmPctValuePrev = rpmPctValue;

        changeShiftLightColor();

        rpmBarSp.fillSprite(TFT_BLACK);
        rpmBarSp.fillRect(0, 0, map(rpmPctValue, 0, 100, 0, RPM_BAR_SP_W), RPM_BAR_SP_H, shiftLightColor);

        rpmBarSp.pushSprite(PADDING_HF, PADDING_HF);
    }
}

void drawRPM(bool drawInitial)
{
    if (drawInitial || rpmValue != rpmValuePrev)
    {
        rpmValuePrev = rpmValue;
        rpmSp.fillSprite(TFT_BLACK);
        rpmSp.setTextColor(TFT_WHITE);
        rpmSp.drawNumber(rpmValue, RPM_SP_W - PADDING_DB, RPM_SP_HF_H - PADDING_HF);
        rpmSp.pushSprite(PADDING_HF, RPM_BAR_SP_H + PADDING);
    }
}

void drawKPH(bool drawInitial)
{
    if (drawInitial || kphValue != kphValuePrev)
    {
        kphValuePrev = kphValue;
        kphSp.fillSprite(TFT_BLACK);
        kphSp.setTextColor(TFT_WHITE);
        kphSp.drawNumber(kphValue, KPH_SP_W - PADDING_DB, KPH_SP_HF_H - PADDING_HF);
        kphSp.pushSprite(TFT.width() - KPH_SP_W + PADDING_HF, RPM_BAR_SP_H + PADDING);
    }
}

void drawGear(bool drawInitial)
{
    if (drawInitial || gearValue != gearValuePrev || shiftLightValue != shiftLightValuePrev)
    {
        gearValuePrev = gearValue;
        shiftLightValuePrev = shiftLightValue;

        changeShiftLightColor();

        gearSp.fillSprite(TFT_BLACK);
        gearSp.setTextColor(shiftLightColor);
        switch (gearValue)
        {
        default:
            gearSp.drawNumber(gearValue, GEAR_SP_HF_W - PADDING_HF, PADDING_DB + PADDING);
            break;
        case -1:
            gearSp.drawString("R", GEAR_SP_HF_W - PADDING - PADDING_HF, PADDING_DB + PADDING);
            break;
        case 0:
            gearSp.drawString("N", GEAR_SP_HF_W - PADDING - PADDING_HF, PADDING_DB + PADDING);
            break;
        }
        gearSp.pushSprite(TFT_HF_W - GEAR_SP_HF_W + PADDING_HF, RPM_BAR_SP_H + PADDING);
    }
}

void drawIndicatorLabel(bool drawInitial)
{
    if (drawInitial || drsValue != drsValuePrev)
    {
        drsValuePrev = drsValue;
        indicatorSp.fillSprite(TFT_DARKGREY);
        switch (drsValue)
        {
        case 0:
            indicatorSp.setTextColor(TFT_BLACK);
            break;
        case 1:
            indicatorSp.setTextColor(TFT_WHITE);
            break;
        case 2:
            indicatorSp.setTextColor(TFT_CYAN);
            break;
        }
        indicatorSp.drawString("DRS", INDICATOR_SP_HF_W - PADDING_HF, INDICATOR_SP_H - PADDING);
        indicatorSp.pushSprite(TFT.width() - KPH_SP_W, RPM_BAR_SP_H + KPH_SP_H + PADDING);
    }

    if (drawInitial || pitValue != pitValuePrev)
    {
        pitValuePrev = pitValue;
        indicatorSp.fillSprite(TFT_DARKGREY);
        switch (pitValue)
        {
        case 0:
            indicatorSp.setTextColor(TFT_BLACK);
            break;
        case 1:
            indicatorSp.setTextColor(TFT_YELLOW);
            break;
        case 2:
            indicatorSp.setTextColor(TFT_ORANGE);
            break;
        }
        indicatorSp.drawString("PIT", INDICATOR_SP_HF_W - PADDING_HF, INDICATOR_SP_H - PADDING);
        indicatorSp.pushSprite(TFT.width() - KPH_SP_W + INDICATOR_SP_W + PADDING_HF, RPM_BAR_SP_H + KPH_SP_H + PADDING);
    }
}

void drawNum(bool drawInitial)
{
    if (drawInitial || absValue != absValuePrev)
    {
        absValuePrev = absValue;
        numSp.fillSprite(TFT_BLACK);
        numSp.drawNumber(
            absValue,
            NUM_SP_HF_W - PADDING_HF - PADDING_HF / 2,
            NUM_SP_HF_H - PADDING);
        numSp.pushSprite(
            TFT.width() - NUM_SP_W - NUM_SP_W,
            RPM_BAR_SP_H + GEAR_SP_H + FONT_11_HEIGHT + PADDING * 3);
    }

    if (drawInitial || tcValue != tcValuePrev)
    {
        tcValuePrev = tcValue;
        numSp.fillSprite(TFT_BLACK);
        numSp.drawNumber(
            tcValue,
            NUM_SP_HF_W - PADDING_HF - PADDING_HF / 2,
            NUM_SP_HF_H - PADDING);
        numSp.pushSprite(
            TFT.width() - NUM_SP_W - NUM_SP_W,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_11_HEIGHT * 2 + PADDING * 6);
    }

    if (drawInitial || brakeBias != brakeBiasPrev)
    {
        brakeBiasPrev = brakeBias;
        numSp.fillSprite(TFT_BLACK);
        numSp.drawFloat(
            brakeBias,
            1,
            NUM_SP_HF_W - PADDING_HF - PADDING_HF / 2,
            NUM_SP_HF_H - PADDING);
        numSp.pushSprite(
            TFT.width() - NUM_SP_W - NUM_SP_W,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H * 2 + FONT_11_HEIGHT * 3 + PADDING * 9);
    }

    if (drawInitial || fuelValue != fuelValuePrev)
    {
        fuelValuePrev = fuelValue;
        numSp.fillSprite(TFT_BLACK);
        numSp.drawFloat(
            fuelValue,
            1,
            NUM_SP_HF_W - PADDING_HF - PADDING_HF / 2,
            NUM_SP_HF_H - PADDING);
        numSp.pushSprite(
            TFT.width() - NUM_SP_W + PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + FONT_11_HEIGHT + PADDING * 3);
    }

    if (drawInitial || ersValue != ersValuePrev)
    {
        ersValuePrev = ersValue;
        numSp.fillSprite(TFT_BLACK);
        numSp.drawFloat(
            ersValue,
            1,
            NUM_SP_HF_W - PADDING_HF - PADDING_HF / 2,
            NUM_SP_HF_H - PADDING);
        numSp.pushSprite(
            TFT.width() - NUM_SP_W + PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_11_HEIGHT * 2 + PADDING * 6);
    }

    if (drawInitial || turboPct != turboPctPrev)
    {
        turboPctPrev = turboPct;
        numSp.fillSprite(TFT_BLACK);
        numSp.drawFloat(
            turboPct,
            1,
            NUM_SP_HF_W - PADDING_HF - PADDING_HF / 2,
            NUM_SP_HF_H - PADDING);
        numSp.pushSprite(
            TFT.width() - NUM_SP_W + PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H * 2 + FONT_11_HEIGHT * 3 + PADDING * 9);
    }

    if (drawInitial || positionValue != positionValuePrev || positionsTotalValue != positionsTotalValuePrev)
    {
        positionValuePrev = positionValue;
        positionsTotalValuePrev = positionsTotalValue;
        numSp.fillSprite(TFT_BLACK);
        numSp.drawString(
            positionValue + "|" + positionsTotalValue,
            NUM_SP_HF_W - PADDING_HF - PADDING_HF / 2,
            NUM_SP_HF_H - PADDING);
        numSp.pushSprite(
            PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + FONT_11_HEIGHT + PADDING * 3);
    }

    if (drawInitial || lapCurrentValue != lapCurrentValuePrev || lapsTotalValue != lapsTotalValuePrev)
    {
        lapCurrentValuePrev = lapCurrentValue;
        lapsTotalValuePrev = lapsTotalValue;
        numSp.fillSprite(TFT_BLACK);
        numSp.drawString(
            lapCurrentValue + "|" + lapsTotalValue,
            NUM_SP_HF_W - PADDING_HF - PADDING_HF / 2,
            NUM_SP_HF_H - PADDING);
        numSp.pushSprite(
            NUM_SP_W + PADDING,
            RPM_BAR_SP_H + GEAR_SP_H + FONT_11_HEIGHT + PADDING * 3);
    }
}

void drawMiniNum(bool drawInitial)
{
    if (drawInitial || tyreTempFLValue != tyreTempFLValuePrev)
    {
        tyreTempFLValuePrev = tyreTempFLValue;
        miniNumSp.fillSprite(TFT_BLACK);
        miniNumSp.setTextDatum(CL_DATUM);
        miniNumSp.drawString(
            "C" + String(tyreTempFLValue, 1),
            PADDING,
            MINI_NUM_SP_HF_H - PADDING + 1);
        miniNumSp.pushSprite(
            PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_16_HEIGHT * 2 + MINI_NUM_SP_H + PADDING + PADDING_HF);
    }

    if (drawInitial || tyreTempRLValue != tyreTempRLValuePrev)
    {
        tyreTempRLValuePrev = tyreTempRLValue;
        miniNumSp.fillSprite(TFT_BLACK);
        miniNumSp.setTextDatum(CL_DATUM);
        miniNumSp.drawString(
            "C" + String(tyreTempRLValue, 1),
            PADDING,
            MINI_NUM_SP_HF_H - PADDING + 1);
        miniNumSp.pushSprite(
            PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_16_HEIGHT * 2 + MINI_NUM_SP_H * 2 + PADDING + PADDING_HF);
    }

    if (drawInitial || tyreTempFRValue != tyreTempFRValuePrev)
    {
        tyreTempFRValuePrev = tyreTempFRValue;
        miniNumSp.fillSprite(TFT_BLACK);
        miniNumSp.setTextDatum(CR_DATUM);
        miniNumSp.drawString(
            String(tyreTempFRValue, 1) + "C",
            MINI_NUM_SP_W - PADDING_DB,
            MINI_NUM_SP_HF_H - PADDING + 1);
        miniNumSp.pushSprite(
            MINI_NUM_SP_W + PADDING,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_16_HEIGHT * 2 + MINI_NUM_SP_H + PADDING + PADDING_HF);
    }

    if (drawInitial || tyreTempRRValue != tyreTempRRValuePrev)
    {
        tyreTempRRValuePrev = tyreTempRRValue;
        miniNumSp.fillSprite(TFT_BLACK);
        miniNumSp.setTextDatum(CR_DATUM);
        miniNumSp.drawString(
            String(tyreTempRRValue, 1) + "C",
            MINI_NUM_SP_W - PADDING_DB,
            MINI_NUM_SP_HF_H - PADDING + 1);
        miniNumSp.pushSprite(
            MINI_NUM_SP_W + PADDING,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_16_HEIGHT * 2 + MINI_NUM_SP_H * 2 + PADDING + PADDING_HF);
    }

    if (drawInitial || tyrePressureFLValue != tyrePressureFLValuePrev)
    {
        tyrePressureFLValuePrev = tyrePressureFLValue;
        miniNumSp.fillSprite(TFT_BLACK);
        miniNumSp.setTextDatum(CL_DATUM);
        miniNumSp.drawString(
            "P" + String(tyrePressureFLValue, 1),
            PADDING,
            MINI_NUM_SP_HF_H - PADDING + 1);
        miniNumSp.pushSprite(
            PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_16_HEIGHT * 2 + PADDING_DB);
    }

    if (drawInitial || tyrePressureRLValue != tyrePressureRLValuePrev)
    {
        tyrePressureRLValuePrev = tyrePressureRLValue;
        miniNumSp.fillSprite(TFT_BLACK);
        miniNumSp.setTextDatum(CL_DATUM);
        miniNumSp.drawString(
            "P" + String(tyrePressureRLValue, 1),
            PADDING,
            MINI_NUM_SP_HF_H - PADDING + 1);
        miniNumSp.pushSprite(
            PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_16_HEIGHT * 2 + MINI_NUM_SP_H * 3 + PADDING);
    }

    if (drawInitial || tyrePressureFRValue != tyrePressureFRValuePrev)
    {
        tyrePressureFRValuePrev = tyrePressureFRValue;
        miniNumSp.fillSprite(TFT_BLACK);
        miniNumSp.setTextDatum(CR_DATUM);
        miniNumSp.drawString(
            String(tyrePressureFRValue, 1) + "P",
            MINI_NUM_SP_W - PADDING_DB,
            MINI_NUM_SP_HF_H - PADDING + 1);
        miniNumSp.pushSprite(
            MINI_NUM_SP_W + PADDING,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_16_HEIGHT * 2 + PADDING_DB);
    }

    if (drawInitial || tyrePressureRRValue != tyrePressureRRValuePrev)
    {
        tyrePressureRRValuePrev = tyrePressureRRValue;
        miniNumSp.fillSprite(TFT_BLACK);
        miniNumSp.setTextDatum(CR_DATUM);
        miniNumSp.drawString(
            String(tyrePressureRRValue, 1) + "P",
            MINI_NUM_SP_W - PADDING_DB,
            MINI_NUM_SP_HF_H - PADDING + 1);
        miniNumSp.pushSprite(
            MINI_NUM_SP_W + PADDING,
            RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_16_HEIGHT * 2 + MINI_NUM_SP_H * 3 + PADDING);
    }
}

void drawLapTime(bool drawInitial)
{
    if (drawInitial || bstLapTimeDeltaValue != bstLapTimeDeltaValuePrev)
    {
        bstLapTimeDeltaValuePrev = bstLapTimeDeltaValue;
        if (bstLapTimeDeltaValue < 0)
        {
            lapTimeSp.setTextColor(TFT_GREEN, TFT_BLACK);
        }
        else if (bstLapTimeDeltaValue > 0)
        {
            lapTimeSp.setTextColor(TFT_RED, TFT_BLACK);
        }
        else
        {
            lapTimeSp.setTextColor(TFT_WHITE, TFT_BLACK);
        }
        lapTimeSp.setTextDatum(CC_DATUM);
        lapTimeSp.fillSprite(TFT_BLACK);
        lapTimeSp.drawFloat(
            bstLapTimeDeltaValue,
            3,
            LAP_TIME_SP_HF_W - PADDING_HF,
            LAP_TIME_SP_HF_H - PADDING_HF);
        lapTimeSp.pushSprite(
            TFT_HF_W - LAP_TIME_SP_HF_W + PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + FONT_9_HEIGHT + PADDING_HF * 5);
        lapTimeSp.setTextDatum(CL_DATUM);
        lapTimeSp.setTextColor(TFT_WHITE, TFT_BLACK);
    }

    if (drawInitial || curLapTimeValue != curLapTimeValuePrev)
    {
        curLapTimeValuePrev = curLapTimeValue;
        lapTimeSp.fillSprite(TFT_BLACK);
        lapTimeSp.setTextColor(TFT_YELLOW);
        lapTimeSp.drawString(
            curLapTimeValue,
            PADDING_HF,
            LAP_TIME_SP_HF_H - PADDING_HF);
        lapTimeSp.pushSprite(
            TFT_HF_W - LAP_TIME_SP_HF_W + PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + LAP_TIME_SP_H + FONT_9_HEIGHT * 2 + PADDING_HF * 7);
    }

    if (drawInitial || bstLapTimeValue != bstLapTimeValuePrev)
    {
        bstLapTimeValuePrev = bstLapTimeValue;
        lapTimeSp.fillSprite(TFT_BLACK);
        lapTimeSp.setTextColor(TFT_GREENYELLOW);
        lapTimeSp.drawString(
            bstLapTimeValue,
            PADDING_HF,
            LAP_TIME_SP_HF_H - PADDING_HF);
        lapTimeSp.pushSprite(
            TFT_HF_W - LAP_TIME_SP_HF_W + PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + LAP_TIME_SP_H * 2 + FONT_9_HEIGHT * 3 + PADDING_HF * 9);
    }

    if (drawInitial || bstSessionLapTimeValue != bstSessionLapTimeValuePrev)
    {
        bstSessionLapTimeValuePrev = bstSessionLapTimeValue;
        lapTimeSp.fillSprite(TFT_BLACK);
        lapTimeSp.setTextColor(TFT_MAGENTA);
        lapTimeSp.drawString(
            bstSessionLapTimeValue,
            PADDING_HF,
            LAP_TIME_SP_HF_H - PADDING_HF);
        lapTimeSp.pushSprite(
            TFT_HF_W - LAP_TIME_SP_HF_W + PADDING_HF,
            RPM_BAR_SP_H + GEAR_SP_H + LAP_TIME_SP_H * 3 + FONT_9_HEIGHT * 4 + PADDING_HF * 11);
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

void drawOnce()
{
    // RPM BAR
    TFT.fillRoundRect(
        0,
        0,
        RPM_BAR_SP_W,
        RPM_BAR_SP_H,
        0,
        TFT_WHITE);

    // RPM
    TFT.fillRoundRect(
        0,
        RPM_BAR_SP_H + PADDING_HF,
        KPH_SP_W,
        KPH_SP_H,
        0,
        TFT_YELLOW);

    TFT.setTextDatum(TL_DATUM);
    TFT.drawString(
        "RPM",
        PADDING_HF,
        RPM_BAR_SP_H + RPM_SP_H + PADDING);

    // GEAR
    TFT.fillRoundRect(
        TFT_HF_W - GEAR_SP_HF_W,
        RPM_BAR_SP_H + PADDING_HF,
        GEAR_SP_W,
        GEAR_SP_H,
        0,
        TFT_CYAN);

    // KPH
    TFT.fillRoundRect(
        TFT.width() - KPH_SP_W,
        RPM_BAR_SP_H + PADDING_HF,
        RPM_SP_W,
        RPM_SP_H,
        0,
        TFT_YELLOW);

    TFT.setTextDatum(TR_DATUM);
    TFT.drawString(
        "KPH",
        TFT.width() - PADDING_HF,
        RPM_BAR_SP_H + RPM_SP_H + PADDING);

    // LAP TIMING
    TFT.setFreeFont(FONT_9);
    TFT.setTextDatum(TC_DATUM);

    TFT.drawRoundRect(
        TFT_HF_W - LAP_TIME_SP_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING,
        LAP_TIME_SP_W,
        LAP_TIME_SP_H * 4 + FONT_9_HEIGHT * 4 + PADDING_HF * 9,
        5,
        TFT_WHITE);

    TFT.drawString(
        "Delta",
        TFT_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING_HF * 4);

    TFT.drawRect(
        TFT_HF_W - LAP_TIME_SP_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + LAP_TIME_SP_H + FONT_9_HEIGHT + PADDING_HF * 4,
        LAP_TIME_SP_W,
        1,
        TFT_WHITE);

    TFT.drawString(
        "Current",
        TFT_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + LAP_TIME_SP_H + FONT_9_HEIGHT + PADDING_HF * 6);

    TFT.drawRect(
        TFT_HF_W - LAP_TIME_SP_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + LAP_TIME_SP_H * 2 + FONT_9_HEIGHT * 2 + PADDING_HF * 6,
        LAP_TIME_SP_W,
        1,
        TFT_WHITE);

    TFT.drawString(
        "Best",
        TFT_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + LAP_TIME_SP_H * 2 + FONT_9_HEIGHT * 2 + PADDING_HF * 8);

    TFT.drawRect(
        TFT_HF_W - LAP_TIME_SP_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + LAP_TIME_SP_H * 3 + FONT_9_HEIGHT * 3 + PADDING_HF * 8,
        LAP_TIME_SP_W,
        1,
        TFT_WHITE);

    TFT.drawString(
        "Session",
        TFT_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + LAP_TIME_SP_H * 3 + FONT_9_HEIGHT * 3 + PADDING_HF * 10);

    TFT.setFreeFont(FONT_11);

    // FUEL
    TFT.drawRoundRect(
        TFT.width() - NUM_SP_W,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING,
        NUM_SP_W,
        NUM_SP_H + FONT_11_HEIGHT + PADDING_DB + PADDING_HF,
        5,
        TFT_ORANGE);

    TFT.drawString(
        "Fuel%",
        TFT.width() - NUM_SP_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING_DB);

    // ABS
    TFT.drawRoundRect(
        TFT.width() - NUM_SP_W,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_11_HEIGHT + PADDING_DB * 2,
        NUM_SP_W,
        NUM_SP_H + FONT_11_HEIGHT + PADDING_DB + PADDING_HF,
        5,
        TFT_DARKCYAN);

    TFT.drawString(
        "ERS%",
        TFT.width() - NUM_SP_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_11_HEIGHT + PADDING_DB * 2 + PADDING);

    // BOOST
    TFT.drawRoundRect(
        TFT.width() - NUM_SP_W,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + PADDING_DB * 3 + PADDING,
        NUM_SP_W,
        NUM_SP_H + FONT_11_HEIGHT + PADDING_DB + PADDING_HF,
        5,
        TFT_DARKCYAN);

    TFT.drawString(
        "BST%",
        TFT.width() - NUM_SP_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + PADDING_DB * 4);

    // ERS
    TFT.drawRoundRect(
        TFT.width() - NUM_SP_W * 2 - PADDING_HF,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING,
        NUM_SP_W,
        NUM_SP_H + FONT_11_HEIGHT + PADDING_DB + PADDING_HF,
        5,
        TFT_DARKGREY);

    TFT.drawString(
        "ABS",
        TFT.width() - NUM_SP_HF_W * 3 - PADDING_HF * 2,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING_DB);

    // TC
    TFT.drawRoundRect(
        TFT.width() - NUM_SP_W * 2 - PADDING_HF,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_11_HEIGHT + PADDING_DB * 2,
        NUM_SP_W,
        NUM_SP_H + FONT_11_HEIGHT + PADDING_DB + PADDING_HF,
        5,
        TFT_DARKGREY);

    TFT.drawString(
        "TC",
        TFT.width() - NUM_SP_HF_W * 3 - PADDING_HF * 2,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_11_HEIGHT + PADDING_DB * 2 + PADDING);

    // BIAS
    TFT.drawRoundRect(
        TFT.width() - NUM_SP_W * 2 - PADDING_HF,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + PADDING_DB * 3 + PADDING,
        NUM_SP_W,
        NUM_SP_H + FONT_11_HEIGHT + PADDING_DB + PADDING_HF,
        5,
        TFT_RED);

    TFT.drawString(
        "BB",
        TFT.width() - NUM_SP_HF_W * 3 - PADDING_HF * 2,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + PADDING_DB * 4);

    // POSITION
    TFT.drawRoundRect(
        0,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING,
        NUM_SP_W,
        NUM_SP_H + FONT_11_HEIGHT + PADDING_DB + PADDING_HF,
        5,
        TFT_DARKGREEN);

    TFT.drawString(
        "POS",
        NUM_SP_HF_W,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING_DB);

    // LAP COUNT
    TFT.drawRoundRect(
        NUM_SP_W + PADDING_HF,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING,
        NUM_SP_W,
        NUM_SP_H + FONT_11_HEIGHT + PADDING_DB + PADDING_HF,
        5,
        TFT_DARKGREEN);

    TFT.drawString(
        "LAP",
        NUM_SP_HF_W * 3 + PADDING_HF,
        RPM_BAR_SP_H + GEAR_SP_H + PADDING_DB);

    // TYRE/BRAKE TEMPS
    TFT.drawRoundRect(
        0,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_11_HEIGHT + PADDING_DB * 2,
        NUM_SP_W * 2 + PADDING_HF,
        NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + FONT_16_HEIGHT - PADDING_HF,
        5,
        TFT_GREENYELLOW);

    TFT.drawString(
        "Tyres",
        NUM_SP_HF_W * 2 + PADDING_HF,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_11_HEIGHT + PADDING_DB * 2 + PADDING);

    TFT.drawRect(
        PADDING,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H * 2 + FONT_11_HEIGHT * 3 + PADDING_DB * 2 + PADDING,
        NUM_SP_W * 2 + PADDING_HF - PADDING_DB,
        2,
        TFT_GREENYELLOW);

    TFT.drawRect(
        NUM_SP_W,
        RPM_BAR_SP_H + GEAR_SP_H + NUM_SP_H + FONT_11_HEIGHT * 2 + FONT_16_HEIGHT + PADDING_HF,
        2,
        NUM_SP_H * 2 + FONT_11_HEIGHT + PADDING_DB,
        TFT_GREENYELLOW);
}

void drawMessage(String message)
{
    TFT.fillScreen(TFT_BLACK);
    TFT.setTextFont(4);
    TFT.setTextSize(1);
    TFT.setTextColor(TFT_WHITE, TFT_BLACK);
    TFT.setTextDatum(CC_DATUM);
    TFT.drawString(message, TFT_HF_W, TFT_HF_H);
    delay(500);
}

// =========================================================================
// Setup For Core 0
// =========================================================================
void setup()
{
    TFT.init();
    TFT.setRotation(3);

    TFT_HF_W = TFT.width() / 2;
    TFT_HF_H = TFT.height() / 2;

    while (!Serial)
    {
        drawMessage("No serial connection!");
    }

    TFT.fillScreen(TFT_BLACK);
    TFT.setFreeFont(DEFAULT_FONT);
    TFT.setTextSize(1);
    TFT.setTextColor(TFT_DARKGREY);
    drawOnce();

    rpmBarSp.createSprite(RPM_BAR_SP_W - PADDING, RPM_BAR_SP_H - PADDING);
    rpmBarSp.setColorDepth(COLOR_DEPTH);
    drawRpmBar(true);

    rpmSp.createSprite(RPM_SP_W - PADDING, RPM_SP_H - PADDING);
    rpmSp.setTextDatum(CR_DATUM);
    rpmSp.setTextFont(7);
    rpmSp.setTextSize(1);
    rpmSp.setColorDepth(COLOR_DEPTH);
    drawRPM(true);

    kphSp.createSprite(KPH_SP_W - PADDING, KPH_SP_H - PADDING);
    kphSp.setTextDatum(CR_DATUM);
    kphSp.setTextFont(7);
    kphSp.setTextSize(1);
    kphSp.setColorDepth(COLOR_DEPTH);
    drawKPH(true);

    gearSp.createSprite(GEAR_SP_W - PADDING, GEAR_SP_H - PADDING);
    gearSp.setFreeFont(FONT_70);
    gearSp.setTextDatum(TC_DATUM);
    gearSp.setTextSize(1);
    gearSp.setTextColor(TFT_WHITE);
    gearSp.setColorDepth(COLOR_DEPTH);
    drawGear(true);

    lapTimeSp.createSprite(LAP_TIME_SP_W - PADDING, LAP_TIME_SP_H - PADDING);
    lapTimeSp.setColorDepth(COLOR_DEPTH);
    lapTimeSp.setTextDatum(CL_DATUM);
    lapTimeSp.setFreeFont(FONT_14);
    lapTimeSp.setTextSize(1);
    lapTimeSp.setTextColor(TFT_WHITE, TFT_BLACK);
    drawLapTime(true);

    indicatorSp.createSprite(INDICATOR_SP_W, INDICATOR_SP_H);
    indicatorSp.setColorDepth(COLOR_DEPTH);
    indicatorSp.setTextDatum(BC_DATUM);
    indicatorSp.setFreeFont(FONT_11);
    indicatorSp.setTextSize(1);
    indicatorSp.setTextColor(TFT_BLACK, TFT_BLACK);
    drawIndicatorLabel(true);

    numSp.createSprite(NUM_SP_W - PADDING, NUM_SP_H - PADDING);
    numSp.setColorDepth(COLOR_DEPTH);
    numSp.setTextDatum(CC_DATUM);
    numSp.setFreeFont(FONT_12);
    numSp.setTextSize(1);
    numSp.setTextColor(TFT_WHITE, TFT_BLACK);
    drawNum(true);

    miniNumSp.createSprite(MINI_NUM_SP_W - PADDING, MINI_NUM_SP_H - PADDING);
    miniNumSp.setColorDepth(COLOR_DEPTH);
    miniNumSp.setTextDatum(CC_DATUM);
    miniNumSp.setFreeFont(FONT_9);
    miniNumSp.setTextSize(1);
    miniNumSp.setTextColor(TFT_WHITE, TFT_BLACK);
    drawMiniNum(true);

    dimmerLoop(true);
}

// =========================================================================
// Loop For Core 0
// =========================================================================
void loop()
{
    drawRpmBar(false);
    drawRPM(false);
    drawKPH(false);
    drawGear(false);
    drawIndicatorLabel(false);
    drawLapTime(false);
    drawNum(false);
    drawMiniNum(false);
    dimmerLoop(false);
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
