#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdarg.h>

FILE *log_open()
{
    FILE *logfile;

    // very first thing, open up the logfile and mark that we got in
    // here.  If we can't open the logfile, we're dead.
    logfile = fopen(LOGFILE, "w");
    if (logfile == NULL) {
	perror("logfile");
	exit(EXIT_FAILURE);
    }

    // set logfile to line buffering
    setvbuf(logfile, NULL, _IOLBF, 0);

    return logfile;
}

void log_msg(const char *format, ...)
{
      va_list ap;
      va_start(ap, format);

      vfprintf(TB_DATA->logfile, format, ap);
}
