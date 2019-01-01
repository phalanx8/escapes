#include <stdio.h>
#include <time.h>

int main()
{
	printf("\033[s"); // save cursor position (die erste Zeile und spalte unter der Prompt speichern.)
	int i = 0;
	while(1) 
	{
		printf("\033[u%d  %d", i, (9-i)); // u geht zurueck zu der gespeicherten Zeile
		fflush(stdout); // man muss den output buffer leeren  ¯\_(ツ)_/¯ sonst kaputt
		sleep(1);
		i = (i >= 9) ? 0: i+1;
	}
	return 0;
}
