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
        void SignUp(std::string username, std::string password, double balance);
        void SignIn(std::string username, std::string password);
        void HomeMenu();
        void GetAccountInformation();

        Bms();
        ~Bms();
};