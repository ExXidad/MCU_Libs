//
// Created by Ivan Kalesnikau on 29.12.2022.
//

#ifndef LT_PD_TIMER_HPP
#define LT_PD_TIMER_HPP

#include "tim.h"
#include <Utils/Types.hpp>
#include <cstdio>
#include <cmath>

struct Timer
{
    TIM_HandleTypeDef *timer_ = nullptr;
    uint32_t channel_ = 0u;
    uint32_t FCLK_ = 0u, ARR_ = 0u, CCR_ = 0u, PSC_ = 0u;
    scalar updateFrequency_ = 0;

    void updateTimerInfo(const bool print = false) ;
    volatile uint32_t *timChannelToCCR(TIM_HandleTypeDef *tim, const uint32_t timChannel) ;

    Timer() = default;
    Timer(TIM_HandleTypeDef *timer, const uint32_t timerChannel);
    Timer(TIM_HandleTypeDef *timer);
    void startTimer() ;
    void stopTimer() ;
    void startPWM() ;
    void stopPWM() ;
    void writePWM(const uint32_t pwmFreq, const scalar dutyCycle) ;
    void writePWMDuty(const scalar duty) ;
    void writePWMDuty(const uint32_t duty) ;
    void setPeriod(const uint32_t arr, const uint32_t psc) ;
    scalar updateFrequency() const;
};

bool operator==(const  Timer &timerClass, const TIM_HandleTypeDef *timer);
bool operator==(const TIM_HandleTypeDef *timer, const  Timer &timerClass);

#endif //LT_PD_TIMER_HPP
