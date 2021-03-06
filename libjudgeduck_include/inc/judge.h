#ifndef JOS_INC_JUDGE_H
#define JOS_INC_JUDGE_H

#include <inc/syscall.h>
#include <inc/trap.h>

struct JudgeParams
{
	uint64_t ns;
	int kb;
	int syscall_enabled[NSYSCALLS];
	void *data_begin;
	#ifndef JD_OLD_MEMORY_LIMIT
	void *esp;
	#endif
	bool defrag_mem;
};

enum JudgeVerdict
{
	VERDICT_OK,
	VERDICT_TLE, // Time Limit Exceeded
	VERDICT_RE,  // Runtime Error
	VERDICT_IS,  // Illegal Syscall
	VERDICT_SE,  // System Error
	#ifndef JD_OLD_MEMORY_LIMIT
	VERDICT_MLE, // Memory Limit Exceeded
	#endif
};

struct JudgeResult
{
	enum JudgeVerdict verdict;
	uint64_t time_cycles;
	uint64_t time_ns;
	int mem_kb; // to be implemented
	struct Trapframe tf;
};

#endif
