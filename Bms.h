#include <iostream>
#include <string>



class Bms
{
    private:
        std::string Username;
        std::string Password;
        double Balance;

    public:
        void SignMenu();
        void SignUp();
        void SignIn();
        void HomeMenu();
        void Deposit();
        void Withdraw();
        void AccountInformation();
        void ModifyAccount();

        Bms();
        ~Bms();
};