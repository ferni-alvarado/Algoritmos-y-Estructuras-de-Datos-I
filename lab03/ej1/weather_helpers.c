#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "weather.h"
#include "array_helpers.h"

int menor_temperatura(WeatherTable array){
    int t;
    t = array[0][0][0]._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (array[year][month][day]._min_temp < t){
                    t = array[year][month][day]._min_temp;
                }  

            }
        }
    }
    return t;
}

void procedimiento(WeatherTable a, int output[YEARS]) {
    int t;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        t = a[year][0][0]._max_temp;
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (a[year][month][day]._max_temp > t){
                    t = a[year][month][day]._max_temp;
                }
            }
        }
        output[year] = t;
    }
}

void procedimiento2(WeatherTable a, int output[YEARS]) {
    int t;
    int c;
    for (unsigned int year = 0u; year < YEARS; ++year){
        c = 0;
        for (month_t month = january; month <= december; ++month) {
            if (t>c){
                c = t;
                output[year] = month;
            }            
            t = 0;
            for (unsigned int day = 0u; day < DAYS; ++day){
                t = t + a[year][month][day]._rainfall;
            }
        }
    }
}
