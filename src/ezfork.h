#ifndef _EZFORK_H_
#define _EZFORK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

int ezfork (
	int (*childcb)  (void *),        void *childcb_args,
	int (*parentcb) (pid_t, void *), void *parentcb_args)
__attribute__ ((nonnull (1, 3), warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _EZFORK_H_ */