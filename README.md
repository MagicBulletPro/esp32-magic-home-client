# ESP32 Magic Home Client

Firmware for controlling Magic Home-compatible relays with an ESP32. Configure Wi-Fi credentials, API token, device metadata, and relay pins in `src/main.cpp`.

This firmware supports the Magic Home app on both Android and iOS:

- Apple App Store: https://apps.apple.com/in/app/magic-home-control-center/id6749792196
- Google Play Store: https://play.google.com/store/apps/details?id=com.linoop.magichome

## Features

- Wi-Fi provisioning with backend authentication token
- Configurable device metadata (ID, name, description)
- Relay control for multiple channels and home accessories over the internet
- Optional DHT11/DHT22 sensor support

## Requirements

- PlatformIO
- ESP32 board
- Magic Home app (API token required)

## Setup

1. Open `src/main.cpp` and replace placeholders:
   - `YOUR_WIFI_SSID`, `YOUR_WIFI_PASSWORD`
   - `YOUR_AUTH_TOKEN` (Magic Home app: Settings -> API Key)
   - `esp32_device_id` (must be unique per device)
2. Update relay pins and labels in the `relays` array.
3. Adjust `statusLedPin`, `dhtPin`, and `dhtType` as needed (use `dhtType = 11` for DHT11 or `22` for DHT22).

## Build

Use PlatformIO tasks or run:

- `platformio run`

## Upload

- `platformio run --target upload`

## License

MIT License. See `LICENSE`.
