/*
   mutex.h

   Header for a Pthread condition variable class in C++.

   ------------------------------------------

   Copyright (c) 2013 Vic Hargrave

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef __condvar_h__
#define __condvar_h__

#include "mutex.h"

class CondVar
{
    pthread_cond_t  m_cond;
    Mutex&          m_lock;

  public:
    // just initialize to defaults
  CondVar(Mutex& mutex) : m_lock(mutex) { pthread_cond_init(&m_cond, NULL); }
    virtual ~CondVar() { pthread_cond_destroy(&m_cond); }

    int wait() { return  pthread_cond_wait(&m_cond, &(m_lock.m_mutex)); }
    int signal() { return pthread_cond_signal(&m_cond); } 
    int broadcast() { return pthread_cond_broadcast(&m_cond); } 

  private:
    CondVar();
};

#endif
