#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>

class User {
	private:
		std::string username;
		std::string password;
	public:
		User(const std::string& name, const std::string& pass) {
			username = name;
			password = pass;
		}
		std::string getUsername(){

			return username;
		}

		std::string getPassword(){

			return password;
		}
};
class UserManager {
	private:
		std::vector<User> users; //create object of vector
	public:
		void RegisterUser(){
			std::string username, password;
			std::cout <<"Enter User Name: ";
			std::cin >> username;
			std::cout << "Enter password: ";
			std::cin >> password;

			User newUser(username, password);
			users.push_back(newUser);

			std::cout << "User Registered Successfuly...." << std::endl;
		}
		bool LoginUser(const std::string& name, const std::string& pass){
			for (size_t i = 0; i < users.size(); i++) {
				if (users[i].getUsername() == name && users[i].getPassword() == pass) {
					std::cout << "Login Successful.." << std::endl;
					return true;
				}
			}
			std::cout << "Invalid Username or Password.." << std::endl;
			return false;
		}
		void showUser() {
			std::cout << "---Users List---" << std::endl;
			for (size_t i = 0;i < users.size();i++) {
				std::cout << "---" << users[i].getUsername() << std::endl;
			}
		}
		void searchUser(const std::string& username) {
			for (size_t i = 0;i < users.size();i++) {
				if (users[i].getUsername() == username) {
					std::cout << "User found.." << std::endl;
				}
			}
		}
		void deleteUser(const std::string& username) {
			for (size_t i = 0; i < users.size();i++) {
				if (users[i].getUsername() == username) {
					users.erase(users.begin() + i);
					std::cout << "User remove successfuly.." << std::endl;
				}
			}
            std::cout << "User not found.." << std::endl;
		}
};

int main() {
    UserManager usermanager;
    int op;

    while (true) {
        system("cls");
        try {
            std::cout << "1. Register User " << std::endl;
            std::cout << "2. Login " << std::endl;
            std::cout << "3. Show User List " << std::endl;
            std::cout << "4. Search User " << std::endl;
            std::cout << "5. Delete User " << std::endl;
            std::cout << "6. Exit" << std::endl;

            std::cout << "Enter your choice: ";
            std::cin >> op;

            // Check if the input is actually an integer
            if (std::cin.fail()) {
                throw std::runtime_error("Please enter a number.");
            }

            // Check if the number is between 1 and 6
            if (op < 1 || op > 6) {
                throw std::out_of_range("Please enter a number between 1 and 6.");
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;

            // Reset cin after invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            system("pause");
            continue;
        }

        switch (op) {

        case 1:
            usermanager.RegisterUser();
            break;

        case 2:
        {
            std::string username, password;

            std::cout << "Enter user: ";
            std::cin >> username;

            std::cout << "Enter password: ";
            std::cin >> password;

            usermanager.LoginUser(username, password);
            break;
        }

        case 3:
            usermanager.showUser();
            break;

        case 4:
        {
            std::string username;

            std::cout << "Enter the username: ";
            std::cin >> username;

            usermanager.searchUser(username);
            break;
        }

        case 5:
        {
            std::string username;

            std::cout << "Enter username: ";
            std::cin >> username;

            usermanager.deleteUser(username);
            break;
        }

        case 6:
            return 0;
        }

        system("pause");
    }

    return 0;
}