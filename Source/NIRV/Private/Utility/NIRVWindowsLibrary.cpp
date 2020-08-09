// Copyright 2020 NIRV Team LLC. All Rights Reserved.
//
#include "Utility/NIRVWindowsLibrary.h"

#include <Windows/AllowWindowsPlatformTypes.h>
#include <Windows/PreWindowsApi.h>
#include <Windows/MinWindows.h>
#include <Windows/PostWindowsApi.h>
#include <Windows/HideWindowsPlatformTypes.h>


bool UNIRVWindowsLibrary::SetCapsLockState(const bool bInState = false)
{
	static BYTE KeyState[256];
	
	GetKeyboardState((LPBYTE)&KeyState);

	if ((bInState && !(KeyState[VK_CAPITAL] & 1)) || (!bInState && (KeyState[VK_CAPITAL] & 1)))
	{
		keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
		keybd_event(VK_CAPITAL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	}

	return bInState && (KeyState[VK_CAPITAL] & 1);
}

bool UNIRVWindowsLibrary::IsCapsLockEnabled()
{
	static BYTE KeyState[256];
	GetKeyboardState(KeyState);

	return KeyState[VK_CAPITAL] ? true : false;
}
