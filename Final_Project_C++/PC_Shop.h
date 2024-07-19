#pragma once

#include"PC_Shop_MasterHeader.h"
using namespace std;



class PC_Shop
{
	deque<PC*> sold_pcs;
	static const int MAX_SOLD_PCS = 10;

	string name;
	vector<PC*> pcs;
public:
	PC_Shop() { name = "Undefined"; }
	PC_Shop(string name) { this->name = name; }

	~PC_Shop() {
		for (PC* pc : pcs) {
			delete pc;
		}
	}
	PC_Shop& operator+(PC* pc) {
		pcs.push_back(pc);
		writePCListToFile();
		return *this;
	}



	void OpenIn(Admin& obj) {
		IntAdmin(obj);
	}

	void OpenIn(User& obj) {
		IntUser(obj);
	}

	template<typename T>
	void IntUser(T& obj) {
		string text;
		readSoldPCsFromFile();
		readPCListFromFile();
		Sleep(150);
		cout << "Добро пожаловать: " << obj.getName() <<"   Ваш баланс: "<<obj.getMoney()<< endl;
		while (true) {
			SetGreen(); cout << "   Версия меню пользователя" << endl; SetBlue();
			cout << "Напишите 'стоп' чтобы остановить " << endl << endl;
			cout << "Чтобы увидеть список ПК , напишите 1" << endl;
			cout << "Чтобы отсортировать список ПК по имени , напишите "; SetRed(); cout << "N"; SetBlue(); cout << " или по стоимости напишите "; SetRed(); cout << "C" << endl; SetBlue();
			cout << "Чтобы купить ПК по ID напишите 2 , если по имени напишите 3" << endl;
			cin >> text;
			if (text == "СТОП" || text == "Стоп" || text == "стоп") { system("cls"); break; }

			if (text == "1") { if (pcs.size() == 0) { cout << "Ничего нет" << endl; } showAllPCs(); cin.ignore(); cin.get(); }
			else if (text == "N" || text == "C") {
				vector<PC*> tempPCs = pcs;
				if (text == "N") { sortPCsByName(tempPCs); }
				else if (text == "C") { sortPCsByCost(tempPCs); }
			}
			else if (text == "2") {
				cout << "Введите ID ПК для покупки: ";
				int pcID; cin >> pcID;
				buyPC(pcID, obj, obj.getName());
			}
			else if (text == "3") {
				cout << "Введите Имя ПК для покупки: ";
				string pcName; cin >> pcName;
				buyPC(pcName, obj, obj.getName());
			}
			else { cout << "Неверный ввод!" << endl; }
			system("cls");
		}
	}

	template<typename T>
	void buyPC(int pcID, T& obj, const string& userName) {
		PC* chosenPC = findPCByID(pcID);
		if (chosenPC == nullptr) {
			cout << "ПК с таким ID не найден." << endl;
			return;
		}

		int pcCost = chosenPC->getCost();

		if (obj.getMoney() >= pcCost) {
			obj.setMoney(obj.getMoney() - pcCost);
			cout << "Покупка успешно совершена!" << endl;
			Sleep(500);
			sold_pcs.push_front(chosenPC);
			removePCFromVector(pcs, chosenPC);

			if (sold_pcs.size() > MAX_SOLD_PCS) {
				sold_pcs.pop_back();
			}
			writePCListToFile();
			writeSoldPCsToFile(obj.getName());
		}
		else {
			cout << "У вас недостаточно средств для покупки этого ПК." << endl;
		}
	}

	PC* findPCByID(int pcID) {
		for (PC* pc : pcs) {
			if (pc->getID() == pcID) {
				return pc;
			}
		}
		return nullptr;
	}



	template<typename T>
	void buyPC(string pcName, T& obj, const string& userName) {
		PC* chosenPC = findPCByName(pcName);
		if (chosenPC == nullptr) {
			cout << "ПК с таким именем не найден." << endl;
			return;
		}

		int pcCost = chosenPC->getCost();

		if (obj.getMoney() >= pcCost) {
			obj.setMoney(obj.getMoney() - pcCost);
			cout << "Покупка успешно совершена!" << endl;
			Sleep(500);
			sold_pcs.push_front(chosenPC);
			removePCFromVector(pcs, chosenPC);

			if (sold_pcs.size() > MAX_SOLD_PCS) {
				sold_pcs.pop_back();
			}
			writePCListToFile();
			writeSoldPCsToFile(obj.getName());
			
		}
		else {
			cout << "У вас недостаточно средств для покупки этого ПК." << endl;
		}
	}

	PC* findPCByName(string pcName) {
		for (PC* pc : pcs) {
			if (pc->getName() == pcName) {
				return pc;
			}
		}
		return nullptr;
	}

	void removePCFromVector(vector<PC*>& vec, PC* pc) {
		vec.erase(remove(vec.begin(), vec.end(), pc), vec.end());
	}

	//-------------------------------------------------

	template<typename T>
	void IntAdmin(T& obj) {
		string text;
		readSoldPCsFromFile();
	    readPCListFromFile();
		
		Sleep(150);
		cout << "Добро пожаловать: " << obj.getName() << endl << endl;
		while (true) {
			SetRed(); cout << "   Версия меню администратора" << endl; SetBlue();
			cout << "Напишите 'стоп' чтобы остановить " << endl << endl;
			cout << "Чтобы увидеть список ПК , напишите 1" << endl;
			cout << "Чтобы отсортировать список ПК по имени , напишите "; SetRed(); cout << "N"; SetBlue(); cout << " или по стоимости напишите "; SetRed(); cout << "C" << endl; SetBlue();
			cout << "Чтобы изменить ваш пароль , напишите 2" << endl;
			cout << "Чтобы добавить ПК , напишите 3" << endl;
			cout << "Чтобы очистить файл , напишите 4" << endl;
			cout << "" << endl;
			cin >> text;
			if (text == "СТОП" || text == "Стоп" || text == "стоп") { system("cls"); break; }

			if (text == "1") { if (pcs.size() == 0) { cout << "Ничего нет" << endl; } showAllPCs(); cin.ignore(); cin.get(); }
			else if (text == "N" || text == "C") {
				vector<PC*> tempPCs = pcs;  
				if (text == "N") { sortPCsByName(tempPCs); }
				else if (text == "C") { sortPCsByCost(tempPCs); }
			}
			else if (text == "2") { obj.ChangePassword(); }
			else if (text == "3") {
				cout << "Выберите стоимость ПК: 1-Дешевый 2-Средний 3-Дорогой" << endl;
				int choose; cin >> choose;
				if (choose < 1 || choose>3) { cout << "Ошибка" << endl; return; }
				else if (choose == 1) { addNewCheapPC(); }
				else if (choose == 2) { addNewMidPC(); }
				else { addNewExpensivePC(); }
				writePCListToFile();
			}
			else if (text == "4") {
				cout << "Напишите пароль, чтобы удалить файл: "; SetRed(); cin >> text; cout << endl;
				if (text == obj.GetPassword())
				{
					SetGreen(); cout << "Успех !" << endl; Sleep(500);
					clearFile();
					readPCListFromFile();
				}
				else { SetRed(); cout << "Неверный пароль!" << endl; Sleep(500); }
			}
			else { cout << "Неверный ввод!" << endl; }
			system("cls");
		}
	}


	void sortPCsByName(vector<PC*> tempPCs) {
		sort(tempPCs.begin(), tempPCs.end(), [](PC*a , PC * b){ return a->getName() < b->getName(); });
		for (PC* pc : tempPCs) {
			SetRed();
			cout << "ID: " << pc->getID();
			cout << endl;
			SetBlue();
			pc->showInfo();
			cout << endl;
		}
		cin.ignore();
		cin.get();
	}

	void sortPCsByCost(vector<PC*> tempPCs) {
		sort(tempPCs.begin(), tempPCs.end(),[](PC*a , PC* b){ return a->getCost() < b->getCost(); });
		for (PC* pc : tempPCs) {  
			SetRed();
			cout << "ID: " << pc->getID();
			cout << endl;
			SetBlue();
			pc->showInfo();
			cout << endl;
		}
		cin.ignore();
		cin.get();
	}

	
	void showAllPCs() {
		for (PC* pc : pcs) {
			SetRed();
			cout << "ID: "<<pc->getID();
			cout << endl;
			SetBlue();
			pc->showInfo();
			cout << endl;
			Sleep(200);
		}
	}

	void addPC(PC* pc) {
		*this + pc;
	}

	void addNewCheapPC() {
		string name;
		string description;
		bool integratedGPU;
		float sale;
		int cost;

		try {
			cout << "Введите название компьютера: ";
			cin >> name;
			cout << "Введите описание компьютера: ";
			cin.ignore();  
			getline(cin, description);

			cout << "Есть ли интегрированный GPU? (1 - да, 0 - нет): ";
			cin >> integratedGPU;
			if (integratedGPU != 1 && integratedGPU != 0) {
				throw runtime_error("Wrong input for GPU");
			}

			cout << "Введите скидку: ";
			cin >> sale;
			if (sale > 1 || sale <= 0) {
				throw runtime_error("Wrong Sale");
			}

			cout << "Введите стоимость компьютера: ";
			cin >> cost;
			if (cost <= 0) {
				throw runtime_error("Wrong cost");
			}

			Cheap_PC* new_cheap_pc = new Cheap_PC(PC::counter++, name, description, integratedGPU, sale, cost);
			addPC(new_cheap_pc);
		}
		catch (const runtime_error& e) {
			SetRed();
			cout << e.what() << endl;
			SetBlue();
		}
	}

	void addNewExpensivePC() {
		try {
			string name;
			string description;
			bool watercooled;
			bool sli;
			int cost;

			cout << "Введите название компьютера: ";
			cin >> name;
			cout << "Введите описание компьютера: ";
			cin.ignore();
			getline(cin, description);
			cout << "Есть ли водяное охлаждение? (1 - да, 0 - нет): ";
			cin >> watercooled;
			if (watercooled != 1 && watercooled != 0) {
				throw runtime_error("Wrong input for watercooling");
			}
			cout << "Поддерживает ли SLI? (1 - да, 0 - нет): ";
			cin >> sli;
			if (sli != 1 && sli != 0) {
				throw runtime_error("Wrong input for SLI");
			}
			cout << "Введите стоимость компьютера: ";
			cin >> cost;
			if (cost <= 0) {
				throw runtime_error("Wrong cost");
			}

			Expensive_PC* new_expensive_pc = new Expensive_PC(PC::counter++, name, description, watercooled, sli, cost);
			addPC(new_expensive_pc);
		}
		catch (const runtime_error& e) {
			SetRed();
			cout << e.what() << endl;
			SetBlue();
		}
	}

	void addNewMidPC() {
		try {
			string name;
			string description;
			bool vrReady;
			bool ssd;
			bool ddr5Ready;
			int cost;

			cout << "Введите название компьютера: ";
			cin >> name;
			cout << "Введите описание компьютера: ";
			cin.ignore();
			getline(cin, description);
			cout << "Поддерживает ли VR? (1 - да, 0 - нет): ";
			cin >> vrReady;
			if (vrReady != 1 && vrReady != 0) {
				throw runtime_error("Wrong input for VR");
			}
			cout << "Есть ли SSD? (1 - да, 0 - нет): ";
			cin >> ssd;
			if (ssd != 1 && ssd != 0) {
				throw runtime_error("Wrong input for SSD");
			}
			cout << "Поддерживает ли DDR5? (1 - да, 0 - нет): ";
			cin >> ddr5Ready;
			if (ddr5Ready != 1 && ddr5Ready != 0) {
				throw runtime_error("Wrong input for DDR5");
			}
			cout << "Введите стоимость компьютера: ";
			cin >> cost;
			if (cost <= 0) {
				throw runtime_error("Wrong cost");
			}

			Mid_PC* new_mid_pc = new Mid_PC(PC::counter++, name, description, vrReady, ssd, ddr5Ready, cost);
			addPC(new_mid_pc);
		}
		catch (const runtime_error& e) {
			SetRed();
			cout << e.what() << endl;
			SetBlue();
		}
	}

private:
	void readCounterFromFile() {
		ifstream inFile("counter.txt");
		if (inFile.is_open()) {
			string line;
			if (getline(inFile, line)) {
				PC::counter = stoi(line);
			}
			inFile.close();
		}
	}

	void writeCounterToFile() const {
		ofstream outFile("counter.txt");
		if (outFile.is_open()) {
			outFile << PC::counter;
			outFile.close();
		}
		else {
			cout << "Unable to open counter file";
		}
	}

	void readPCListFromFile() {
		readCounterFromFile();

		for (PC* pc : pcs) {
			delete pc;
		}
		pcs.clear();

		ifstream inFile("PC_list.txt");
		if (inFile.is_open()) {
			string line;
			while (getline(inFile, line)) {
				stringstream ss(line);
				string property;

				getline(ss, property, ',');
				string type = property;

				getline(ss, property, ',');
				int id = stoi(property);

				getline(ss, property, ',');
				string name = property;

				getline(ss, property, ',');
				string description = property;

				getline(ss, property, ',');
				int cost = stoi(property);

				PC* pc = nullptr;
				if (type == "Cheap_PC") {
					getline(ss, property, ',');
					bool integratedGPU = stoi(property) != 0;

					getline(ss, property, ',');
					float sale = stof(property);

					pc = new Cheap_PC(id, name, description, integratedGPU, sale, cost);
				}
				else if (type == "Mid_PC") {
					getline(ss, property, ',');
					bool vrReady = stoi(property) != 0;

					getline(ss, property, ',');
					bool ssd = stoi(property) != 0;

					getline(ss, property, ',');
					bool ddr5Ready = stoi(property) != 0;

					pc = new Mid_PC(id, name, description, vrReady, ssd, ddr5Ready, cost);
				}
				else if (type == "Expensive_PC") {
					getline(ss, property, ',');
					bool watercooled = stoi(property) != 0;

					getline(ss, property, ',');
					bool sli = stoi(property) != 0;

					pc = new Expensive_PC(id, name, description, watercooled, sli, cost);
				}

				if (pc != nullptr) {
					pcs.push_back(pc);
				}
			}
			inFile.close();
		}
		
	}

	void writePCListToFile() const {
		writeCounterToFile();
		ofstream outFile("PC_list.txt");
		if (outFile.is_open()) {
			for (const PC* pc : pcs) {
				if (pc == NULL) continue;

				if (dynamic_cast<const Cheap_PC*>(pc)) {
					outFile << "Cheap_PC,";
				}
				else if (dynamic_cast<const Mid_PC*>(pc)) {
					outFile << "Mid_PC,";
				}
				else if (dynamic_cast<const Expensive_PC*>(pc)) {
					outFile << "Expensive_PC,";
				}

				outFile << pc->getAllPropertiesAsString() << endl;
			}
			outFile.close();
		}
		else {
			cout << "Unable to open file";
		}
	}


	void writeSoldPCsToFile(const string& userName) const {
		ofstream outFile("sold_pcs.txt");
		if (outFile.is_open()) {
			for (int i = 0; i < sold_pcs.size(); i++) {
				const PC* pc = sold_pcs[i];
				if (pc == NULL) continue;

				if (dynamic_cast<const Cheap_PC*>(pc)) {
					outFile << "Cheap_PC,";
				}
				else if (dynamic_cast<const Mid_PC*>(pc)) {
					outFile << "Mid_PC,";
				}
				else if (dynamic_cast<const Expensive_PC*>(pc)) {
					outFile << "Expensive_PC,";
				}

				outFile << pc->getAllPropertiesAsString() << "," << userName << endl; // добавляем имя пользователя в конец строки
			}
			outFile.close();
		}
		else {
			cout << "Unable to open file";
		}
	}
	
	void readSoldPCsFromFile() {
		ifstream inFile("sold_pcs.txt");
		if (inFile.is_open()) {
			string line;
			while (getline(inFile, line) && sold_pcs.size() < MAX_SOLD_PCS) {
				stringstream ss(line);
				string property;

				getline(ss, property, ',');
				string type = property;

				getline(ss, property, ',');
				int id = stoi(property);

				getline(ss, property, ',');
				string name = property;

				getline(ss, property, ',');
				string description = property;

				getline(ss, property, ',');
				int cost = stoi(property);

				PC* pc = nullptr;
				if (type == "Cheap_PC") {
					getline(ss, property, ',');
					bool integratedGPU = stoi(property) != 0;

					getline(ss, property, ',');
					float sale = stof(property);

					pc = new Cheap_PC(id, name, description, integratedGPU, sale, cost);
				}
				else if (type == "Mid_PC") {
					getline(ss, property, ',');
					bool vrReady = stoi(property) != 0;

					getline(ss, property, ',');
					bool ssd = stoi(property) != 0;

					getline(ss, property, ',');
					bool ddr5Ready = stoi(property) != 0;

					pc = new Mid_PC(id, name, description, vrReady, ssd, ddr5Ready, cost);
				}
				else if (type == "Expensive_PC") {
					getline(ss, property, ',');
					bool watercooled = stoi(property) != 0;

					getline(ss, property, ',');
					bool sli = stoi(property) != 0;

					pc = new Expensive_PC(id, name, description, watercooled, sli, cost);
				}

				
				getline(ss, property, ',');

				if (pc != nullptr) {
					sold_pcs.push_back(pc);
				}
			}
			inFile.close();
		}
	}




	void clearFile() {
		ofstream outFile("PC_list.txt");
		outFile.close();
	}

};

