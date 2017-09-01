#ifndef _EZFORK_H_
#define _EZFORK_H_

#include <sys/types.h>

int ezfork (
	int (*childcb)  (void *),        void *childcb_args,
	int (*parentcb) (pid_t, void *), void *parentcb_args) ;

#endif /* _EZFORK_H_ */