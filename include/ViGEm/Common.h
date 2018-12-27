/*
MIT License

Copyright (c) 2017 Benjamin "Nefarius" Höglinger

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#pragma once

//
// Represents the desired target type for the emulated device.
//  
typedef enum _VIGEM_TARGET_TYPE
{
    // 
    // Microsoft Xbox 360 Controller (wired)
    // 
    Xbox360Wired,
    // 
    // Microsoft Xbox One Controller (wired)
    // 
    XboxOneWired,
    //
    // Nintendo Switch (wired)
    // 
    NintendoSwitchWired

} VIGEM_TARGET_TYPE, *PVIGEM_TARGET_TYPE;

//
// Possible XUSB report buttons.
// 
typedef enum _XUSB_BUTTON
{
    XUSB_GAMEPAD_DPAD_UP            = 0x0001,
    XUSB_GAMEPAD_DPAD_DOWN          = 0x0002,
    XUSB_GAMEPAD_DPAD_LEFT          = 0x0004,
    XUSB_GAMEPAD_DPAD_RIGHT         = 0x0008,
    XUSB_GAMEPAD_START              = 0x0010,
    XUSB_GAMEPAD_BACK               = 0x0020,
    XUSB_GAMEPAD_LEFT_THUMB         = 0x0040,
    XUSB_GAMEPAD_RIGHT_THUMB        = 0x0080,
    XUSB_GAMEPAD_LEFT_SHOULDER      = 0x0100,
    XUSB_GAMEPAD_RIGHT_SHOULDER     = 0x0200,
    XUSB_GAMEPAD_GUIDE              = 0x0400,
    XUSB_GAMEPAD_A                  = 0x1000,
    XUSB_GAMEPAD_B                  = 0x2000,
    XUSB_GAMEPAD_X                  = 0x4000,
    XUSB_GAMEPAD_Y                  = 0x8000

} XUSB_BUTTON, *PXUSB_BUTTON;

//
// Represents an XINPUT_GAMEPAD-compatible report structure.
// 
typedef struct _XUSB_REPORT
{
    USHORT wButtons;
    BYTE bLeftTrigger;
    BYTE bRightTrigger;
    SHORT sThumbLX;
    SHORT sThumbLY;
    SHORT sThumbRX;
    SHORT sThumbRY;

} XUSB_REPORT, *PXUSB_REPORT;

//
// Initializes a _XUSB_REPORT structure.
// 
VOID FORCEINLINE XUSB_REPORT_INIT(
    _Out_ PXUSB_REPORT Report
)
{
    RtlZeroMemory(Report, sizeof(XUSB_REPORT));
}

//
// Nintendo Switch HID Input report
// 
typedef struct _NSWITCH_REPORT
{
	UCHAR TimerStatus;
	UCHAR Report[64];

} NSWITCH_REPORT, *PNSWITCH_REPORT;

