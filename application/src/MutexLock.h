/*
 * MutexLock.h
 *
 *  Created on: 17 sty 2015
 *      Author: Pawel Jakubowski
 */

#ifndef MUTEXLOCK_H_
#define MUTEXLOCK_H_

#include <pthread.h>

class MutexLock {
public:
	bool is_locked();
	void lock();
	void unlock();

	explicit MutexLock();
	virtual ~MutexLock();
private:
	pthread_mutex_t m;
	bool locked;
	int error;

	MutexLock(MutexLock&);
	MutexLock& operator=(MutexLock&);
};

#endif /* MUTEXLOCK_H_ */
