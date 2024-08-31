#!/bin/bash

# script for automating signing and notarization tasks on macos

# Paths
APP_PATH="build/Pong.app"
ZIP_PATH="build/Pong.zip"
SIGN_CERT="Developer ID Application: Michael Long (KGC3GK695M)"
ENTITLEMENTS="build/macos.entitlements"

echo "Signing bundle contents..."
find "$APP_PATH" -type f -exec codesign --entitlements "$ENTITLEMENTS" --deep --force --timestamp --strict --options runtime --sign "$SIGN_CERT" {} \;

echo "Signing the app bundle..."
codesign --entitlements "$ENTITLEMENTS" --deep --strict --force --options runtime --timestamp --sign "$SIGN_CERT" "$APP_PATH"

echo "Creating zip file"
zip -r "$ZIP_PATH" "$APP_PATH"

echo "Notarizing..."
xcrun notarytool submit "$ZIP_PATH" --apple-id "$MY_APPLE_ID" --password "$MY_APP_SPECIFIC_PASSWORD" --team-id "$T_ID" --wait

#echo "Stapling..."
xcrun stapler staple "$APP_PATH"

rm "$ZIP_PATH"
cd build && zip -r Pong.zip Pong.app

echo "App signed, packaged, notarized, and ticket stapled."
