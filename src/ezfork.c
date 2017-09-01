#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "ezfork.h"

#define CHILD_CASE case 0
#define PARENT_CASE default
#define ERROR_CASE case -1

int ezfork (
	int (*childcb)  (void *),        void *childcb_args,
	int (*parentcb) (pid_t, void *), void *parentcb_args) {
	pid_t pid;
	
	pid = fork ();
	switch (pid) {
    ERROR_CASE: return -1;
	CHILD_CASE:
	   if (childcb (childcb_args) != 0)
	      return EXIT_FAILURE;
	   return EXIT_SUCCESS;
	PARENT_CASE:
	   if (parentcb (pid, parentcb_args) != 0)
		   return -3;
	   return 0;
   }
   /* unreachable () */
}

#undef CHILD_CASE
#undef PARENT_CASE
#undef ERROR_CASE