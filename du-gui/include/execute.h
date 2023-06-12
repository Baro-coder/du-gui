#ifndef H_EXECUTE
#define H_EXECUTE

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DEFINITIONS */

#define FLAGS_BUFFER_SIZE 128
#define CMD_BUFFER_SIZE 256
#define OUT_BUFFER_SIZE 512

#define FLAG_INCF "-a"
#define FLAG_STSZ "-c"
#define FLAG_FOLL "-L"
#define FLAG_COUH "-l"
#define FLAG_SEPD "-S"
#define FLAG_SOFS "-x"

#define BLOCK_SIZE_DEF "-h"
#define BLOCK_SIZE_BYT "-b"
#define BLOCK_SIZE_KIB "-BK"
#define BLOCK_SIZE_MIB "-BM"
#define BLOCK_SIZE_GIB "-BG"

#define EXCL_PATTERN_NONE ""
#define EXCL_PATTERN_C "{*.c,*.h,*.cpp,*.hpp}"
#define EXCL_PATTERN_PY "*.py"
#define EXCL_PATTERN_SH "*.sh"

/* FUNCTIONS */
FILE *execute_cmd(char *flags);

/* DECLARATIONS */


#endif