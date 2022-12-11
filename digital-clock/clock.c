#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int h = 0;
	int m = 0;
	int s = 0;

	/* delay in seconds */
	int delay_s = 1;

	switch (argc)
	{
		case 4: s = atoi(argv[3]);
		case 3: m = atoi(argv[2]);
		case 2: h = atoi(argv[1]);
			break;
		default:
			printf("USAGE:\n%s [hours] [minutes] [seconds]\n", argv[0]);
			printf("If left empty, the values will default to 0");
			exit(-1);
			break;
	}


	if (h > 24 || m > 60 || s > 60)
	{
		printf("Invalid values!\n");
		exit(-1);
	}

	while (1)
	{
		if (h == 24) { h = 0; }
		if (m == 60) { m = 0; h++; }
		if (s == 60) { s = 0; m++; }

		printf("\nClock: %02d:%02d:%02d", h, m, s);
		sleep(delay_s);
		system("clear");

		s++;
	}

	return 0;

}
