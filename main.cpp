#include <iostream>
#include <vector>

class Contact
{
private:
    std::string Name;
    std::string PhoneNumber;

public:
    std::string getName()
    {
        return Name;
    }

    std::string getPhoneNumber()
    {
        return PhoneNumber;
    }

    Contact(std::string name, std::string phoneNumber)
    {
        Name = name;
        PhoneNumber = phoneNumber;
    }
};

std::vector <Contact> Contacts;

void addContact()
{
    std::string name;
    std::string phoneNumber;
    std::cout << "Enter the name : ";
    std::getline(std::cin, name);
    std::cout << "Enter the Phone Number : ";
    std::getline(std::cin, phoneNumber);
    Contact contact = Contact(name, phoneNumber);
    Contacts.push_back(contact);
}

void viewAllContacts()
{
    for(int i = 0; i < Contacts.size(); i++)
    {
        std::cout << "\n\nName - " << Contacts[i].getName() << "\nPhone - " << Contacts[i].getPhoneNumber() << std::endl;
    }
}

void deleteContact()
{
    for(int i = 0; i < Contacts.size(); i++)
    {
        std::cout << i << "\n\nName - " << Contacts[i].getName() << "\nPhone - " << Contacts[i].getPhoneNumber() << std::endl;
    }
    int num;
    std::cout << "Enter the id of the number you want to delete : ";
    std::cin >> num;
    if (num > 0 && num < Contacts.size())
    {
        Contacts.erase(Contacts.begin() + num);
        std::cout << "Successfully deleted the contact" << std::endl;
    }
    else
    {
        std::cout << "Invalid Contact Id" << std::endl;
    }
}

int main(void)
{
    std::string help = "\n\t\t\tHelp Menu\n1. Add Contacts\n2. View All Contacts\n3. Delete a contact.\n";
    bool running = true;
    std::cout << help << std::endl;

    while(running)
    {
        int choice;

        std::cout << "Enter your choice : ";
        std::cin >> choice;
        std::cin.ignore();

        switch(choice)
        {
            case 1:
                addContact();
                break;
            case 2:
                viewAllContacts();
                break;
            case 3:
                deleteContact();
                break;
            default:
                std::cout << "[!] Invalid Choice" << std::endl;
                break;
        }
    }
}
