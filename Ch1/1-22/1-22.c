/**
 * 1-22		write program to fold any lines at the nth column. Do something 'smart' with long lines
 * notables		no tabs (tabs just requires additional previous code)
 * 				store word in array
 */

#include <stdio.h>
#include <windows.h>
#define SOFTLINEEND 30
#define HARDLINEEND 60
#define TRUE 1
#define FALSE 0

/**
 * GetCh courtesy of user 'unoriginal' from http://www.cplusplus.com/forum/articles/19975/
 * 			due to getchar() unable to process 1 character at a time, and conio.h's getch()
 * 			not working and crashing.
 *	RUN .EXE, NOT IDE CONSOLE
 * 	TYPE SLOWLY!
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

int main(void) {
	int c = 0;
	int posCounter = 0;
	while ((c = GetCh()) != EOF) {
		if (c == '\n') {
			printf("%d\n", posCounter);
			posCounter = 0;
		} else {
			if (posCounter > SOFTLINEEND) {
				if (c == ' ') {
					printf(" %d\n", posCounter);
					posCounter = 0;
				} else if (posCounter > HARDLINEEND) {
					printf("-%d\n", posCounter);
					posCounter = 0;
					printf("%c", c);
					posCounter++; //redundant two lines, but visually to see a reset and first character.
				} else {
					printf("%c", c);
					posCounter++;
				}
			} else {
				printf("%c", c);
				posCounter++;
			}
		}
		fflush(stdout);
	}
	return 0;
}

