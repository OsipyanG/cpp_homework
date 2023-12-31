#include <iostream>

class Date {
   public:
    Date(int day, int month, int year) {
        if (isValidDate(day, month, year)) {
            int daysSinceEpoch = getDaysSinceEpoch(day, month, year);
            daysSinceEpoch_ = daysSinceEpoch;
        } else {
            daysSinceEpoch_ = 0;
        }
    }

    int GetDay() const {
        int days = daysSinceEpoch_;
        int year = 1970;
        int month = 1;
        int day = days + 1;
        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return day;
    }

    int GetMonth() const {
        int days = daysSinceEpoch_;
        int year = 1970;
        int month = 1;
        int day = days + 1;
        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return month;
    }

    int GetYear() const {
        int days = daysSinceEpoch_;
        int year = 1970;
        int month = 1;
        int day = days + 1;
        while (day > daysInMonth(month, year)) {
            day -= daysInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return year;
    }

    Date operator+(int days) const {
        int newDaysSinceEpoch = daysSinceEpoch_ + days;
        Date date(1, 1, 1970);  // Assuming the epoch is 1st January 1970
        date.daysSinceEpoch_ = newDaysSinceEpoch;
        return date;
    }

    Date operator-(int days) const {
        int newDaysSinceEpoch = daysSinceEpoch_ - days;
        Date date(1, 1, 1970);  // Assuming the epoch is 1st January 1970
        date.daysSinceEpoch_ = newDaysSinceEpoch;
        return date;
    }

    int operator-(const Date& other) const {
        int days1 = daysSinceEpoch_;
        int days2 = other.daysSinceEpoch_;
        return days1 - days2;
    }

   private:
    int daysSinceEpoch_;

    bool isValidDate(int day, int month, int year) {
        if (year < 1970 || year > 2099) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > daysInMonth(month, year)) return false;
        return true;
    }

    int daysInMonth(int month, int year) const {
        static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int numDays = days[month - 1];
        if (month == 2 && isLeapYear(year)) numDays++;
        return numDays;
    }

    bool isLeapYear(int year) const { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }

    int getDaysSinceEpoch(int day, int month, int year) const {
        int days = day - 1;
        for (int y = 1970; y < year; y++) {
            days += isLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month; m++) {
            days += daysInMonth(m, year);
        }
        return days;
    }
};