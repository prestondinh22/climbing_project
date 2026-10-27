#include "Attempt.h"
#include <chrono>
#include <vector>

#pragma once 

class ClimbingSession { 
    private: 

    std::vector<Attempt> attempts{}; 
    bool session_active{}; // true or false depending on session status
    bool attempt_running{}; // true or false depending on attempt status
    bool session_closed{};
    double session_duration_s{}; // will be equal to session_end_time snapshot - session_start_time
    std::chrono::time_point<std::chrono::steady_clock> attempt_start_time; // snapshot of start_time, used to calculate attempt duration when stopAttempt is called
    std::chrono::time_point<std::chrono::steady_clock> session_start_time; // session start time should never change per object.
    

    public:

    void startAttempt(); 
    void stopAttempt();
    void startSession();
    void stopSession();
    const Attempt& viewAttempt(int index) const;

};
