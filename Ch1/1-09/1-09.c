#include <stdio.h>
#include <windows.h>

#define FALSE 0
#define TRUE 1

/**
 * GetCh courtesy of user 'unoriginal' from http://www.cplusplus.com/forum/articles/19975/
 * 			due to getchar() unable to process 1 character at a time, and conio.h's getch()
 * 			not working and crashing.
 */
CHAR GetCh (VOID)
{
  HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
  INPUT_RECORD irInputRecord;
  DWORD dwEventsRead;
  CHAR cChar;

  while(ReadConsoleInputA (hStdin, &irInputRecord, 1, &dwEventsRead)) /* Read key press */
    if (irInputRecord.EventType == KEY_EVENT
	&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_SHIFT
	&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_MENU
	&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_CONTROL)
    {
      cChar = irInputRecord.Event.KeyEvent.uChar.AsciiChar;
	ReadConsoleInputA (hStdin, &irInputRecord , 1, &dwEventsRead); /* Read key release */
	return cChar;
    }
  return EOF;
}

int main() {
	int c, flag_oneOrMoreSpace;
	c = flag_oneOrMoreSpace = 0;
	while ((c=GetCh()) != EOF) {
		if (c == ' ') {
			if (flag_oneOrMoreSpace == FALSE) {
				printf("%c", c);
				flag_oneOrMoreSpace = TRUE;
			}
		}
		else {
			printf("%c", c);
			if (flag_oneOrMoreSpace == TRUE) {
				flag_oneOrMoreSpace = FALSE;
			}
		}
	}
	return 0;
}
