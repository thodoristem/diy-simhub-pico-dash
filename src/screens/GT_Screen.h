void gtParseMsg()
{
    rpmValue = atoi(strtok(NULL, RPM_DELIMITER));
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
}

#define GT_DEFAULT_FONT FONT_11

#define GT_PADDING_DB 8
#define GT_PADDING 4
#define GT_PADDING_HF 2

#define GT_RPM_BAR_SP_W 480
#define GT_RPM_BAR_SP_H 20

#define GT_RPM_SP_W 184
#define GT_RPM_SP_H 58
#define GT_RPM_SP_HF_W 92
#define GT_RPM_SP_HF_H 29

#define GT_GEAR_SP_W 108
#define GT_GEAR_SP_H 120
#define GT_GEAR_SP_HF_W 54
#define GT_GEAR_SP_HF_H 60

#define GT_KPH_SP_W 184
#define GT_KPH_SP_H 58
#define GT_KPH_SP_HF_W 92
#define GT_KPH_SP_HF_H 29

#define GT_LAP_TIME_SP_W 152
#define GT_LAP_TIME_SP_H 26
#define GT_LAP_TIME_SP_HF_W 76
#define GT_LAP_TIME_SP_HF_H 13

#define GT_INDICATOR_SP_W 46
#define GT_INDICATOR_SP_H 24
#define GT_INDICATOR_SP_HF_W 23
#define GT_INDICATOR_SP_HF_H 12

#define GT_NUM_SP_W 72
#define GT_NUM_SP_H 30
#define GT_NUM_SP_HF_W 36
#define GT_NUM_SP_HF_H 15

#define GT_MINI_NUM_SP_W 72
#define GT_MINI_NUM_SP_H 24
#define GT_MINI_NUM_SP_HF_W 36
#define GT_MINI_NUM_SP_HF_H 12

#define GT_LAP_SP_W 50
#define GT_LAP_SP_H 36
#define GT_LAP_SP_HF_W 25
#define GT_LAP_SP_HF_H 18

TFT_eSprite gtRpmBarSp = TFT_eSprite(&TFT);
TFT_eSprite gtRpmSp = TFT_eSprite(&TFT);
TFT_eSprite gtKphSp = TFT_eSprite(&TFT);
TFT_eSprite gtGearSp = TFT_eSprite(&TFT);
TFT_eSprite gtLapTimeSp = TFT_eSprite(&TFT);
TFT_eSprite gtIndicatorSp = TFT_eSprite(&TFT);
TFT_eSprite gtNumSp = TFT_eSprite(&TFT);
TFT_eSprite gtMiniNumSp = TFT_eSprite(&TFT);

void gtDrawRpmBar(bool drawInitial)
{
    if (drawInitial || rpmPctValue != rpmPctValuePrev)
    {
        rpmPctValuePrev = rpmPctValue;

        changeShiftLightColor();

        gtRpmBarSp.fillSprite(TFT_BLACK);
        gtRpmBarSp.fillRect(0, 0, map(rpmPctValue, 0, 100, 0, GT_RPM_BAR_SP_W), GT_RPM_BAR_SP_H, shiftLightColor);

        gtRpmBarSp.pushSprite(GT_PADDING_HF, GT_PADDING_HF);
    }
}

void gtDrawRPM(bool drawInitial)
{
    if (drawInitial || rpmValue != rpmValuePrev)
    {
        rpmValuePrev = rpmValue;
        gtRpmSp.fillSprite(TFT_BLACK);
        gtRpmSp.setTextColor(TFT_WHITE);
        gtRpmSp.drawNumber(rpmValue, GT_RPM_SP_W - GT_PADDING_DB, GT_RPM_SP_HF_H - GT_PADDING_HF);
        gtRpmSp.pushSprite(GT_PADDING_HF, GT_RPM_BAR_SP_H + GT_PADDING);
    }
}

void gtDrawKPH(bool drawInitial)
{
    if (drawInitial || kphValue != kphValuePrev)
    {
        kphValuePrev = kphValue;
        gtKphSp.fillSprite(TFT_BLACK);
        gtKphSp.setTextColor(TFT_WHITE);
        gtKphSp.drawNumber(kphValue, GT_KPH_SP_W - GT_PADDING_DB, GT_KPH_SP_HF_H - GT_PADDING_HF);
        gtKphSp.pushSprite(TFT.width() - GT_KPH_SP_W + GT_PADDING_HF, GT_RPM_BAR_SP_H + GT_PADDING);
    }
}

void gtDrawGear(bool drawInitial)
{
    if (drawInitial || gearValue != gearValuePrev || shiftLightValue != shiftLightValuePrev)
    {
        gearValuePrev = gearValue;
        shiftLightValuePrev = shiftLightValue;

        changeShiftLightColor();

        gtGearSp.fillSprite(TFT_BLACK);
        gtGearSp.setTextColor(shiftLightColor);
        switch (gearValue)
        {
        default:
            gtGearSp.drawNumber(gearValue, GT_GEAR_SP_HF_W - GT_PADDING_HF, GT_PADDING_DB + GT_PADDING);
            break;
        case -1:
            gtGearSp.drawString("R", GT_GEAR_SP_HF_W - GT_PADDING - GT_PADDING_HF, GT_PADDING_DB + GT_PADDING);
            break;
        case 0:
            gtGearSp.drawString("N", GT_GEAR_SP_HF_W - GT_PADDING - GT_PADDING_HF, GT_PADDING_DB + GT_PADDING);
            break;
        }
        gtGearSp.pushSprite(TFT_HF_W - GT_GEAR_SP_HF_W + GT_PADDING_HF, GT_RPM_BAR_SP_H + GT_PADDING);
    }
}

void gtDrawIndicatorLabel(bool drawInitial)
{
    if (drawInitial || drsValue != drsValuePrev)
    {
        drsValuePrev = drsValue;
        gtIndicatorSp.fillSprite(TFT_DARKGREY);
        switch (drsValue)
        {
        case 0:
            gtIndicatorSp.setTextColor(TFT_BLACK);
            break;
        case 1:
            gtIndicatorSp.setTextColor(TFT_WHITE);
            break;
        case 2:
            gtIndicatorSp.setTextColor(TFT_CYAN);
            break;
        }
        gtIndicatorSp.drawString("DRS", GT_INDICATOR_SP_HF_W - GT_PADDING_HF, GT_INDICATOR_SP_H - GT_PADDING);
        gtIndicatorSp.pushSprite(TFT.width() - GT_KPH_SP_W, GT_RPM_BAR_SP_H + GT_KPH_SP_H + GT_PADDING);
    }

    if (drawInitial || pitValue != pitValuePrev)
    {
        pitValuePrev = pitValue;
        gtIndicatorSp.fillSprite(TFT_DARKGREY);
        switch (pitValue)
        {
        case 0:
            gtIndicatorSp.setTextColor(TFT_BLACK);
            break;
        case 1:
            gtIndicatorSp.setTextColor(TFT_YELLOW);
            break;
        case 2:
            gtIndicatorSp.setTextColor(TFT_ORANGE);
            break;
        }
        gtIndicatorSp.drawString("PIT", GT_INDICATOR_SP_HF_W - GT_PADDING_HF, GT_INDICATOR_SP_H - GT_PADDING);
        gtIndicatorSp.pushSprite(TFT.width() - GT_KPH_SP_W + GT_INDICATOR_SP_W + GT_PADDING_HF, GT_RPM_BAR_SP_H + GT_KPH_SP_H + GT_PADDING);
    }
}

void gtDrawNum(bool drawInitial)
{
    if (drawInitial || absValue != absValuePrev)
    {
        absValuePrev = absValue;
        gtNumSp.fillSprite(TFT_BLACK);
        gtNumSp.drawNumber(
            absValue,
            GT_NUM_SP_HF_W - GT_PADDING_HF - GT_PADDING_HF / 2,
            GT_NUM_SP_HF_H - GT_PADDING);
        gtNumSp.pushSprite(
            TFT.width() - GT_NUM_SP_W - GT_NUM_SP_W,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + FONT_11_HEIGHT + GT_PADDING * 3);
    }

    if (drawInitial || tcValue != tcValuePrev)
    {
        tcValuePrev = tcValue;
        gtNumSp.fillSprite(TFT_BLACK);
        gtNumSp.drawNumber(
            tcValue,
            GT_NUM_SP_HF_W - GT_PADDING_HF - GT_PADDING_HF / 2,
            GT_NUM_SP_HF_H - GT_PADDING);
        gtNumSp.pushSprite(
            TFT.width() - GT_NUM_SP_W - GT_NUM_SP_W,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_11_HEIGHT * 2 + GT_PADDING * 6);
    }

    if (drawInitial || brakeBias != brakeBiasPrev)
    {
        brakeBiasPrev = brakeBias;
        gtNumSp.fillSprite(TFT_BLACK);
        gtNumSp.drawFloat(
            brakeBias,
            1,
            GT_NUM_SP_HF_W - GT_PADDING_HF - GT_PADDING_HF / 2,
            GT_NUM_SP_HF_H - GT_PADDING);
        gtNumSp.pushSprite(
            TFT.width() - GT_NUM_SP_W - GT_NUM_SP_W,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H * 2 + FONT_11_HEIGHT * 3 + GT_PADDING * 9);
    }

    if (drawInitial || fuelValue != fuelValuePrev)
    {
        fuelValuePrev = fuelValue;
        gtNumSp.fillSprite(TFT_BLACK);
        gtNumSp.drawFloat(
            fuelValue,
            1,
            GT_NUM_SP_HF_W - GT_PADDING_HF - GT_PADDING_HF / 2,
            GT_NUM_SP_HF_H - GT_PADDING);
        gtNumSp.pushSprite(
            TFT.width() - GT_NUM_SP_W + GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + FONT_11_HEIGHT + GT_PADDING * 3);
    }

    if (drawInitial || ersValue != ersValuePrev)
    {
        ersValuePrev = ersValue;
        gtNumSp.fillSprite(TFT_BLACK);
        gtNumSp.drawFloat(
            ersValue,
            1,
            GT_NUM_SP_HF_W - GT_PADDING_HF - GT_PADDING_HF / 2,
            GT_NUM_SP_HF_H - GT_PADDING);
        gtNumSp.pushSprite(
            TFT.width() - GT_NUM_SP_W + GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_11_HEIGHT * 2 + GT_PADDING * 6);
    }

    if (drawInitial || turboPct != turboPctPrev)
    {
        turboPctPrev = turboPct;
        gtNumSp.fillSprite(TFT_BLACK);
        gtNumSp.drawFloat(
            turboPct,
            1,
            GT_NUM_SP_HF_W - GT_PADDING_HF - GT_PADDING_HF / 2,
            GT_NUM_SP_HF_H - GT_PADDING);
        gtNumSp.pushSprite(
            TFT.width() - GT_NUM_SP_W + GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H * 2 + FONT_11_HEIGHT * 3 + GT_PADDING * 9);
    }

    if (drawInitial || positionValue != positionValuePrev || positionsTotalValue != positionsTotalValuePrev)
    {
        positionValuePrev = positionValue;
        positionsTotalValuePrev = positionsTotalValue;
        gtNumSp.fillSprite(TFT_BLACK);
        gtNumSp.drawString(
            positionValue + "|" + positionsTotalValue,
            GT_NUM_SP_HF_W - GT_PADDING_HF - GT_PADDING_HF / 2,
            GT_NUM_SP_HF_H - GT_PADDING);
        gtNumSp.pushSprite(
            GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + FONT_11_HEIGHT + GT_PADDING * 3);
    }

    if (drawInitial || lapCurrentValue != lapCurrentValuePrev || lapsTotalValue != lapsTotalValuePrev)
    {
        lapCurrentValuePrev = lapCurrentValue;
        lapsTotalValuePrev = lapsTotalValue;
        gtNumSp.fillSprite(TFT_BLACK);
        gtNumSp.drawString(
            lapCurrentValue + "|" + lapsTotalValue,
            GT_NUM_SP_HF_W - GT_PADDING_HF - GT_PADDING_HF / 2,
            GT_NUM_SP_HF_H - GT_PADDING);
        gtNumSp.pushSprite(
            GT_NUM_SP_W + GT_PADDING,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + FONT_11_HEIGHT + GT_PADDING * 3);
    }
}

void gtDrawMiniNum(bool drawInitial)
{
    if (drawInitial || tyreTempFLValue != tyreTempFLValuePrev)
    {
        tyreTempFLValuePrev = tyreTempFLValue;
        gtMiniNumSp.fillSprite(TFT_BLACK);
        gtMiniNumSp.setTextDatum(CL_DATUM);
        gtMiniNumSp.drawString(
            "C" + String(tyreTempFLValue, 1),
            GT_PADDING,
            GT_MINI_NUM_SP_HF_H - GT_PADDING + 1);
        gtMiniNumSp.pushSprite(
            GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_16_HEIGHT * 2 + GT_MINI_NUM_SP_H + GT_PADDING + GT_PADDING_HF);
    }

    if (drawInitial || tyreTempRLValue != tyreTempRLValuePrev)
    {
        tyreTempRLValuePrev = tyreTempRLValue;
        gtMiniNumSp.fillSprite(TFT_BLACK);
        gtMiniNumSp.setTextDatum(CL_DATUM);
        gtMiniNumSp.drawString(
            "C" + String(tyreTempRLValue, 1),
            GT_PADDING,
            GT_MINI_NUM_SP_HF_H - GT_PADDING + 1);
        gtMiniNumSp.pushSprite(
            GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_16_HEIGHT * 2 + GT_MINI_NUM_SP_H * 2 + GT_PADDING + GT_PADDING_HF);
    }

    if (drawInitial || tyreTempFRValue != tyreTempFRValuePrev)
    {
        tyreTempFRValuePrev = tyreTempFRValue;
        gtMiniNumSp.fillSprite(TFT_BLACK);
        gtMiniNumSp.setTextDatum(CR_DATUM);
        gtMiniNumSp.drawString(
            String(tyreTempFRValue, 1) + "C",
            GT_MINI_NUM_SP_W - GT_PADDING_DB,
            GT_MINI_NUM_SP_HF_H - GT_PADDING + 1);
        gtMiniNumSp.pushSprite(
            GT_MINI_NUM_SP_W + GT_PADDING,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_16_HEIGHT * 2 + GT_MINI_NUM_SP_H + GT_PADDING + GT_PADDING_HF);
    }

    if (drawInitial || tyreTempRRValue != tyreTempRRValuePrev)
    {
        tyreTempRRValuePrev = tyreTempRRValue;
        gtMiniNumSp.fillSprite(TFT_BLACK);
        gtMiniNumSp.setTextDatum(CR_DATUM);
        gtMiniNumSp.drawString(
            String(tyreTempRRValue, 1) + "C",
            GT_MINI_NUM_SP_W - GT_PADDING_DB,
            GT_MINI_NUM_SP_HF_H - GT_PADDING + 1);
        gtMiniNumSp.pushSprite(
            GT_MINI_NUM_SP_W + GT_PADDING,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_16_HEIGHT * 2 + GT_MINI_NUM_SP_H * 2 + GT_PADDING + GT_PADDING_HF);
    }

    if (drawInitial || tyrePressureFLValue != tyrePressureFLValuePrev)
    {
        tyrePressureFLValuePrev = tyrePressureFLValue;
        gtMiniNumSp.fillSprite(TFT_BLACK);
        gtMiniNumSp.setTextDatum(CL_DATUM);
        gtMiniNumSp.drawString(
            "P" + String(tyrePressureFLValue, 1),
            GT_PADDING,
            GT_MINI_NUM_SP_HF_H - GT_PADDING + 1);
        gtMiniNumSp.pushSprite(
            GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_16_HEIGHT * 2 + GT_PADDING_DB);
    }

    if (drawInitial || tyrePressureRLValue != tyrePressureRLValuePrev)
    {
        tyrePressureRLValuePrev = tyrePressureRLValue;
        gtMiniNumSp.fillSprite(TFT_BLACK);
        gtMiniNumSp.setTextDatum(CL_DATUM);
        gtMiniNumSp.drawString(
            "P" + String(tyrePressureRLValue, 1),
            GT_PADDING,
            GT_MINI_NUM_SP_HF_H - GT_PADDING + 1);
        gtMiniNumSp.pushSprite(
            GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_16_HEIGHT * 2 + GT_MINI_NUM_SP_H * 3 + GT_PADDING);
    }

    if (drawInitial || tyrePressureFRValue != tyrePressureFRValuePrev)
    {
        tyrePressureFRValuePrev = tyrePressureFRValue;
        gtMiniNumSp.fillSprite(TFT_BLACK);
        gtMiniNumSp.setTextDatum(CR_DATUM);
        gtMiniNumSp.drawString(
            String(tyrePressureFRValue, 1) + "P",
            GT_MINI_NUM_SP_W - GT_PADDING_DB,
            GT_MINI_NUM_SP_HF_H - GT_PADDING + 1);
        gtMiniNumSp.pushSprite(
            GT_MINI_NUM_SP_W + GT_PADDING,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_16_HEIGHT * 2 + GT_PADDING_DB);
    }

    if (drawInitial || tyrePressureRRValue != tyrePressureRRValuePrev)
    {
        tyrePressureRRValuePrev = tyrePressureRRValue;
        gtMiniNumSp.fillSprite(TFT_BLACK);
        gtMiniNumSp.setTextDatum(CR_DATUM);
        gtMiniNumSp.drawString(
            String(tyrePressureRRValue, 1) + "P",
            GT_MINI_NUM_SP_W - GT_PADDING_DB,
            GT_MINI_NUM_SP_HF_H - GT_PADDING + 1);
        gtMiniNumSp.pushSprite(
            GT_MINI_NUM_SP_W + GT_PADDING,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_16_HEIGHT * 2 + GT_MINI_NUM_SP_H * 3 + GT_PADDING);
    }
}

void gtDrawLapTime(bool drawInitial)
{
    if (drawInitial || bstLapTimeDeltaValue != bstLapTimeDeltaValuePrev)
    {
        bstLapTimeDeltaValuePrev = bstLapTimeDeltaValue;
        if (bstLapTimeDeltaValue < 0)
        {
            gtLapTimeSp.setTextColor(TFT_GREEN, TFT_BLACK);
        }
        else if (bstLapTimeDeltaValue > 0)
        {
            gtLapTimeSp.setTextColor(TFT_RED, TFT_BLACK);
        }
        else
        {
            gtLapTimeSp.setTextColor(TFT_WHITE, TFT_BLACK);
        }
        gtLapTimeSp.setTextDatum(CC_DATUM);
        gtLapTimeSp.fillSprite(TFT_BLACK);
        gtLapTimeSp.drawFloat(
            bstLapTimeDeltaValue,
            3,
            GT_LAP_TIME_SP_HF_W - GT_PADDING_HF,
            GT_LAP_TIME_SP_HF_H - GT_PADDING_HF);
        gtLapTimeSp.pushSprite(
            TFT_HF_W - GT_LAP_TIME_SP_HF_W + GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + FONT_9_HEIGHT + GT_PADDING_HF * 5);
        gtLapTimeSp.setTextDatum(CL_DATUM);
        gtLapTimeSp.setTextColor(TFT_WHITE, TFT_BLACK);
    }

    if (drawInitial || curLapTimeValue != curLapTimeValuePrev)
    {
        curLapTimeValuePrev = curLapTimeValue;
        gtLapTimeSp.fillSprite(TFT_BLACK);
        gtLapTimeSp.setTextColor(TFT_YELLOW);
        gtLapTimeSp.drawString(
            curLapTimeValue,
            GT_PADDING_HF,
            GT_LAP_TIME_SP_HF_H - GT_PADDING_HF);
        gtLapTimeSp.pushSprite(
            TFT_HF_W - GT_LAP_TIME_SP_HF_W + GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_LAP_TIME_SP_H + FONT_9_HEIGHT * 2 + GT_PADDING_HF * 7);
    }

    if (drawInitial || bstLapTimeValue != bstLapTimeValuePrev)
    {
        bstLapTimeValuePrev = bstLapTimeValue;
        gtLapTimeSp.fillSprite(TFT_BLACK);
        gtLapTimeSp.setTextColor(TFT_GREENYELLOW);
        gtLapTimeSp.drawString(
            bstLapTimeValue,
            GT_PADDING_HF,
            GT_LAP_TIME_SP_HF_H - GT_PADDING_HF);
        gtLapTimeSp.pushSprite(
            TFT_HF_W - GT_LAP_TIME_SP_HF_W + GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_LAP_TIME_SP_H * 2 + FONT_9_HEIGHT * 3 + GT_PADDING_HF * 9);
    }

    if (drawInitial || bstSessionLapTimeValue != bstSessionLapTimeValuePrev)
    {
        bstSessionLapTimeValuePrev = bstSessionLapTimeValue;
        gtLapTimeSp.fillSprite(TFT_BLACK);
        gtLapTimeSp.setTextColor(TFT_MAGENTA);
        gtLapTimeSp.drawString(
            bstSessionLapTimeValue,
            GT_PADDING_HF,
            GT_LAP_TIME_SP_HF_H - GT_PADDING_HF);
        gtLapTimeSp.pushSprite(
            TFT_HF_W - GT_LAP_TIME_SP_HF_W + GT_PADDING_HF,
            GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_LAP_TIME_SP_H * 3 + FONT_9_HEIGHT * 4 + GT_PADDING_HF * 11);
    }
}

void gtDrawOnce()
{
    // RPM BAR
    TFT.fillRoundRect(
        0,
        0,
        GT_RPM_BAR_SP_W,
        GT_RPM_BAR_SP_H,
        0,
        TFT_WHITE);

    // RPM
    TFT.fillRoundRect(
        0,
        GT_RPM_BAR_SP_H + GT_PADDING_HF,
        GT_KPH_SP_W,
        GT_KPH_SP_H,
        0,
        TFT_YELLOW);

    TFT.setTextDatum(TL_DATUM);
    TFT.drawString(
        "RPM",
        GT_PADDING_HF,
        GT_RPM_BAR_SP_H + GT_RPM_SP_H + GT_PADDING);

    // GEAR
    TFT.fillRoundRect(
        TFT_HF_W - GT_GEAR_SP_HF_W,
        GT_RPM_BAR_SP_H + GT_PADDING_HF,
        GT_GEAR_SP_W,
        GT_GEAR_SP_H,
        0,
        TFT_CYAN);

    // KPH
    TFT.fillRoundRect(
        TFT.width() - GT_KPH_SP_W,
        GT_RPM_BAR_SP_H + GT_PADDING_HF,
        GT_RPM_SP_W,
        GT_RPM_SP_H,
        0,
        TFT_YELLOW);

    TFT.setTextDatum(TR_DATUM);
    TFT.drawString(
        "KPH",
        TFT.width() - GT_PADDING_HF,
        GT_RPM_BAR_SP_H + GT_RPM_SP_H + GT_PADDING);

    // GT_LAP TIMING
    TFT.setFreeFont(FONT_9);
    TFT.setTextDatum(TC_DATUM);

    TFT.drawRoundRect(
        TFT_HF_W - GT_LAP_TIME_SP_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING,
        GT_LAP_TIME_SP_W,
        GT_LAP_TIME_SP_H * 4 + FONT_9_HEIGHT * 4 + GT_PADDING_HF * 9,
        5,
        TFT_WHITE);

    TFT.drawString(
        "Delta",
        TFT_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING_HF * 4);

    TFT.drawRect(
        TFT_HF_W - GT_LAP_TIME_SP_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_LAP_TIME_SP_H + FONT_9_HEIGHT + GT_PADDING_HF * 4,
        GT_LAP_TIME_SP_W,
        1,
        TFT_WHITE);

    TFT.drawString(
        "Current",
        TFT_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_LAP_TIME_SP_H + FONT_9_HEIGHT + GT_PADDING_HF * 6);

    TFT.drawRect(
        TFT_HF_W - GT_LAP_TIME_SP_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_LAP_TIME_SP_H * 2 + FONT_9_HEIGHT * 2 + GT_PADDING_HF * 6,
        GT_LAP_TIME_SP_W,
        1,
        TFT_WHITE);

    TFT.drawString(
        "Best",
        TFT_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_LAP_TIME_SP_H * 2 + FONT_9_HEIGHT * 2 + GT_PADDING_HF * 8);

    TFT.drawRect(
        TFT_HF_W - GT_LAP_TIME_SP_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_LAP_TIME_SP_H * 3 + FONT_9_HEIGHT * 3 + GT_PADDING_HF * 8,
        GT_LAP_TIME_SP_W,
        1,
        TFT_WHITE);

    TFT.drawString(
        "Session",
        TFT_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_LAP_TIME_SP_H * 3 + FONT_9_HEIGHT * 3 + GT_PADDING_HF * 10);

    TFT.setFreeFont(FONT_11);

    // FUEL
    TFT.drawRoundRect(
        TFT.width() - GT_NUM_SP_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING,
        GT_NUM_SP_W,
        GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB + GT_PADDING_HF,
        5,
        TFT_ORANGE);

    TFT.drawString(
        "Fuel%",
        TFT.width() - GT_NUM_SP_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING_DB);

    // ABS
    TFT.drawRoundRect(
        TFT.width() - GT_NUM_SP_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB * 2,
        GT_NUM_SP_W,
        GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB + GT_PADDING_HF,
        5,
        TFT_DARKCYAN);

    TFT.drawString(
        "ERS%",
        TFT.width() - GT_NUM_SP_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB * 2 + GT_PADDING);

    // BOOST
    TFT.drawRoundRect(
        TFT.width() - GT_NUM_SP_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + GT_PADDING_DB * 3 + GT_PADDING,
        GT_NUM_SP_W,
        GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB + GT_PADDING_HF,
        5,
        TFT_DARKCYAN);

    TFT.drawString(
        "BST%",
        TFT.width() - GT_NUM_SP_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + GT_PADDING_DB * 4);

    // ERS
    TFT.drawRoundRect(
        TFT.width() - GT_NUM_SP_W * 2 - GT_PADDING_HF,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING,
        GT_NUM_SP_W,
        GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB + GT_PADDING_HF,
        5,
        TFT_DARKGREY);

    TFT.drawString(
        "ABS",
        TFT.width() - GT_NUM_SP_HF_W * 3 - GT_PADDING_HF * 2,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING_DB);

    // TC
    TFT.drawRoundRect(
        TFT.width() - GT_NUM_SP_W * 2 - GT_PADDING_HF,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB * 2,
        GT_NUM_SP_W,
        GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB + GT_PADDING_HF,
        5,
        TFT_DARKGREY);

    TFT.drawString(
        "TC",
        TFT.width() - GT_NUM_SP_HF_W * 3 - GT_PADDING_HF * 2,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB * 2 + GT_PADDING);

    // BIAS
    TFT.drawRoundRect(
        TFT.width() - GT_NUM_SP_W * 2 - GT_PADDING_HF,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + GT_PADDING_DB * 3 + GT_PADDING,
        GT_NUM_SP_W,
        GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB + GT_PADDING_HF,
        5,
        TFT_RED);

    TFT.drawString(
        "BB",
        TFT.width() - GT_NUM_SP_HF_W * 3 - GT_PADDING_HF * 2,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + GT_PADDING_DB * 4);

    // POSITION
    TFT.drawRoundRect(
        0,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING,
        GT_NUM_SP_W,
        GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB + GT_PADDING_HF,
        5,
        TFT_DARKGREEN);

    TFT.drawString(
        "POS",
        GT_NUM_SP_HF_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING_DB);

    // GT_LAP COUNT
    TFT.drawRoundRect(
        GT_NUM_SP_W + GT_PADDING_HF,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING,
        GT_NUM_SP_W,
        GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB + GT_PADDING_HF,
        5,
        TFT_DARKGREEN);

    TFT.drawString(
        "LAP",
        GT_NUM_SP_HF_W * 3 + GT_PADDING_HF,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_PADDING_DB);

    // TYRE/BRAKE TEMPS
    TFT.drawRoundRect(
        0,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB * 2,
        GT_NUM_SP_W * 2 + GT_PADDING_HF,
        GT_NUM_SP_H * 2 + FONT_11_HEIGHT * 2 + FONT_16_HEIGHT - GT_PADDING_HF,
        5,
        TFT_GREENYELLOW);

    TFT.drawString(
        "Tyres",
        GT_NUM_SP_HF_W * 2 + GT_PADDING_HF,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_11_HEIGHT + GT_PADDING_DB * 2 + GT_PADDING);

    TFT.drawRect(
        GT_PADDING,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H * 2 + FONT_11_HEIGHT * 3 + GT_PADDING_DB * 2 + GT_PADDING,
        GT_NUM_SP_W * 2 + GT_PADDING_HF - GT_PADDING_DB,
        2,
        TFT_GREENYELLOW);

    TFT.drawRect(
        GT_NUM_SP_W,
        GT_RPM_BAR_SP_H + GT_GEAR_SP_H + GT_NUM_SP_H + FONT_11_HEIGHT * 2 + FONT_16_HEIGHT + GT_PADDING_HF,
        2,
        GT_NUM_SP_H * 2 + FONT_11_HEIGHT + GT_PADDING_DB,
        TFT_GREENYELLOW);
}

void gtSetup()
{
    TFT.fillScreen(TFT_BLACK);
    TFT.setFreeFont(GT_DEFAULT_FONT);
    TFT.setTextSize(1);
    TFT.setTextColor(TFT_DARKGREY);
    gtDrawOnce();

    gtRpmBarSp.createSprite(GT_RPM_BAR_SP_W - GT_PADDING, GT_RPM_BAR_SP_H - GT_PADDING);
    gtRpmBarSp.setColorDepth(COLOR_DEPTH);
    gtDrawRpmBar(true);

    gtRpmSp.createSprite(GT_RPM_SP_W - GT_PADDING, GT_RPM_SP_H - GT_PADDING);
    gtRpmSp.setTextDatum(CR_DATUM);
    gtRpmSp.setTextFont(7);
    gtRpmSp.setTextSize(1);
    gtRpmSp.setColorDepth(COLOR_DEPTH);
    gtDrawRPM(true);

    gtKphSp.createSprite(GT_KPH_SP_W - GT_PADDING, GT_KPH_SP_H - GT_PADDING);
    gtKphSp.setTextDatum(CR_DATUM);
    gtKphSp.setTextFont(7);
    gtKphSp.setTextSize(1);
    gtKphSp.setColorDepth(COLOR_DEPTH);
    gtDrawKPH(true);

    gtGearSp.createSprite(GT_GEAR_SP_W - GT_PADDING, GT_GEAR_SP_H - GT_PADDING);
    gtGearSp.setFreeFont(FONT_70);
    gtGearSp.setTextDatum(TC_DATUM);
    gtGearSp.setTextSize(1);
    gtGearSp.setTextColor(TFT_WHITE);
    gtGearSp.setColorDepth(COLOR_DEPTH);
    gtDrawGear(true);

    gtLapTimeSp.createSprite(GT_LAP_TIME_SP_W - GT_PADDING, GT_LAP_TIME_SP_H - GT_PADDING);
    gtLapTimeSp.setColorDepth(COLOR_DEPTH);
    gtLapTimeSp.setTextDatum(CL_DATUM);
    gtLapTimeSp.setFreeFont(FONT_14);
    gtLapTimeSp.setTextSize(1);
    gtLapTimeSp.setTextColor(TFT_WHITE, TFT_BLACK);
    gtDrawLapTime(true);

    gtIndicatorSp.createSprite(GT_INDICATOR_SP_W, GT_INDICATOR_SP_H);
    gtIndicatorSp.setColorDepth(COLOR_DEPTH);
    gtIndicatorSp.setTextDatum(BC_DATUM);
    gtIndicatorSp.setFreeFont(FONT_11);
    gtIndicatorSp.setTextSize(1);
    gtIndicatorSp.setTextColor(TFT_BLACK, TFT_BLACK);
    gtDrawIndicatorLabel(true);

    gtNumSp.createSprite(GT_NUM_SP_W - GT_PADDING, GT_NUM_SP_H - GT_PADDING);
    gtNumSp.setColorDepth(COLOR_DEPTH);
    gtNumSp.setTextDatum(CC_DATUM);
    gtNumSp.setFreeFont(FONT_12);
    gtNumSp.setTextSize(1);
    gtNumSp.setTextColor(TFT_WHITE, TFT_BLACK);
    gtDrawNum(true);

    gtMiniNumSp.createSprite(GT_MINI_NUM_SP_W - GT_PADDING, GT_MINI_NUM_SP_H - GT_PADDING);
    gtMiniNumSp.setColorDepth(COLOR_DEPTH);
    gtMiniNumSp.setTextDatum(CC_DATUM);
    gtMiniNumSp.setFreeFont(FONT_9);
    gtMiniNumSp.setTextSize(1);
    gtMiniNumSp.setTextColor(TFT_WHITE, TFT_BLACK);
    gtDrawMiniNum(true);
}

void gtLoop()
{
    gtDrawRpmBar(false);
    gtDrawRPM(false);
    gtDrawKPH(false);
    gtDrawGear(false);
    gtDrawIndicatorLabel(false);
    gtDrawLapTime(false);
    gtDrawNum(false);
    gtDrawMiniNum(false);
}