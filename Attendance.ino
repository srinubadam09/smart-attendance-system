#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MFRC522.h>

// RFID Module
#define SS_PIN 5
#define RST_PIN 4
MFRC522 rfid(SS_PIN, RST_PIN);

// OLED Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C  // Default I2C address for SSD1306
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Known card UIDs
byte card1_UID[] = {0x53, 0x6F, 0xF8, 0xF5};  
byte card2_UID[] = {0x7C, 0xC6, 0x48, 0x7C};

// Corresponding names
const char *name1 = "Srinu";  
const char *name2 = "Thejesh";    

void setup() {
    Serial.begin(115200);
    SPI.begin();
    rfid.PCD_Init();

    // Initialize OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 10);
    display.println("Place your RFID card...");
    display.display();

    Serial.println("Place your RFID card...");
}

void loop() {
    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
        return;
    }

    Serial.print("Tag UID: ");
    for (byte i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i], HEX);
        Serial.print(" ");
    }

    const char *recognizedName = NULL;
    if (compareUID(rfid.uid.uidByte, rfid.uid.size, card1_UID, sizeof(card1_UID))) {
        recognizedName = name1;
    } else if (compareUID(rfid.uid.uidByte, rfid.uid.size, card2_UID, sizeof(card2_UID))) {
        recognizedName = name2;
    }

    if (recognizedName) {
        Serial.print(" - Recognized: ");
        Serial.println(recognizedName);
        showOLEDMessage(recognizedName);
    } else {
        Serial.println(" - Unknown Card");
        showOLEDMessage("Unknown Card");
    }

    rfid.PICC_HaltA();
}

// Function to compare UIDs
bool compareUID(byte scannedUID[], byte scannedSize, byte storedUID[], byte storedSize) {
    if (scannedSize != storedSize) return false;
    for (byte i = 0; i < scannedSize; i++) {
        if (scannedUID[i] != storedUID[i]) {
            return false;
        }
    }
    return true;
}

// Function to display message on OLED
void showOLEDMessage(const char *message) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(10, 20);
    display.println(message);
    display.display();
}
