#include <Arduino.h>
#include <TFT_eSPI.h>

const uint8_t whitrabt16pt7bBitmaps[] PROGMEM = {
  0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
  0x3F, 0xFF, 0xFF, 0xFF, 0xFC, 0xE3, 0xF1, 0xF8, 0xFC, 0x7E, 0x3F, 0x1C,
  0x1C, 0x70, 0x38, 0xE0, 0x71, 0xC0, 0xE3, 0x81, 0xC7, 0x03, 0x8E, 0x3F,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x38, 0xE0, 0x71, 0xC0, 0xE3, 0x8F, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x8E, 0x38, 0x1C, 0x70, 0x38, 0xE0, 0x71, 0xC0,
  0xE3, 0x81, 0xC7, 0x00, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x01, 0xFF, 0xF7,
  0xFF, 0xFF, 0xFF, 0xF8, 0xE0, 0x71, 0xC0, 0xE3, 0x81, 0xFF, 0xF1, 0xFF,
  0xF0, 0xFF, 0xE0, 0x38, 0xE0, 0x71, 0xC0, 0xE3, 0xFF, 0xFF, 0xFF, 0xFD,
  0xFF, 0xE0, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0xFC, 0x0F, 0xF8, 0x1F,
  0xF0, 0x3F, 0xE0, 0x7F, 0xC1, 0xFF, 0x87, 0xC0, 0x1F, 0x00, 0x7C, 0x01,
  0xF0, 0x07, 0xC0, 0x1F, 0x00, 0x7C, 0x01, 0xF0, 0x07, 0xC0, 0x1F, 0x00,
  0x7C, 0x3F, 0xF0, 0x7F, 0xC0, 0xFF, 0x81, 0xFF, 0x03, 0xFE, 0x07, 0xE0,
  0x3C, 0x00, 0xFE, 0x03, 0xFC, 0x07, 0x1C, 0x0E, 0x38, 0x1C, 0x70, 0x38,
  0xE0, 0x7B, 0xC0, 0xFF, 0x80, 0xFE, 0x00, 0xF8, 0x03, 0xF8, 0x0F, 0xF8,
  0xFE, 0xFB, 0xF8, 0xFF, 0xF0, 0xFE, 0xE0, 0xF9, 0xC3, 0xFB, 0xFF, 0xFB,
  0xFE, 0xF1, 0xF8, 0xE0, 0xFF, 0xFF, 0xC0, 0x3D, 0xFF, 0xF8, 0xE3, 0x8E,
  0x38, 0xE3, 0x8E, 0x38, 0xE3, 0x8E, 0x38, 0xE3, 0x8F, 0xDF, 0x1C, 0xF3,
  0xEF, 0x87, 0x1C, 0x71, 0xC7, 0x1C, 0x71, 0xC7, 0x1C, 0x71, 0xC7, 0x1C,
  0x7F, 0xFE, 0xE0, 0x1C, 0x70, 0x38, 0xE0, 0x7B, 0xC0, 0x77, 0x00, 0xFE,
  0x00, 0xF8, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x0F, 0x80, 0x3F, 0x80,
  0x77, 0x01, 0xEF, 0x03, 0x8E, 0x07, 0x1C, 0x00, 0x03, 0x80, 0x07, 0x00,
  0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFE, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0,
  0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBC, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x0E, 0x00, 0x1C, 0x00,
  0x38, 0x00, 0x70, 0x01, 0xE0, 0x07, 0xC0, 0x1F, 0x00, 0x7C, 0x01, 0xF0,
  0x07, 0xC0, 0x1F, 0x00, 0x7C, 0x01, 0xF0, 0x07, 0xC0, 0x1F, 0x00, 0x7C,
  0x00, 0xF0, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x00, 0x3F,
  0xF8, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC, 0x03, 0xF8, 0x0F,
  0xF0, 0x3F, 0xE0, 0xFF, 0xC7, 0xDF, 0x9F, 0x3F, 0x7C, 0x7F, 0xE0, 0xFF,
  0x81, 0xFE, 0x03, 0xF8, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFB, 0xFF,
  0xE1, 0xFF, 0x00, 0x1C, 0x1E, 0x1F, 0x1F, 0x8F, 0xC7, 0xE0, 0x70, 0x38,
  0x1C, 0x0E, 0x07, 0x03, 0x81, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x3F,
  0xFF, 0xFF, 0xF8, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00,
  0xFC, 0x01, 0xC0, 0x03, 0x80, 0x0F, 0x00, 0x3E, 0x00, 0xF8, 0x03, 0xE0,
  0x0F, 0x80, 0x3E, 0x00, 0xF8, 0x03, 0xE0, 0x0F, 0x80, 0x3E, 0x00, 0xF8,
  0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF,
  0xF7, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E,
  0x07, 0xFC, 0x0F, 0xF0, 0x1F, 0xE0, 0x00, 0xE0, 0x01, 0xC0, 0x03, 0xF0,
  0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFB, 0xFF, 0xE1, 0xFF, 0x00, 0x00,
  0x70, 0x00, 0xE0, 0x01, 0xC7, 0x03, 0x8E, 0x07, 0x1C, 0x0E, 0x38, 0x1C,
  0x70, 0x38, 0xE0, 0x71, 0xC0, 0xE3, 0x81, 0xC7, 0x03, 0x8F, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x80, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0, 0x03,
  0x80, 0x07, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0E, 0x00,
  0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xFF, 0xF3, 0xFF, 0xF7,
  0xFF, 0xE0, 0x00, 0xE0, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00,
  0x1F, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0x00, 0x1F, 0xF0, 0xFF, 0xE3, 0xFF,
  0xC7, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01,
  0xFF, 0xF3, 0xFF, 0xF7, 0xFF, 0xFE, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0,
  0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFB, 0xFF, 0xE1, 0xFF, 0x00, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0, 0x03,
  0x80, 0x0F, 0x00, 0x3E, 0x00, 0xF8, 0x03, 0xE0, 0x0F, 0x80, 0x3E, 0x00,
  0xF8, 0x03, 0xE0, 0x0F, 0x80, 0x3E, 0x00, 0xF8, 0x03, 0xE0, 0x07, 0x80,
  0x0E, 0x00, 0x00, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00,
  0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0E, 0xFF, 0xFD, 0xFF, 0xF7,
  0xFF, 0xEE, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0,
  0x1F, 0xFF, 0xFB, 0xFF, 0xE1, 0xFF, 0x00, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF,
  0xF7, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F,
  0xFF, 0xFD, 0xFF, 0xF9, 0xFF, 0xF0, 0x00, 0xE0, 0x01, 0xC0, 0x03, 0x80,
  0x07, 0x00, 0x0E, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0x00, 0xFF,
  0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
  0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xBC, 0xE0, 0x00, 0x70, 0x0F, 0x01, 0xF0, 0x3E, 0x07,
  0xC0, 0xF8, 0x1F, 0x03, 0xE0, 0x7C, 0x0F, 0x80, 0xF0, 0x0F, 0x80, 0x7C,
  0x03, 0xE0, 0x1F, 0x00, 0xF8, 0x07, 0xC0, 0x3E, 0x01, 0xF0, 0x0F, 0x00,
  0x70, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xE0, 0x0F, 0x00, 0xF8, 0x07, 0xC0,
  0x3E, 0x01, 0xF0, 0x0F, 0x80, 0x7C, 0x03, 0xE0, 0x1F, 0x00, 0xF0, 0x1F,
  0x03, 0xE0, 0x7C, 0x0F, 0x81, 0xF0, 0x3E, 0x07, 0xC0, 0xF8, 0x0F, 0x00,
  0xE0, 0x00, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC,
  0x01, 0xC0, 0x03, 0x80, 0x0F, 0x00, 0x3E, 0x00, 0xF8, 0x03, 0xE0, 0x0F,
  0x80, 0x3E, 0x00, 0x78, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF, 0xF7,
  0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x3F, 0xF0, 0xFF, 0xE3, 0xFF, 0xC7,
  0x1F, 0x8E, 0x3F, 0x1C, 0x7E, 0x3F, 0xFC, 0x3F, 0xB8, 0x1C, 0x70, 0x00,
  0xE0, 0x01, 0xC0, 0x03, 0xFF, 0xFB, 0xFF, 0xF1, 0xFF, 0xE0, 0x3F, 0xF8,
  0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0,
  0x07, 0xE0, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0xFC, 0x01,
  0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E,
  0x00, 0xE0, 0xFF, 0xF9, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC,
  0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF,
  0xEE, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F,
  0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0x00, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF, 0xF7,
  0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0,
  0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x07,
  0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFB, 0xFF, 0xE1, 0xFF, 0x00, 0xFF, 0xF9,
  0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0,
  0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFC, 0x01,
  0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFF, 0xFF, 0xEF,
  0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0E, 0x00, 0x1C,
  0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xFF, 0xE3, 0xFF, 0xC7, 0xFF,
  0x8E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0, 0x03,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xFF,
  0xE3, 0xFF, 0xC7, 0xFF, 0x8E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00,
  0xE0, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x00, 0x3F, 0xF8,
  0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x00, 0x70,
  0x00, 0xE0, 0x01, 0xC0, 0xFF, 0x81, 0xFF, 0x03, 0xFE, 0x00, 0xFC, 0x01,
  0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFB, 0xFF, 0xE1,
  0xFF, 0x00, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFC,
  0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFE, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F,
  0x80, 0x3F, 0x00, 0x7E, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xE3, 0x81, 0xC0,
  0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x81, 0xC0, 0xE0, 0x70, 0x38,
  0x1C, 0x0E, 0x3F, 0xFF, 0xFF, 0xF8, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38,
  0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00,
  0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0, 0x03, 0xF0, 0x07,
  0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFB, 0xFF, 0xE1, 0xFF, 0x00, 0xE0, 0x0F,
  0xC0, 0x3F, 0x80, 0xFF, 0x03, 0xEE, 0x0F, 0x9C, 0x3E, 0x38, 0xF8, 0x73,
  0xE0, 0xEF, 0x81, 0xFE, 0x03, 0xF8, 0x07, 0xF8, 0x0F, 0xF8, 0x1E, 0xF8,
  0x38, 0xF8, 0x70, 0xF8, 0xE0, 0xF9, 0xC0, 0xFB, 0x80, 0xFF, 0x00, 0xFE,
  0x00, 0xE0, 0xE0, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x1C,
  0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00,
  0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0, 0x03,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0x0F, 0xE0, 0x3F, 0xE0, 0xFF,
  0xE3, 0xFF, 0xEF, 0xFF, 0xFF, 0xFB, 0xFB, 0xF3, 0xE7, 0xE3, 0x8F, 0xC0,
  0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07,
  0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xE0, 0xE0, 0x0F,
  0xE0, 0x1F, 0xE0, 0x3F, 0xE0, 0x7F, 0xE0, 0xFF, 0xE1, 0xFB, 0xE3, 0xF3,
  0xE7, 0xE3, 0xEF, 0xC3, 0xFF, 0x83, 0xFF, 0x03, 0xFE, 0x03, 0xFC, 0x03,
  0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E,
  0x00, 0xE0, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC,
  0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00,
  0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F,
  0xFF, 0xFB, 0xFF, 0xE1, 0xFF, 0x00, 0xFF, 0xF9, 0xFF, 0xFB, 0xFF, 0xF7,
  0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xFF,
  0xFF, 0xFF, 0xF7, 0xFF, 0x8E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00,
  0xE0, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x00, 0x3F, 0xF8,
  0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0,
  0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x38, 0xFC, 0x7B,
  0xF8, 0xFF, 0xF0, 0xFE, 0xE0, 0xF9, 0xC3, 0xFB, 0xFF, 0xFB, 0xFE, 0xF1,
  0xF8, 0xE0, 0xFF, 0xF9, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC,
  0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF,
  0xEE, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F,
  0x80, 0x3F, 0x00, 0x7E, 0x00, 0xE0, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF, 0xF7,
  0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xFF,
  0xF1, 0xFF, 0xF1, 0xFF, 0xE0, 0x00, 0xE0, 0x01, 0xC0, 0x03, 0xF0, 0x07,
  0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFB, 0xFF, 0xE1, 0xFF, 0x80, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xF8, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01,
  0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70,
  0x00, 0xE0, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00,
  0x38, 0x00, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFC,
  0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00,
  0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F,
  0xFF, 0xFB, 0xFF, 0xE1, 0xFF, 0x00, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F,
  0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0,
  0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFE, 0x03, 0xFE, 0x0F, 0xBE, 0x3E,
  0x3E, 0xF8, 0x3F, 0xE0, 0x3F, 0x80, 0x3E, 0x00, 0x38, 0x00, 0xE0, 0x0F,
  0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0,
  0x07, 0xE0, 0x0F, 0xC7, 0x1F, 0x8E, 0x3F, 0x1C, 0x7E, 0x38, 0xFC, 0x71,
  0xF8, 0xE3, 0xF1, 0xC7, 0xE3, 0x8F, 0xC7, 0x1F, 0xFF, 0xFB, 0xFF, 0xE1,
  0xC7, 0x00, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7F, 0x01, 0xFF,
  0x07, 0xDF, 0x1F, 0x1F, 0x7C, 0x1F, 0xF0, 0x1F, 0xC0, 0x1F, 0x00, 0x7F,
  0x01, 0xFF, 0x07, 0xDF, 0x1F, 0x1F, 0x7C, 0x1F, 0xF0, 0x1F, 0xC0, 0x1F,
  0x80, 0x3F, 0x00, 0x7E, 0x00, 0xE0, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F,
  0x00, 0x7F, 0x01, 0xFF, 0x07, 0xDF, 0x1F, 0x1F, 0x7C, 0x1F, 0xF0, 0x1F,
  0xC0, 0x1F, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0,
  0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x70, 0x01, 0xE0, 0x07, 0xC0, 0x1F, 0x00,
  0x7C, 0x01, 0xF0, 0x07, 0xC0, 0x1F, 0x00, 0x7C, 0x01, 0xF0, 0x07, 0xC0,
  0x1F, 0x00, 0x7C, 0x00, 0xF0, 0x01, 0xC0, 0x03, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xE0, 0xFF, 0xFF, 0xF8, 0xE3, 0x8E, 0x38, 0xE3, 0x8E, 0x38, 0xE3,
  0x8E, 0x38, 0xE3, 0x8F, 0xFF, 0xFC, 0xE0, 0x01, 0xC0, 0x03, 0x80, 0x07,
  0x00, 0x0F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F,
  0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F,
  0x00, 0x1E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0xFF, 0xFF,
  0xC7, 0x1C, 0x71, 0xC7, 0x1C, 0x71, 0xC7, 0x1C, 0x71, 0xC7, 0x1C, 0x7F,
  0xFF, 0xFC, 0x03, 0x80, 0x0F, 0x80, 0x3F, 0x80, 0xFF, 0x83, 0xEF, 0x8F,
  0x8F, 0xBE, 0x0F, 0xF8, 0x0F, 0xE0, 0x0E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xF8, 0xE3, 0xCF, 0x9F, 0x3C, 0x70, 0x1F, 0xF8, 0x3F, 0xF8, 0x7F, 0xF0,
  0x00, 0x70, 0x00, 0xE0, 0x01, 0xCF, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xC0,
  0x1F, 0x80, 0x3F, 0x00, 0x7F, 0xFF, 0xEF, 0xFF, 0xC7, 0xFF, 0x80, 0xE0,
  0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x3F, 0xFE,
  0x7F, 0xFE, 0xFF, 0xFD, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFC,
  0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFF, 0xFF,
  0xEF, 0xFF, 0x00, 0x3F, 0xF8, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00,
  0xFC, 0x01, 0xF8, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0, 0x1F, 0x80, 0x3F,
  0x00, 0x7F, 0xFF, 0xEF, 0xFF, 0x87, 0xFC, 0x00, 0x00, 0x0E, 0x00, 0x1C,
  0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xCF, 0xFF, 0xBF, 0xFF, 0xFF,
  0xFF, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03,
  0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0xFF, 0xFB, 0xFF, 0xF1, 0xFF, 0xE0,
  0x3F, 0xF8, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0F, 0xFF,
  0x0F, 0xFE, 0x07, 0xFC, 0x00, 0x07, 0xF0, 0xFF, 0x1F, 0xF1, 0xC0, 0x1C,
  0x01, 0xC0, 0xFF, 0x8F, 0xF8, 0xFF, 0x81, 0xC0, 0x1C, 0x01, 0xC0, 0x1C,
  0x01, 0xC0, 0x1C, 0x01, 0xC0, 0x1C, 0x01, 0xC0, 0x1C, 0x01, 0xC0, 0x1C,
  0x00, 0x3F, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7E, 0x00, 0xFC, 0x01,
  0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xFF, 0xFD, 0xFF, 0xF8, 0xFF, 0xF0,
  0x00, 0xE0, 0x01, 0xC0, 0x03, 0x8F, 0xFF, 0x1F, 0xFC, 0x3F, 0xE0, 0xE0,
  0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x3F, 0xFE,
  0x7F, 0xFE, 0xFF, 0xFD, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFC,
  0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00,
  0x7E, 0x00, 0xE0, 0x1C, 0x0E, 0x07, 0x00, 0x00, 0x00, 0x03, 0xF1, 0xF8,
  0xFC, 0x0E, 0x07, 0x03, 0x81, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x3F,
  0xFF, 0xFF, 0xF8, 0x00, 0x70, 0x07, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00,
  0x03, 0xF0, 0x3F, 0x03, 0xF0, 0x07, 0x00, 0x70, 0x07, 0x00, 0x70, 0x07,
  0x00, 0x70, 0x07, 0x00, 0x70, 0x07, 0xE0, 0x7E, 0x07, 0xE0, 0x7F, 0xFF,
  0x7F, 0xE1, 0xF8, 0xE0, 0x0E, 0x00, 0xE0, 0x0E, 0x00, 0xE0, 0x0E, 0x00,
  0xE0, 0x7E, 0x0F, 0xE1, 0xFE, 0x3E, 0xE7, 0xCE, 0xF8, 0xFF, 0x0F, 0xE0,
  0xFF, 0x0F, 0xF8, 0xF7, 0xCE, 0x3E, 0xE1, 0xFE, 0x0F, 0xE0, 0x70, 0xFC,
  0x7E, 0x3F, 0x03, 0x81, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03,
  0x81, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x3F, 0xFF, 0xFF, 0xF8, 0xFE,
  0x79, 0xFF, 0xFB, 0xFF, 0xF7, 0x1C, 0x7E, 0x38, 0xFC, 0x71, 0xF8, 0xE3,
  0xF1, 0xC7, 0xE3, 0x8F, 0xC7, 0x1F, 0x8E, 0x3F, 0x1C, 0x7E, 0x38, 0xFC,
  0x71, 0xF8, 0xE3, 0x80, 0xFF, 0xF9, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E,
  0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0x80,
  0x3F, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0x80, 0x3F, 0xF8, 0xFF,
  0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07,
  0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7F, 0xFF, 0xEF, 0xFF, 0x87,
  0xFC, 0x00, 0xFF, 0xF9, 0xFF, 0xFB, 0xFF, 0xF7, 0x00, 0x7E, 0x00, 0xFC,
  0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF,
  0x8E, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x70, 0x00, 0xE0, 0x01, 0xC0, 0x00,
  0x3F, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8,
  0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xFF, 0xFD, 0xFF, 0xF8, 0xFF, 0xF0, 0x00,
  0xE0, 0x01, 0xC0, 0x03, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x1C, 0xFF, 0xCF,
  0xFE, 0xFF, 0xEE, 0x07, 0xE0, 0x7E, 0x07, 0xE0, 0x0E, 0x00, 0xE0, 0x0E,
  0x00, 0xE0, 0x0E, 0x00, 0xE0, 0x0E, 0x00, 0xE0, 0x00, 0x3F, 0xFE, 0xFF,
  0xFF, 0xFF, 0xFF, 0x00, 0x0E, 0x00, 0x1C, 0x00, 0x3F, 0xFE, 0x3F, 0xFE,
  0x1F, 0xFC, 0x00, 0x1C, 0x00, 0x38, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xBF,
  0xFC, 0x00, 0x1C, 0x01, 0xC0, 0x1C, 0x01, 0xC0, 0x1C, 0x01, 0xC0, 0xFF,
  0xFF, 0xFF, 0xFF, 0xF1, 0xC0, 0x1C, 0x01, 0xC0, 0x1C, 0x01, 0xC0, 0x1C,
  0x01, 0xC0, 0x1C, 0x01, 0xC0, 0x1F, 0xF0, 0xFF, 0x03, 0xF0, 0xE0, 0x0F,
  0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0,
  0x07, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7F, 0xFF, 0xEF, 0xFF,
  0xC7, 0xFF, 0x80, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F, 0x00, 0x7E, 0x00,
  0xFC, 0x01, 0xF8, 0x03, 0xF8, 0x0F, 0xF8, 0x3E, 0xF8, 0xF8, 0xFB, 0xE0,
  0xFF, 0x80, 0xFE, 0x00, 0xF8, 0x00, 0xE0, 0x00, 0xE0, 0x0F, 0xC0, 0x1F,
  0x80, 0x3F, 0x1C, 0x7E, 0x38, 0xFC, 0x71, 0xF8, 0xE3, 0xF1, 0xC7, 0xE3,
  0x8F, 0xC7, 0x1F, 0x8E, 0x3F, 0x1C, 0x7F, 0xFF, 0xEF, 0xFF, 0x87, 0x1C,
  0x00, 0xE0, 0x0F, 0xE0, 0x3F, 0xE0, 0xFB, 0xE3, 0xE3, 0xEF, 0x83, 0xFE,
  0x03, 0xF8, 0x03, 0xE0, 0x0F, 0xE0, 0x3F, 0xE0, 0xFB, 0xE3, 0xE3, 0xEF,
  0x83, 0xFE, 0x03, 0xF8, 0x03, 0x80, 0xE0, 0x0F, 0xC0, 0x1F, 0x80, 0x3F,
  0x00, 0x7E, 0x00, 0xFC, 0x01, 0xF8, 0x03, 0xF0, 0x07, 0xE0, 0x0F, 0xFF,
  0xFD, 0xFF, 0xF8, 0xFF, 0xF0, 0x00, 0xE0, 0x01, 0xC0, 0x03, 0x8F, 0xFF,
  0x1F, 0xFC, 0x3F, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x03, 0xE0,
  0x0F, 0x80, 0x3E, 0x00, 0xF8, 0x03, 0xE0, 0x0F, 0x80, 0x3E, 0x00, 0xF8,
  0x03, 0xE0, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x07, 0x87, 0xC7,
  0xE3, 0x81, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x7E, 0x3E, 0x1F, 0x01, 0xC0,
  0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0xE1, 0xF0, 0x38, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF0, 0x7C, 0x3E, 0x03, 0x81, 0xC0, 0xE0,
  0x70, 0x38, 0x1C, 0x0F, 0xC3, 0xE1, 0xF1, 0xC0, 0xE0, 0x70, 0x38, 0x1C,
  0x0E, 0x3F, 0x1F, 0x0E, 0x00, 0x1E, 0x00, 0xFE, 0x03, 0xFC, 0x07, 0x1C,
  0x7E, 0x38, 0xFC, 0x71, 0xC0, 0xFF, 0x80, 0xFE, 0x00, 0x70 };

const GFXglyph whitrabt16pt7bGlyphs[] PROGMEM = {
  {     0,   1,   1,  18,    0,    0 },   // 0x20 ' '
  {     1,   6,  21,  17,    4,  -20 },   // 0x21 '!'
  {    17,   9,   6,  17,    4,  -20 },   // 0x22 '"'
  {    24,  15,  21,  18,    1,  -20 },   // 0x23 '#'
  {    64,  15,  21,  18,    1,  -20 },   // 0x24 '$'
  {   104,  15,  21,  18,    1,  -20 },   // 0x25 '%'
  {   144,  15,  21,  18,    1,  -20 },   // 0x26 '&'
  {   184,   3,   6,  17,    7,  -20 },   // 0x27 '''
  {   187,   6,  21,  17,    7,  -20 },   // 0x28 '('
  {   203,   6,  21,  17,    4,  -20 },   // 0x29 ')'
  {   219,  15,  15,  18,    1,  -20 },   // 0x2A '*'
  {   248,  15,  15,  18,    1,  -17 },   // 0x2B '+'
  {   277,   6,   9,  17,    4,   -5 },   // 0x2C ','
  {   284,  15,   3,  18,    1,  -11 },   // 0x2D '-'
  {   290,   6,   6,  17,    4,   -5 },   // 0x2E '.'
  {   295,  15,  21,  18,    1,  -20 },   // 0x2F '/'
  {   335,  15,  21,  18,    1,  -20 },   // 0x30 '0'
  {   375,   9,  21,  18,    4,  -20 },   // 0x31 '1'
  {   399,  15,  21,  18,    1,  -20 },   // 0x32 '2'
  {   439,  15,  21,  18,    1,  -20 },   // 0x33 '3'
  {   479,  15,  21,  18,    1,  -20 },   // 0x34 '4'
  {   519,  15,  21,  18,    1,  -20 },   // 0x35 '5'
  {   559,  15,  21,  18,    1,  -20 },   // 0x36 '6'
  {   599,  15,  21,  18,    1,  -20 },   // 0x37 '7'
  {   639,  15,  21,  18,    1,  -20 },   // 0x38 '8'
  {   679,  15,  21,  18,    1,  -20 },   // 0x39 '9'
  {   719,   6,  18,  17,    4,  -17 },   // 0x3A ':'
  {   733,   6,  21,  17,    4,  -17 },   // 0x3B ';'
  {   749,  12,  21,  17,    1,  -20 },   // 0x3C '<'
  {   781,  15,   9,  18,    1,  -14 },   // 0x3D '='
  {   798,  12,  21,  18,    4,  -20 },   // 0x3E '>'
  {   830,  15,  21,  18,    1,  -20 },   // 0x3F '?'
  {   870,  15,  21,  18,    1,  -20 },   // 0x40 '@'
  {   910,  15,  21,  18,    1,  -20 },   // 0x41 'A'
  {   950,  15,  21,  18,    1,  -20 },   // 0x42 'B'
  {   990,  15,  21,  18,    1,  -20 },   // 0x43 'C'
  {  1030,  15,  21,  18,    1,  -20 },   // 0x44 'D'
  {  1070,  15,  21,  18,    1,  -20 },   // 0x45 'E'
  {  1110,  15,  21,  18,    1,  -20 },   // 0x46 'F'
  {  1150,  15,  21,  18,    1,  -20 },   // 0x47 'G'
  {  1190,  15,  21,  18,    1,  -20 },   // 0x48 'H'
  {  1230,   9,  21,  17,    4,  -20 },   // 0x49 'I'
  {  1254,  15,  21,  18,    1,  -20 },   // 0x4A 'J'
  {  1294,  15,  21,  18,    1,  -20 },   // 0x4B 'K'
  {  1334,  15,  21,  18,    1,  -20 },   // 0x4C 'L'
  {  1374,  15,  21,  18,    1,  -20 },   // 0x4D 'M'
  {  1414,  15,  21,  18,    1,  -20 },   // 0x4E 'N'
  {  1454,  15,  21,  18,    1,  -20 },   // 0x4F 'O'
  {  1494,  15,  21,  18,    1,  -20 },   // 0x50 'P'
  {  1534,  15,  21,  18,    1,  -20 },   // 0x51 'Q'
  {  1574,  15,  21,  18,    1,  -20 },   // 0x52 'R'
  {  1614,  15,  21,  18,    1,  -20 },   // 0x53 'S'
  {  1654,  15,  21,  18,    1,  -20 },   // 0x54 'T'
  {  1694,  15,  21,  18,    1,  -20 },   // 0x55 'U'
  {  1734,  15,  21,  18,    1,  -20 },   // 0x56 'V'
  {  1774,  15,  21,  18,    1,  -20 },   // 0x57 'W'
  {  1814,  15,  21,  18,    1,  -20 },   // 0x58 'X'
  {  1854,  15,  21,  18,    1,  -20 },   // 0x59 'Y'
  {  1894,  15,  21,  18,    1,  -20 },   // 0x5A 'Z'
  {  1934,   6,  21,  17,    7,  -20 },   // 0x5B '['
  {  1950,  15,  21,  18,    1,  -20 },   // 0x5C '\'
  {  1990,   6,  21,  17,    4,  -20 },   // 0x5D ']'
  {  2006,  15,   9,  18,    1,  -20 },   // 0x5E '^'
  {  2023,  15,   3,  18,    1,    1 },   // 0x5F '_'
  {  2029,   6,   6,  17,    7,  -20 },   // 0x60 '`'
  {  2034,  15,  15,  18,    1,  -14 },   // 0x61 'a'
  {  2063,  15,  21,  18,    1,  -20 },   // 0x62 'b'
  {  2103,  15,  15,  18,    1,  -14 },   // 0x63 'c'
  {  2132,  15,  21,  18,    1,  -20 },   // 0x64 'd'
  {  2172,  15,  15,  18,    1,  -14 },   // 0x65 'e'
  {  2201,  12,  21,  18,    4,  -20 },   // 0x66 'f'
  {  2233,  15,  18,  18,    1,  -14 },   // 0x67 'g'
  {  2267,  15,  21,  18,    1,  -20 },   // 0x68 'h'
  {  2307,   9,  21,  17,    4,  -20 },   // 0x69 'i'
  {  2331,  12,  24,  17,    1,  -20 },   // 0x6A 'j'
  {  2367,  12,  21,  18,    4,  -20 },   // 0x6B 'k'
  {  2399,   9,  21,  17,    4,  -20 },   // 0x6C 'l'
  {  2423,  15,  15,  18,    1,  -14 },   // 0x6D 'm'
  {  2452,  15,  15,  18,    1,  -14 },   // 0x6E 'n'
  {  2481,  15,  15,  18,    1,  -14 },   // 0x6F 'o'
  {  2510,  15,  18,  18,    1,  -14 },   // 0x70 'p'
  {  2544,  15,  18,  18,    1,  -14 },   // 0x71 'q'
  {  2578,  12,  15,  18,    4,  -14 },   // 0x72 'r'
  {  2601,  15,  15,  18,    1,  -14 },   // 0x73 's'
  {  2630,  12,  21,  18,    4,  -20 },   // 0x74 't'
  {  2662,  15,  15,  18,    1,  -14 },   // 0x75 'u'
  {  2691,  15,  15,  18,    1,  -14 },   // 0x76 'v'
  {  2720,  15,  15,  18,    1,  -14 },   // 0x77 'w'
  {  2749,  15,  15,  18,    1,  -14 },   // 0x78 'x'
  {  2778,  15,  18,  18,    1,  -14 },   // 0x79 'y'
  {  2812,  15,  15,  18,    1,  -14 },   // 0x7A 'z'
  {  2841,   9,  21,  17,    4,  -20 },   // 0x7B '{'
  {  2865,   3,  21,  17,    7,  -20 },   // 0x7C '|'
  {  2873,   9,  21,  17,    4,  -20 },   // 0x7D '}'
  {  2897,  15,   9,  18,    1,  -20 } }; // 0x7E '~'

const GFXfont whitrabt16pt7b PROGMEM = {
  (uint8_t  *)whitrabt16pt7bBitmaps,
  (GFXglyph *)whitrabt16pt7bGlyphs,
  0x20, 0x7E, 24 };

// Approx. 3586 bytes
