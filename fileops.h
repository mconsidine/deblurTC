/*
 *  Header for file operations module
 */

#ifndef _KISIP_FILEOPS_H
#define _KISIP_FILEOPS_H

#include "speckle_admin.h"

int readims(char **filenames, maininfo* info, float *data);
int savefloat(char filename[], long size, maininfo info, float *data);

#ifdef EMAN2
	int getsize(maininfo* info, char *filename);
#endif

#endif	/* _KISIP_FILEOPS_H */

