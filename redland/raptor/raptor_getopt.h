/* 
 * Public Domain getopt header
 *
 * $Id: raptor_getopt.h,v 1.1.1.1 2005/07/06 09:38:37 gully Exp $
 *
 */

#ifndef RAPTOR_GETOPT_H
#define RAPTOR_GETOPT_H

#ifdef __cplusplus
extern "C" {
#endif

int getopt(int argc, char * const argv[], const char *optstring);
extern char *optarg;
extern int optind, opterr, optopt;

#ifdef __cplusplus
}
#endif

#endif
