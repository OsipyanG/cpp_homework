#include <iostream>

class Date {
   public:
    Date(int day, int month, int year) {
        if (isValidDate(day, month, year)) {
            day_ = day;
            month_ = month;
            year_ = year;
        } else {
            day_ = 1;
            month_ = 1;
            year_ = 1970;
        }
    }

    int GetDay() const { return day_; }

    int GetMonth() const { return month_; }

    int GetYear() const { return year_; }

    Date operator+(int days) const {
        int totalDays = getDaysSinceEpoch() + days;
        return getDateFromDays(totalDays);
    }

    Date operator-(int days) const {
        int totalDays = getDaysSinceEpoch() - days;
        return getDateFromDays(totalDays);
    }

    int operator-(const Date& other) const {
        int days1 = getDaysSinceEpoch();
        int days2 = other.getDaysSinceEpoch();
        return days1 - days2;
    }

   private:
    int day_;
    int month_;
    int year_;

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

    int getDaysSinceEpoch() const {
        int days = 0;
        for (int y = 1970; y < year_; y++) {
            days += isLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month_; m++) {
            days += daysInMonth(m, year_);
        }
        days += day_ - 1;
        return days;
    }

    Date getDateFromDays(int totalDays) const {
        int year = 1970;
        while (totalDays >= (isLeapYear(year) ? 366 : 365)) {
            totalDays -= isLeapYear(year) ? 366 : 365;
            year++;
        }
        int month = 1;
        while (totalDays >= daysInMonth(month, year)) {
            totalDays -= daysInMonth(month, year);
            month++;
        }
        int day = totalDays + 1;
        return Date(day, month, year);
    }
};
