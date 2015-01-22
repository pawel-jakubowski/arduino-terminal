/*
 * Lock.cpp
 *
 *  Created on: 17 sty 2015
 *      Author: Pawel Jakubowski
 */

#include "MutexLock.h"

#include <iostream>

MutexLock::MutexLock() :
		locked(false), error(0) {
	pthread_mutex_init(&m, NULL);
}

bool MutexLock::tryToLock() {
	if(pthread_mutex_trylock(&m) == 0) {
		locked = true;
		return true;
	}
	return false;
}

void MutexLock::lock() {
	while(tryToLock()) {}
//	error = pthread_mutex_lock(&m);
//	locked = (error == 0);
}

void MutexLock::unlock() {
	if (locked) {
		pthread_mutex_unlock(&m);
		locked = false;
	}
}

MutexLock::~MutexLock() {
	unlock();
	pthread_mutex_destroy(&m);
}

bool MutexLock::isLocked() {
	return locked;
}

