void rallyParseMsg()
{
    rpmValue = atoi(strtok(NULL, RPM_DELIMITER));
    rpmPctValue = atoi(strtok(NULL, RPM_DELIMITER));
    kphValue = atoi(strtok(NULL, KPH_DELIMITER));
    gearValue = atoi(strtok(NULL, GEAR_DELIMITER));
    shiftLightValue = atoi(strtok(NULL, GEAR_DELIMITER));
    bstLapTimeDeltaValue = atof(strtok(NULL, TIME_DELIMITER));
    curLapTimeValue = strtok(NULL, TIME_DELIMITER);
}

#define RALLY_DEFAULT_FONT FONT_11

#define RALLY_PADDING_DB 8
#define RALLY_PADDING 4
#define RALLY_PADDING_HF 2

#define RALLY_RPM_BAR_SP_W 480
#define RALLY_RPM_BAR_SP_H 50

#define RALLY_GEAR_SP_W 240
#define RALLY_GEAR_SP_H 240
#define RALLY_GEAR_SP_HF_W 120
#define RALLY_GEAR_SP_HF_H 120

#define RALLY_KPH_SP_W 240
#define RALLY_KPH_SP_H 110
#define RALLY_KPH_SP_HF_W 120
#define RALLY_KPH_SP_HF_H 55

#define RALLY_TIME_SP_W 240
#define RALLY_TIME_SP_H 46
#define RALLY_TIME_SP_HF_W 120
#define RALLY_TIME_SP_HF_H 23

TFT_eSprite rallyRpmBarSp = TFT_eSprite(&TFT);
TFT_eSprite rallyGearSp = TFT_eSprite(&TFT);
TFT_eSprite rallyKphSp = TFT_eSprite(&TFT);
TFT_eSprite rallyTimeSp = TFT_eSprite(&TFT);

void rallyDrawRpmBar(bool drawInitial)
{
    if (drawInitial || rpmPctValue != rpmPctValuePrev)
    {
        rpmPctValuePrev = rpmPctValue;

        changeShiftLightColor();

        rallyRpmBarSp.fillSprite(TFT_BLACK);

        rallyRpmBarSp.fillRect(
            0,
            0,
            map(rpmPctValue, 0, 100, 0, RALLY_RPM_BAR_SP_W),
            RALLY_RPM_BAR_SP_H,
            shiftLightColor);

        rallyRpmBarSp.pushSprite(RALLY_PADDING, RALLY_PADDING);
    }
}

void rallyDrawGear(bool drawInitial)
{
    if (drawInitial || gearValue != gearValuePrev || shiftLightValue != shiftLightValuePrev)
    {
        gearValuePrev = gearValue;
        shiftLightValuePrev = shiftLightValue;

        changeShiftLightColor();

        rallyGearSp.setTextColor(shiftLightColor);
        rallyGearSp.fillSprite(TFT_BLACK);

        switch (gearValue)
        {
        default:
            rallyGearSp.drawNumber(
                gearValue,
                RALLY_GEAR_SP_HF_W - RALLY_PADDING,
                RALLY_GEAR_SP_HF_H - 19);
            break;
        case -1:
            rallyGearSp.drawString(
                "R",
                RALLY_GEAR_SP_HF_W - RALLY_PADDING,
                RALLY_GEAR_SP_HF_H - 19);
            break;
        case 0:
            rallyGearSp.drawString(
                "N",
                RALLY_GEAR_SP_HF_W - RALLY_PADDING,
                RALLY_GEAR_SP_HF_H - 19);
            break;
        }

        rallyGearSp.pushSprite(RALLY_PADDING, TFT_H - RALLY_GEAR_SP_H + RALLY_PADDING);
    }
}

void rallyDrawKPH(bool drawInitial)
{
    if (drawInitial || kphValue != kphValuePrev)
    {
        kphValuePrev = kphValue;

        rallyKphSp.fillSprite(TFT_BLACK);

        rallyKphSp.drawNumber(
            kphValue,
            RALLY_KPH_SP_W - RALLY_PADDING_DB,
            RALLY_KPH_SP_HF_H - RALLY_PADDING);

        rallyKphSp.pushSprite(
            TFT_W - RALLY_KPH_SP_W + RALLY_PADDING,
            TFT_H - RALLY_GEAR_SP_H + RALLY_PADDING);
    }
}

void rallyDrawTime(bool drawInitial)
{
    if (drawInitial || bstLapTimeDeltaValue != bstLapTimeDeltaValuePrev)
    {
        bstLapTimeDeltaValuePrev = bstLapTimeDeltaValue;

        if (bstLapTimeDeltaValue < 0)
        {
            rallyTimeSp.setTextColor(TFT_GREEN, TFT_BLACK);
        }
        else if (bstLapTimeDeltaValue > 0)
        {
            rallyTimeSp.setTextColor(TFT_RED, TFT_BLACK);
        }
        else
        {
            rallyTimeSp.setTextColor(TFT_WHITE, TFT_BLACK);
        }

        rallyTimeSp.fillSprite(TFT_BLACK);

        rallyTimeSp.drawFloat(
            bstLapTimeDeltaValue,
            3,
            RALLY_TIME_SP_HF_W - RALLY_PADDING,
            RALLY_TIME_SP_HF_H - RALLY_PADDING);

        rallyTimeSp.pushSprite(
            TFT_W - RALLY_TIME_SP_W + RALLY_PADDING,
            TFT_H - RALLY_TIME_SP_H * 2 - FONT_14_HEIGHT + RALLY_PADDING + RALLY_PADDING_HF);
    }

    if (drawInitial || curLapTimeValue != curLapTimeValuePrev)
    {
        curLapTimeValuePrev = curLapTimeValue;

        rallyTimeSp.setTextColor(TFT_YELLOW, TFT_BLACK);
        rallyTimeSp.fillSprite(TFT_BLACK);
        rallyTimeSp.setTextDatum(CL_DATUM);

        rallyTimeSp.drawString(
            curLapTimeValue,
            RALLY_PADDING_DB * 2,
            RALLY_TIME_SP_HF_H - RALLY_PADDING);

        rallyTimeSp.pushSprite(
            TFT_W - RALLY_TIME_SP_W + RALLY_PADDING,
            TFT_H - RALLY_TIME_SP_H + RALLY_PADDING);
    }
}

void rallyDrawOnce()
{
    // RPM BAR
    TFT.fillRoundRect(
        0,
        0,
        RALLY_RPM_BAR_SP_W,
        RALLY_RPM_BAR_SP_H + 30,
        0,
        TFT_LIGHTGREY);

    // GEAR
    TFT.fillRoundRect(
        0,
        TFT_H - RALLY_GEAR_SP_H,
        RALLY_GEAR_SP_W,
        RALLY_GEAR_SP_H,
        0,
        TFT_DARKGREEN);

    // 
    TFT.fillRoundRect(
        RALLY_GEAR_SP_W,
        TFT_H - RALLY_GEAR_SP_H,
        RALLY_GEAR_SP_W,
        RALLY_GEAR_SP_H,
        0,
        TFT_DARKCYAN);

    TFT.setTextColor(TFT_BLACK);
    TFT.setTextDatum(TC_DATUM);

    TFT.drawString(
        "Gear",
        RALLY_GEAR_SP_HF_W,
        RALLY_RPM_BAR_SP_H + RALLY_PADDING);

    TFT.drawString(
        "Km/H",
        TFT_W - RALLY_KPH_SP_HF_W,
        RALLY_RPM_BAR_SP_H + RALLY_PADDING);

    TFT.setTextDatum(BC_DATUM);

    TFT.drawString(
        "Delta",
        TFT_W - RALLY_KPH_SP_HF_W,
        TFT_H - RALLY_TIME_SP_H * 2 - FONT_14_HEIGHT + RALLY_PADDING);

    TFT.drawString(
        "Stage Time",
        TFT_W - RALLY_KPH_SP_HF_W,
        TFT_H - RALLY_TIME_SP_H + RALLY_PADDING_HF);
}

void rallySetup()
{
    TFT.fillScreen(TFT_BLACK);
    TFT.setFreeFont(FONT_14);
    TFT.setTextSize(1);
    TFT.setTextColor(TFT_LIGHTGREY);
    rallyDrawOnce();

    rallyRpmBarSp.createSprite(RALLY_RPM_BAR_SP_W - RALLY_PADDING_DB, RALLY_RPM_BAR_SP_H - RALLY_PADDING_DB);
    rallyRpmBarSp.setColorDepth(COLOR_DEPTH);
    rallyDrawRpmBar(true);

    rallyGearSp.createSprite(RALLY_GEAR_SP_W - RALLY_PADDING_DB, RALLY_GEAR_SP_H - RALLY_PADDING_DB);
    rallyGearSp.setTextDatum(CC_DATUM);
    rallyGearSp.setFreeFont(FONT_76);
    rallyGearSp.setTextColor(TFT_WHITE);
    rallyGearSp.setTextSize(2);
    rallyGearSp.setColorDepth(COLOR_DEPTH);
    rallyDrawGear(true);

    rallyKphSp.createSprite(RALLY_KPH_SP_W - RALLY_PADDING_DB, RALLY_KPH_SP_H - RALLY_PADDING_DB);
    rallyKphSp.setTextDatum(CR_DATUM);
    rallyKphSp.setFreeFont(FONT_70);
    rallyKphSp.setTextColor(TFT_WHITE);
    rallyKphSp.setTextSize(1);
    rallyKphSp.setColorDepth(COLOR_DEPTH);
    rallyDrawKPH(true);

    rallyTimeSp.createSprite(RALLY_TIME_SP_W - RALLY_PADDING_DB, RALLY_TIME_SP_H - RALLY_PADDING_DB);
    rallyTimeSp.setTextDatum(CC_DATUM);
    rallyTimeSp.setFreeFont(FONT_20);
    rallyTimeSp.setTextColor(TFT_WHITE);
    rallyTimeSp.setTextSize(1);
    rallyTimeSp.setColorDepth(COLOR_DEPTH);
    rallyDrawTime(true);
}

void rallyLoop()
{
    rallyDrawRpmBar(false);
    rallyDrawGear(false);
    rallyDrawKPH(false);
    rallyDrawTime(false);
}