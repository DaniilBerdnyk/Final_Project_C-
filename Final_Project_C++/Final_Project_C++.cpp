#include <iostream>
#include"MasterHeader.h"

vector<User> users;
vector<Admin> admins;
bool DONE = false;


PC_Shop* PCs = new PC_Shop();
map<int,string> frames = {
    {0,
    "   |----|   \n"
    "   | == |   \n"
    "   |    |   \n"
    "   |    |   \n"
    "   |____|   \n"},
    {1,
    " |----|.   \n"
    " | == ||   \n"
    " |    ||   \n"
    " |    ||   \n"
    " |____||   \n"},
    {2,
    "|----|.   \n"
    "| == | |   \n"
    "|    | |   \n"
    "|    | |   \n"
    "|____| |   \n"},
    {3,
    ":---|.    \n"
    ":== |  .   \n"
    ":   |   |   \n"
    ":   |   |   \n"
    ":___|   |   \n"},
    {4,
    ":--|_      \n"
    ":  |  -_   \n"
    ":  |    |   \n"
    ":  |    |   \n"
    ":__|    |   \n"},
    {5,
    ":-|- .. _   \n"
    ": |      |  \n"
    ": |      |  \n"
    ": |      |  \n"
    ":_|      |  \n"},
    {6,
    ":|^ - .. _  \n"
    ":|        |  \n"
    ":|        |  \n"
    ":|        |  \n"
    ":|        |  \n"},
    { 7,
    "  _ __ __ _  \n"
    " |         |  \n"
    " |         |  \n"
    " |         |  \n"
    " |         |  \n" },
    { 8,
    "  _ __ __ _\n"
    " |         |\n"
    " |         |\n"
    " |         |\n"
    " |         |\n" },
    {9,
    "   _ . - ^|:  \n"
    "  |       |:  \n"
    "  |       |:  \n"
    "  |       |:  \n"
    "  |       |:\n"},
    {10,
    "   _ .. -|-:  \n"
    "  |      | :  \n"
    "  |      | :  \n"
    "  |      | :  \n"
    "  |      |_:\n"},

    {11,
    "       _|--:  \n"
    "    _   |  :  \n"
    "   |    |  :  \n"
    "   |    |  :  \n"
    "   |    |__:  \n"},
    {12,
    "      .|---:  \n"
    "    .  |   :  \n"
    "   |   |   :  \n"
    "   |   |   :  \n"
    "   |   |___:  \n"},
    {13,
    "    .|----|\n"
    "   | |    |\n"
    "   | |    |\n"
    "   | |    |\n"
    "   | |____|\n"},
    {14,
    "   .|----| \n"
    "   ||    | \n"
    "   ||    | \n"
    "   ||    | \n"
    "   ||____| \n"},
    {15,
    "   |----|   \n"
    "   |    |   \n"
    "   |    |   \n"
    "   |    |   \n"
    "   |____|   \n"},
    {16,
    " |----|.   \n"
    " |    ||   \n"
    " |    ||   \n"
    " |    ||   \n"
    " |____||   \n"},
    {17,
    "|----|_   \n"
    "|    | |   \n"
    "|    | |   \n"
    "|    | |   \n"
    "|____| |   \n"},
    {18,
    ":---|.    \n"
    ":   |  .  \n"
    ":   |   |   \n"
    ":   |   |   \n"
    ":___|   |   \n"},
    {19,
    ":--|_       \n"
    ":  |   _   \n"
    ":  |    |   \n"
    ":  |    |   \n"
    ":__|    |   \n"},
    {20,
    ":-|-  . _   \n"
    ": |      |  \n"
    ": |      |  \n"
    ": |      |  \n"
    ":_|      |  \n"},
    {21,
    ":|^ -  . _   \n"
    ":|        |  \n"
    ":|        |  \n"
    ":|        |  \n"
    ":|        |  \n"},
     { 22,
    "  _ _  _ _  \n"
    " |         |  \n"
    " |         |  \n"
    " |         |  \n"
    " |         |  \n" },
    { 23,
    "   _ _  _ _ \n"
    " |         |\n"
    " |         |\n"
    " |         |\n"
    " |         |\n" },
    { 24,
    "   _ .  - |:  \n"
    "  |       |:  \n"
    "  |       |:  \n"
    "  |       |:  \n"
    "  |       |:\n" },
    { 25,
    "   _ .  -|-:  \n"
    "  |      | :  \n"
    "  |      | :  \n"
    "  |      | :  \n"
    "  |      |_:\n" },

    { 26,
    "       _|--:  \n"
    "   _ ^  |  :  \n"
    "   |    |  :  \n"
    "   |    |  :  \n"
    "   |    |__:  \n" },
    { 27,
    "      .|---:  \n"
    "     ^ | ==:  \n"
    "    |  |   :  \n"
    "    |  |   :  \n"
    "    |  |___:  \n" },
    { 28,
    "     _|----|\n"
    "    | | == |\n"
    "    | |    |\n"
    "    | |    |\n"
    "    | |____|\n" },
    { 29,
    "    .|----| \n"
    "    || == | \n"
    "    ||    | \n"
    "    ||    | \n"
    "    ||____| \n" }
};

void animation() {
    SetBlue();
    while (DONE != true)
    {
        for (int i = 0; i < 30; i++)
        {
            if (DONE == true) { return; }
            ostringstream buffer;
            buffer << frames[i] <<endl;
            system("cls");
            cout << buffer.str();
            Sleep(100);
        }
    }
}


void loadUsers() {
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(TEXT("User_*.txt"), &data)) != INVALID_HANDLE_VALUE) {
        do {
            char filename[MAX_PATH];
            size_t outSize;
            wcstombs_s(&outSize, filename, data.cFileName, MAX_PATH);
            ifstream inFile(filename);
            string name;
            int money;
            string line;
            getline(inFile, line);
            name = line.substr(line.find(":") + 2);

            getline(inFile, line);  
            line = line.substr(line.find(":") + 2); 
            money = stoi(line); 

            users.push_back(User(name, money));
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}

void loadAdmins() {
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(TEXT("Admin_*.txt"), &data)) != INVALID_HANDLE_VALUE) {
        do {
            char filename[MAX_PATH];
            size_t outSize;
            wcstombs_s(&outSize, filename, data.cFileName, MAX_PATH);
            ifstream inFile(filename);
            string name;
            string password;
            string line;
            getline(inFile, line);
            name = line.substr(line.find(":") + 2); 
            getline(inFile, line);
            password = line.substr(line.find(":") + 2); 
            admins.push_back(Admin(name, password));
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}



void addUser() {
    string name;
    int money;
    SetBlue(); cout << "Введите имя пользователя: ";
    cin >> name;
    cout << "Введите баланс пользователя: ";
    cin >> money;
    thread th(animation);
    User newUser(name, money);
    users.push_back(newUser);
    DONE = true;
    th.join();
}

void deleteUser() {
    string name;
    SetBlue(); cout << "Введите имя пользователя для удаления: ";
    cin >> name;
    thread th(animation);
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getName() == name) {
            users.erase(it);
            string filename = "User_" + name + ".txt";
            if (remove(filename.c_str()) != 0) {
                SetRed(); cout << "Ошибка при удалении файла." << endl;
            }
            else {
                SetGreen(); cout << "Пользователь и его файл успешно удалены." << endl;
            }
            DONE = true;
            th.join();
            return;
        }
    }
    SetRed(); cout << "Пользователь не найден." << endl;
    DONE = true;
    th.join();
}

void showUsers() {
    for (const auto& user : users) {
        SetGreen(); cout << user.getName() << " - " << user.rules << endl;
    }
    for (const auto& admin : admins) {
        SetRed(); cout << admin.getName() << " - " << admin.rules << endl;
    }
}

void menu(User& user) {
    system("cls");
    int userChoice;
    do {
        SetBlue(); cout << "1. Вернуться в меню выбора\n";
        SetGreen(); cout << "2. Открыть магазин\n";
        SetRed(); cout << "3. Выход\n";
        SetBlue(); cout << "\nВыберите действие: ";
        cin >> userChoice;
        switch (userChoice) {
        case 1:
            return;
        case 2:
            system("cls");
            PCs->OpenIn(user);
            break;
        case 3:
            SetBlue(); cout << "Выход из меню пользователя." << endl;
            exit(0);
        default:
            SetRed(); cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    } while (userChoice != 3);
}

void menu(Admin& admin) {
    
    string password;
    SetBlue(); cout << "Введите пароль админа: ";
    SetRed(); cin >> password; SetBlue();
    if (password != admin.GetPassword()) {
        SetRed(); cout << "Неверный пароль." << endl;
        return;
    }
    system("cls");
    int adminChoice;
    do {
        SetBlue(); cout << "1. Добавить пользователя\n";
        SetBlue(); cout << "2. Удалить пользователя\n";
        SetGreen(); cout << "3. Открыть магазин\n";
        SetRed(); cout << "4. Выход\n";
        SetBlue(); cout << "\nВыберите действие: ";
        cin >> adminChoice;
        switch (adminChoice) {
        case 1:
            addUser();
            break;
        case 2:
            deleteUser();
            break;
        case 3:
            system("cls");
            PCs->OpenIn(admin);
            break;
        case 4:
            SetBlue(); cout << "Выход из меню администратора." << endl;
            return;
        default:
            SetRed();  cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    } while (adminChoice != 4);
}

void Main_Menu() {

    
    string name;
    bool validUser = false;

    while (!validUser) {
        showUsers();
        SetBlue(); cout << "Введите имя пользователя для входа: ";
        SetGreen(); cin >> name; SetBlue();

        for (auto& user : users) {
            if (user.getName() == name) {
                menu(user);
                validUser = true;
                break;
            }
        }

        for (auto& admin : admins) {
            if (admin.getName() == name) {
                menu(admin);
                validUser = true;
                break;
            }
        }

        if (!validUser) {
            SetRed();  cout << "Пользователь не найден. Попробуйте еще раз." << endl; Sleep(400); system("cls");
        }
    }

}


int main() {
    thread th(animation);
    thread thr1(loadUsers);
    thread thr2(loadAdmins);
    
    Sleep(3300); 
    DONE = true;

    th.detach();
    thr1.detach();
    thr2.detach();
    Sleep(200);

    cout << "Users: \n" <<endl;
    Main_Menu();
    return 0;
}

