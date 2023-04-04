//1. Презентация просмотрена
//2. Видео Барабаша глянуто
// Остальные таски в самом коде:)

#include <iostream> 
#include <list> 
#include <stdlib.h>

using namespace std;

//Дописаны конструкторы и гет/сет-методы
class Date
{
	int day;
	int month;
	int year;

public:
	Date()
	{
		day = 01;
		month = 01;
		year = 2023;
	}

	Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	void SetDay(int day)
	{
		if (day <= 1 || day >= 31)
		{
			cout << "THE DAY IS INCORRECT!";
			exit(1);
		}
		else
			this->day = day;
	}

	void SetMonth(int month)
	{
		if (month <= 1 || month >= 12)
		{
			cout << "THE MONTH IS INCORRECT!";
			exit(1);
		}
		else
			this->month = month;
	}

	void SetYear(int year)
	{
		if (year <= 1 || year >= 2023)
		{
			cout << "THE YEAR IS INCORRECT!";
			exit(1);
		}
		else
			this->year = year;
	}

	int GetDay() const { return this->day; }
	int GetMonth() const { return this->month; }
	int GetYear() const { return this->year; }
};

//Дописаны конструкторы и гет/сет-методы
class Rate
{
	int value; 
	Date date;
	string subject;
	string prepod;
	int lesson;

public:
	Rate()
	{
		value = 1;
		date = Date();
		prepod = "Alex";
		subject = "UML";
		lesson = 1;
	}
	Rate(int v, Date d, string p, string s, int l)
	{
		value = v;
		date = d;
		prepod = p;
		subject = s;
		lesson = l;
	}
	void SetValue(int value)
	{
		if (value <= 1 || value >= 12)
		{
			cout << "THE VALUE IS INCORRECT!";
			exit(1);
		}
		else
			this->value = value;
	}

	void SetDate(Date date) { this->date = date; }
	void SetSubject(string subject) { this->subject = subject; }
	void SetPrepod(string prepod) { this->prepod = prepod; }
	void SetLesson(int lesson) { this->lesson = lesson; }

	int GetValue() const { return this->value; }
	Date GetDate() const { return this->date; }
	string GetPrepod() const { return this->prepod; }
	string GetSubject() const { return this->subject; }

	int GetLesson() const { return this->lesson; }

	bool operator == (const Rate& obj) const
	{
		if (obj.GetDate().GetDay() == GetDate().GetDay() &&
			obj.GetDate().GetMonth() == GetDate().GetMonth() &&
			obj.GetDate().GetYear() == GetDate().GetYear() &&
			obj.GetLesson() == GetLesson() &&
			obj.GetPrepod() == GetPrepod() &&
			obj.GetSubject() == GetSubject() &&
			obj.GetValue() == GetValue())
		{
			return true;
		}
		return false;
	}
};

//Дописаны конструкторы и гет/сет-методы + методы AddRate, ChangeRate, DeleteRate
class RateCollection
{
	list<Rate> r_c;

public:
	RateCollection(list<Rate> r_c = list<Rate>()) { this->r_c = r_c; }

	void AddRate(Date date, string prepod, string subject, int value, int lesson) 
	{
		//стандартные проверочки
		if (value <= 1 || value >= 12) 
		{
			cout << "THE VALUE IS INCORRECT!";
			exit(1);
		}
		else if (date.GetDay() <= 1 || date.GetDay() >= 31 || date.GetMonth() <= 1 || date.GetMonth() >= 12 || date.GetYear() <= 1 || date.GetYear() >= 2023)
		{
			cout << "THE DATE IS INCORRECT!";
			exit(1);
		}
		else if (prepod == "")
		{
			cout << "THE PREPOD IS INCORRECT!";
			exit(1);
		}
		else if (subject == "")
		{
			cout << "THE SUBJECT IS INCORRECT!";
			exit(1);
		}
		else if (lesson <= 0) 
		{
			cout << "THE LESSON IS INCORRECT!";
			exit(1);
		}
		else
		{
			Rate obj = Rate(value, Date(date.GetDay(), date.GetMonth(), date.GetYear()), prepod, subject, lesson);
			this->r_c.push_back(obj);
		}
	}

	void AddRate(Rate rate) 
	{
		if (rate.GetValue() <= 1 || rate.GetValue() >= 12)
		{
			cout << "THE VALUE IS INCORRECT!";
			exit(1);
		}
		else if (rate.GetDate().GetDay() <= 1 || rate.GetDate().GetDay() >= 31 || rate.GetDate().GetMonth() < 1 || rate.GetDate().GetMonth() > 12 || rate.GetDate().GetYear() < 1 || rate.GetDate().GetYear() > 2023)
		{
			cout << "THE DATE IS INCORRECT!";
			exit(1);
		}
		else if (rate.GetPrepod() == "") 
		{
			cout << "THE PREPOD IS INCORRECT!";
			exit(1);
		}
		else if (rate.GetSubject() == "")
		{
			cout << "THE SUBJECT IS INCORRECT!";
			exit(1);
		}
		else if (rate.GetLesson() <= 1) 
		{
			cout << "THE LESSON IS INCORRECT!";
			exit(1);
		}
		else this->r_c.push_back(rate);
	}

	void ChangeRate(int index)
	{
		int value;
		int day;
		int month;
		int year;
		string prepod;
		string subject;
		int lesson;

		cout << "Enter a value: ";
		cin >> value;
		while (value <= 1 || value >= 12)
		{
			cout << endl;
			cin >> value;
		}

		cout << endl << "Enter day: ";
		cin >> day;
		while (day <= 1 || day >= 31)
		{
			cout << endl;
			cin >> day;
		}

		cout << endl << "Enter month: ";
		cin >> month;
		while (month <= 1 || month >= 12)
		{
			cout << endl;
			cin >> month;
		}

		cout << endl << "Enter year: ";
		cin >> year;
		while (year <= 1 || year >= 2023)
		{
			cout << endl;
			cin >> year;
		}

		cout << endl << "Enter prepod: ";
		while (prepod == "")
		{
			cout << endl;
			cin >> prepod;
		}

		cout << endl << "Enter subject: ";
		while (subject == "")
		{
			cout << endl;
			cin >> subject;
		}

		cout << endl << "Enter lesson: ";
		cin >> lesson;
		while (lesson < 0)
		{
			cout << endl;
			cin >> lesson;
		}

		Rate obj = Rate(value, Date(day, month, year), prepod, subject, lesson);
		int counter = 0;
		for (Rate var : r_c)
		{
			Rate prev = var;
			cout << prev.GetPrepod() << endl;
			if (counter == index)
			{
				r_c.remove(var);
				r_c.push_back(obj);
				break;
			}
			index++;
		}
	}

	void DeleteRate(int index)
	{
		int counter = 0;

		for (Rate var : r_c)
		{
			Rate before = var;
			if (counter == index)
			{
				r_c.remove(before);
			}
		}
	}

	void Print()
	{
		for (Rate var : r_c)
		{
			cout << "Value: " << var.GetValue() << endl;
			cout << "Day: " << var.GetDate().GetDay() << endl;
			cout << "Month: " << var.GetDate().GetMonth() << endl;
			cout << "Year: " << var.GetDate().GetYear() << endl;
			cout << "Prepod: " << var.GetPrepod() << endl;
			cout << "Subject: " << var.GetSubject() << endl;
			cout << "Lesson: " << var.GetLesson() << endl;
		}
	}

	void SetRates(list<Rate> rates) { this->r_c = rates; }

	list<Rate> GetRates() const { return this->r_c; }
};

//всё, что связано с группой выделено в отдельный одноимённый класс
class Group
{
	string speciality;
	string group_name;
	int kurs;

public:
	Group()
	{
		speciality = "design";
		group_name = "KND-211";
		kurs = 2;
	}

	Group(string s, string gn, int k)
	{
		speciality = s;
		group_name = gn;
		kurs = k;
	}
};

//всё, что связано с адресом выделено в отдельный одноимённый класс
class Adress
{
	string country;
	string region;
	string city;
	string street;
	int house_number;
	int flat_number;
	int postal_index;

public:
	Adress()
	{
		country = "Ukraine";
		region = "Odeska";
		city = "Odesa";
		street = "Unknown";
		house_number = 0;
		flat_number = 0;
		postal_index = 0;
	}

	Adress(string c, string r, string ct, string s, int hn, int fn, int pi)
	{
		country = c;
		region = r;
		city = ct;
		street = s;
		house_number = hn;
		flat_number = fn;
		postal_index = pi;
	}
};

class Student
{
	string name;
	string lastname;
	string fathername;
	Date* birthday;

	RateCollection homeworks;
	RateCollection practices; 
	RateCollection kursachies;
	RateCollection exams;

	Group MyGroup;
	Adress MyAdress;
	double average_rate; 
	Date timeOfLearning;
	string university = "IT Step";
	string email = "alex@proton.me";
	string phone_numbers[3] = { "+380630300035", "+380501234567" };
	string avatar = "https://fsx1.itstep.org/api/v1/files/8jjPAOyeLzWLM2qC5UQ9coSV2L43lUYz";

public:

	Student(string name, string lastname, string fathername, Date birthday,
		RateCollection homeworks, RateCollection practices, RateCollection kursachies, RateCollection exams,
		Group MyGroup, Adress MyAdress, double average_rate, Date timeOfLearning)
	{
		this->name = name;
		this->lastname = lastname;
		this->fathername = fathername;
		this->birthday = new Date(birthday.GetDay(), birthday.GetMonth(), birthday.GetYear());
		this->homeworks = homeworks;
		this->practices = practices;
		this->kursachies = kursachies;
		this->exams = exams;
		this->MyGroup = MyGroup;
		this->MyAdress = MyAdress;
		this->average_rate = average_rate;
		this->timeOfLearning = timeOfLearning;
	}

	~Student()
	{
		delete this->birthday;
		this->birthday = nullptr;
	}
};


int main()
{
	setlocale(0, ""); 
	Rate obj = Rate(12, Date(03, 04, 2023), "Alex", "UML", 1);
	Date secObj = obj.GetDate();
	list<Rate> rateS = list<Rate>();
	rateS.push_back(obj);
	RateCollection objR = RateCollection(rateS);
	objR.Print();
	objR.ChangeRate(0);
	objR.Print();
}
