#include <Arduino.h>
#include "MagicHomeClient.h"

// Wi-Fi credentials
const char *ssid = "YOUR_WIFI_SSID";
const char *password = "YOUR_WIFI_PASSWORD";

// API token from the Magic Home app (Settings -> API Key)
const char *authToken = "YOUR_AUTH_TOKEN";

// Device metadata shown in the backend UI
const char *deviceId = "esp32_device_id"; // Must be unique per device (use different IDs for multiple devices)
const char *deviceName = "Device Name";
const char *deviceDescription = "Device Description";

// Hardware configuration
const uint8_t statusLedPin = 2; // On-board status LED (adjust per board)
const int dhtPin = 4;           // GPIO for DHT sensor data
const int dhtType = 11;         // Use 0 to disable, 11 for DHT11, 22 for DHT22

// Relay list: {pin, name, description, initialState}
RelayConfig relays[] = {
    {18, "Relay 1", "First relay description", false},
    {19, "Relay 2", "Second relay description", false},
    {27, "Relay 3", "Third relay description", false},
};

MagicHomeConfig config = {
    ssid,
    password,
    authToken,
    deviceId,
    deviceName,
    deviceDescription,
    statusLedPin,
    dhtPin,
    dhtType,
    relays,
    sizeof(relays) / sizeof(relays[0]),
};

// Client instance
MagicHomeClient client(config);

void setup()
{
    // Initialize Wi-Fi and Magic Home client
    client.begin();
}

void loop()
{
    // Keep the client responsive
    client.loop();
}