/*
 * @Author: Divin Raj
 * @Date: 07-01-2024
 * @File: writer.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		syslog(LOG_ERR, "Error: Two arguments are required.");
		exit(1);
	}

	char *writefile = argv[1];
	char *writestr = argv[2];

	if (writefile == NULL || writestr == NULL) {
		syslog(LOG_ERR, "Error: Both arguments must be specified.");
		exit(1);
	}

	openlog(argv[0], LOG_PID, LOG_USER);

	FILE *file = fopen(writefile, "w");

	if (file == NULL) {
		syslog(LOG_ERR, "Error: Failed to create the file %s.", writefile);
		exit(1);
	}

	if (fprintf(file, "%s\n", writestr) < 0) {
		syslog(LOG_ERR, "Error: Failed to write to the file %s.", writefile);
		fclose(file);
		exit(1);
	}

	fclose(file);

	syslog(LOG_INFO, "%s created successfully with content: %s", writefile, writestr);

	closelog();

	return 0;
}

