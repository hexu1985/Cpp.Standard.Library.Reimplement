// -*- C++ -*-
// HeXu's
// 2013 Jun

#ifndef MINI_STL_RECURSIVE_MUTEX_INC
#define MINI_STL_RECURSIVE_MUTEX_INC

#include <pthread.h>

namespace mini_stl {

/**
 * The recursive_mutex class is a synchronization primitive 
 * that can be used to protect shared data from being simultaneously 
 * accessed by multiple threads. 
 * recursive_mutex offers exclusive, recursive ownership semantics.
 */
class recursive_mutex {
    pthread_mutex_t mtx_;        // native mutex handle

public:
    typedef pthread_mutex_t* native_handle_type;

	/**
	 * Constructs the mutex. 
	 * The mutex is in unlocked state after the call. 
	 */
	explicit recursive_mutex(); 

    /** Destroys the mutex. */
    ~recursive_mutex();

    recursive_mutex(const recursive_mutex&) = delete;
    recursive_mutex& operator=(const recursive_mutex&) = delete;

	/**
	 * Locks the mutex. 
	 * If another thread has already locked the mutex, a call to lock will 
	 * block execution until the lock is acquired. If lock is called by a 
	 * thread that already owns the mutex, the program may deadlock. 
	 */
	void lock();
	
	/**
	 * Tries to lock the mutex. Returns immediately. 
	 * On successful lock acquisition returns true, otherwise returns false.
	 * The behavior is undefined if the mutex is not unlocked 
	 * before being destroyed, i.e. some thread still owns it. 
	 */
	bool try_lock();

	/**
	 * Unlocks the mutex.
	 * The mutex must be unlocked by all threads that have successfully locked 
	 * it before being destroyed. Otherwise, the behavior is undefined. 
	 */
	void unlock();

	/** 
	 * Returns the underlying implementation-defined native handle object. 
	 */
	native_handle_type native_handle() { return &mtx_; }
};

}	// namespace mini_stl

#endif

