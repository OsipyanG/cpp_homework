#include <iostream>
#include <string>

class NotifierBase {
   public:
    virtual void Notify(const std::string& message) const = 0;
};

class SmsNotifier : public NotifierBase {
   public:
    SmsNotifier(const std::string& number) : number_(number) {}

    void Notify(const std::string& message) const override { SendSms(number_, message); }

   private:
    std::string number_;
};

class EmailNotifier : public NotifierBase {
   public:
    EmailNotifier(const std::string& email) : email_(email) {}

    void Notify(const std::string& message) const override { SendEmail(email_, message); }

   private:
    std::string email_;
};