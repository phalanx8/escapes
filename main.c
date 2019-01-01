#include <stdio.h>
#include <unistd.h>
#include <time.h>

/**
* tilda: x=31;y=33
*/

char *str_pos(const char *haystack, const char *needle)
{
	int i = 0;
	int n = 0;
	while(haystack[i] != '\0')
	{
		if(haystack[i] == needle[n])
		{
			n++;
			if(needle[n] == '\0')
			{
				return needle + n;
			}
		}
		i++;
	}
}

int print_battewry_stat()
{
	FILE *f = popen("acpiconf -i batt", "r");
	
	

	pclose(f);
	return 0;
}

int main()
{
  printf("\033[2J%s", " ");
	int i = 0;
	while(i < 33)
	{
		printf("\033[%d;1H%31s", i + 1, "");
		i++;
	}
	fflush(stdout);
	do
	{
		time_t curr_time = time(NULL);
		struct tm today = *localtime(&curr_time);
		
		printf("\033[1;1H%31s", " ");
		printf("\033[1;15H%02d.%02d.%d\033[41m \033[m%d:%02d:%02d", today.tm_mday, today.tm_mon + 1, today.tm_year + 1900, today.tm_hour, today.tm_min, today.tm_sec);
		fflush(stdout);
	}while(!sleep(1));
	return 0;
}
