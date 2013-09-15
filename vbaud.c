#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	unsigned long speed;
	if (argc !=2 || (speed = atol(argv[1])) == 0 || speed > 38400) {
		fprintf(stderr, "Usage: %s <bit rate>\n"
			"\t %s rate limits the output speed to the speed over\n"
			"\t a serial line rated at <bit rate>.\n\n"
			"Example:\n"
			"\t %% gzip -dc globe.vt.gz | ./%s 9600\n"
			"\t Shows a slowly rotating globe in your terminal window.\n"
			"\t VT100 animation files can e.g. be found at\n"
			"\t https://ftp.nice.ch/NiCE/vt100.anims/\n",
			argv[0], argv[0], argv[0]);
		exit(1);
		/* This bit rate is frequently talso specified as the <baud rate>
		 * (e.g. "9600 baud"), even though that 1:1 matching is only true
		 * for real serial lines, and not e.g. for modems.
		 */
	}
	/* Assume 10 bits (1 start+8 data+0 parity+1 stop) per char */
	unsigned long wait = 10000000L / speed;
	int ch;
	/* Turn of line buffering */
	setvbuf(stdout, NULL, 0, _IONBF);
	while ((ch = getchar()) != EOF) {
		putchar(ch);
		usleep(wait);
	}
	return 0;
}
