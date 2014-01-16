/* 
 * Public Domain getopt header
 *
 * $Id: rdfproc_getopt.h,v 1.1.1.1 2005/07/06 09:38:37 gully Exp $
 *
 */

#ifndef RDFPROC_GETOPT_H
#define RDFPROC_GETOPT_H

int getopt(int argc, char * const argv[], const char *optstring);
extern char *optarg;
extern int optind, opterr, optopt;

#endif
