/*
 * Lock.cpp
 *
 *  Created on: 17 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "MutexLock.h"

MutexLock::MutexLock() :
		locked(false), error(0) {
	pthread_mutex_init(&m, NULL);
}

void MutexLock::lock() {
	error = pthread_mutex_lock(&m);
	locked = (error == 0);
}

void MutexLock::unlock() {
	if (locked)
		pthread_mutex_unlock(&m);
}

MutexLock::~MutexLock() {
	unlock();
	pthread_mutex_destroy(&m);
}

bool MutexLock::is_locked() {
	return locked;
}

