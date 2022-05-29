#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<utility>
#include<algorithm>
#include<ctime>
using namespace std;
/**********************************
 * Sales Manager
***********************************/
class Items
{
	public:
		int id;
		string name;
		string type;
		int quantity;
		float prices;
		string source;
		string dateOfManufacture;
		string importDate;
		Items()
		{
			this->id=0;
			this->name="";
			this->quantity=0;
			this->prices=0;
			this->source="";
			this->dateOfManufacture="";
			this->importDate="";
		}
		Items(int id,string name,int quantity,float prices,string source,string dateOfManufacture,string importDate)
		{
			this->id=id;
			this->name=name;
			this->quantity=quantity;
			this->prices=prices;
			this->source=source;
			this->dateOfManufacture=dateOfManufacture;
			this->importDate=importDate;
		}
		virtual void input();
		virtual void output();
		virtual float caculated() = 0;
};

void Items::input()
{
	cout<<setw(38)<<"----------------------------------"<<endl;
	cout<<endl;
	cout<<setw(14)<<"Enter ID: ";
	cin>>id;
	cin.ignore();
	cout<<setw(16)<<"Enter Name: ";
	getline(cin,name);
	cout<<setw(20)<<"Enter Quantity: ";
	cin>>quantity;
	cin.ignore();
	cout<<setw(18)<<"Enter Prices: ";
	cin>>prices;
	cin.ignore();
//	cout<<setw(16)<<"Enter Type: ";
//	getline(cin,type);
	cout<<setw(18)<<"Enter Source: ";
	getline(cin,source);
	cout<<setw(29)<<"Enter dateOfManufacture: ";
	getline(cin,dateOfManufacture);
	cout<<setw(22)<<"Enter importDate: ";
	getline(cin,importDate);
}
void Items::output()
{
	cout<<" ----------------------------------------------"<<endl;
	cout<<"| "<<setw(18)<<left<<"ID "<<left<<"| ";
	cout<<setw(18)<<left<<id<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Name "<<left<<"| ";
	cout<<setw(20)<<left<<name<<setw(6)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Quantity "<<left<<"| ";
	cout<<setw(18)<<left<<quantity<<setw(8)<<right<<"|"<<endl;
	cout<<fixed;
	cout.precision(0);
	cout<<"| "<<setw(18)<<left<<"Prices "<<left<<"| ";
	cout<<setw(18)<<left<<prices<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Type "<<left<<"| ";
	cout<<setw(18)<<left<<type<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Source "<<left<<"| ";
	cout<<setw(18)<<left<<source<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"DateOfManufacture "<<left<<"| ";
	cout<<setw(18)<<left<<dateOfManufacture<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"ImportDate "<<left<<"| ";
	cout<<setw(18)<<left<<importDate<<setw(8)<<right<<"|"<<endl;

}
class HouseWares:public Items
{
	public:
		float VAT;
		bool liquidationGoods;
		HouseWares():Items()
		{
			this->type = "House Wares";
			this->VAT = 0;
			this->liquidationGoods = false;
		}
		HouseWares(int id,string name,int quantity,float prices,string source,string dateOfManufacture,string importDate,float VAT, bool liquidationGoods):Items(id,name,quantity,prices,source,dateOfManufacture,importDate)
		{
			this->id=id;
			this->name=name;
			this->quantity=quantity;
			this->prices=prices;
			this->source=source;
			this->dateOfManufacture=dateOfManufacture;
			this->importDate=importDate;
			this->type="House Wares";
			this->VAT=VAT;
			this->liquidationGoods=liquidationGoods;
		}
		void input();
		void output();
		float caculated();
		friend istream &operator>>(istream &is, HouseWares &p);
		friend ostream &operator<<(ostream &os, HouseWares &p);
};
void HouseWares::input()
{
	cout<<endl;
	cout<<" ________________________________________"<<endl;
	cout<<"|                                        |"<<endl;
	cout<<"|       H  O  U  S  E  W  A  R  E  S     |"<<endl;
	cout<<"|________________________________________|"<<endl;
	cout<<endl<<endl;
	Items::input();
	cout<<setw(15)<<"Enter VAT: ";
	cin>>VAT;
	cin.ignore();
}
void HouseWares::output()
{
	Items::output();
	cout<<fixed;
	cout.precision(2);
	cout<<"| "<<setw(18)<<left<<"Calculated "<<left<<"| ";
	cout<<setw(18)<<left<<HouseWares::caculated()<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"VAT "<<left<<"| ";
	cout<<setw(18)<<left<<VAT<<setw(8)<<right<<"|"<<endl;
	cout<<" ----------------------------------------------"<<endl;
}
float HouseWares::caculated()
{
	float a =prices + prices * VAT + 5000;
	return a;
}
istream &operator>>(istream &is, HouseWares &p)
{
	cout<<setw(38)<<"----------------------------------"<<endl;
	cout<<endl;
	cout<<setw(14)<<"Enter ID: ";
	is>>p.id;
	is.ignore();
	cout<<setw(16)<<"Enter Name: ";
	getline(is, p.name);
	cout<<setw(16)<<"Enter Prices: ";
	is>>p.prices;
	cout<<setw(18)<<"Enter Type: ";
	getline(is, p.type);
	is.ignore();
	cout<<setw(18)<<"Enter Source: ";
	getline(is, p.source);
	cout<<setw(29)<<"Enter dateOfManufacture: ";
	getline(is, p.dateOfManufacture);
	cout<<setw(22)<<"Enter importDate: ";
	getline(is, p.importDate);
	cout<<setw(22)<<"Enter VAT: ";
	is>>p.VAT;
	is.ignore();
	return is;
}

ostream &operator<<(ostream &os, HouseWares &p)
{
	cout<<" ----------------------------------------------"<<endl;
	cout<<"| "<<setw(18)<<left<<"ID "<<left<<"| ";
	os<<setw(18)<<left<<p.id<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Name "<<left<<"| ";
	os<<setw(18)<<left<<p.name<<setw(6)<<right<<"|"<<endl;
	cout<<"| "<<setw(20)<<left<<"Type "<<left<<"| ";
	os<<setw(18)<<left<<p.type<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Prices "<<left<<"| ";
	os<<setw(18)<<left<<p.prices<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Source "<<left<<"| ";
	os<<setw(18)<<left<<p.source<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"DateOfManufacture "<<left<<"| ";
	os<<setw(18)<<left<<p.dateOfManufacture<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"ImportDate "<<left<<"| ";
	os<<setw(18)<<left<<p.importDate<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"VAT "<<left<<"| ";
	os<<setw(18)<<left<<p.VAT<<setw(8)<<right<<"|"<<endl;
	cout<<" ----------------------------------------------"<<endl;
	return os;
}

class LearningTools  : public Items
{
	public:
		float VAT;

		LearningTools():Items()
		{
			this->type = "Learning Tools";
			this->VAT = 0;
		}
		LearningTools(int id,string name,int quantity,float prices,string source,string dateOfManufacture,string importDate,float VAT):Items(id,name,quantity,prices,source,dateOfManufacture,importDate)
		{
			this->id=id;
			this->name=name;
			this->quantity=quantity;
			this->prices=prices;
			this->source=source;
			this->dateOfManufacture=dateOfManufacture;
			this->importDate=importDate;
			this->type="Learning Tools";
			this->VAT=VAT;
		}
		void input();
		void output();
		float caculated();
		friend istream &operator>>(istream &is, LearningTools  &p);
		friend ostream &operator<<(ostream &os, LearningTools  &p);
};
void LearningTools::input()
{
	cout<<endl;
	cout<<" _________________________________________________"<<endl;
	cout<<"|                                                 |"<<endl;
	cout<<"|       L  E  A  R  N  I  N  G  T  O  O  L  S     |"<<endl;
	cout<<"|_________________________________________________|"<<endl;
	cout<<endl<<endl;
	cout<<setw(38)<<"----------------------------------"<<endl;
	cout<<endl;
	Items::input();
	cout<<setw(15)<<"Enter VAT: ";
	cin>>VAT;
	cin.ignore();
}

void LearningTools::output()
{
	Items::output();

	cout<<fixed;
	cout.precision(2);

	cout<<"| "<<setw(18)<<left<<"Calculated "<<left<<"| ";
	cout<<setw(18)<<left<<LearningTools::caculated()<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"VAT "<<left<<"| ";
	cout<<setw(18)<<left<<VAT<<setw(8)<<right<<"|"<<endl;
	cout<<" ----------------------------------------------"<<endl;
}

float LearningTools::caculated()
{
	float a=prices + prices*VAT + 5000;
	return  a;
}

istream &operator>>(istream &is, LearningTools &p)
{
	cout<<setw(38)<<"----------------------------------"<<endl;
	cout<<endl;
	cout<<setw(14)<<"Enter ID: ";
	is>>p.id;
	is.ignore();
	cout<<setw(16)<<"Enter Name: ";
	getline(is, p.name);
	cout<<setw(16)<<"Enter Type: ";
	getline(is, p.type);
	cout<<setw(18)<<"Enter Prices: ";
	is>>p.prices;
	is.ignore();
	cout<<setw(18)<<"Enter Source: ";
	getline(is, p.source);
	cout<<setw(29)<<"Enter dateOfManufacture: ";
	getline(is, p.dateOfManufacture);
	cout<<setw(22)<<"Enter importDate: ";
	getline(is, p.importDate);
	cout<<setw(22)<<"Enter VAT: ";
	is>>p.VAT;
	is.ignore();
	return is;
}

ostream &operator<<(ostream &os, LearningTools &p)
{
	cout<<" ----------------------------------------------"<<endl;
	cout<<"| "<<setw(18)<<left<<"ID "<<left<<"| ";
	os<<setw(18)<<left<<p.id<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Name "<<left<<"| ";
	os<<setw(20)<<left<<p.name<<setw(6)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Type "<<left<<"| ";
	os<<setw(18)<<left<<p.type<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Prices "<<left<<"| ";
	os<<setw(18)<<left<<p.prices<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Source "<<left<<"| ";
	os<<setw(18)<<left<<p.source<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"DateOfManufacture "<<left<<"| ";
	os<<setw(18)<<left<<p.dateOfManufacture<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"ImportDate "<<left<<"| ";
	os<<setw(18)<<left<<p.importDate<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"VAT "<<left<<"| ";
	os<<setw(18)<<left<<p.VAT<<setw(8)<<right<<"|"<<endl;
	cout<<" ----------------------------------------------"<<endl;
	return os;
}

class Technological : public Items
{
	public:
		float VAT;
		float maintenance;
		string electricity;
		Technological():Items()
		{
			this->type="Technological";
			this->VAT = 0;
			this->maintenance = 0;
			this->electricity = "";
		}
		Technological(int id,string name,int quantity,float prices,string source,string dateOfManufacture,string importDate,float VAT, float maintenance, string electricity):Items(id,name,quantity,prices,source,dateOfManufacture,importDate)
		{
			this->id=id;
			this->name=name;
			this->quantity=quantity;
			this->prices=prices;
			this->source=source;
			this->dateOfManufacture=dateOfManufacture;
			this->importDate=importDate;
			this->type="Technological";
			this->VAT=VAT;
			this->maintenance=maintenance;
			this->electricity=electricity;
		}
		void input();
		void output();
		float caculated();
		friend istream &operator>>(istream &is, Technological &p);
		friend ostream &operator<<(ostream &os, Technological &p);
};
void Technological::input()
{
	cout<<endl;
	cout<<" _________________________________________________"<<endl;
	cout<<"|                                                 |"<<endl;
	cout<<"|       T  E  C  H  N  O  L  O  G  I  C  A  L     |"<<endl;
	cout<<"|_________________________________________________|"<<endl;
	cout<<endl<<endl;
	Items::input();
	cout<<setw(15)<<"Enter VAT: ";
	cin>>VAT;
	cin.ignore();
	cout<<setw(23)<<"Enter Maintenance: ";
	cin>>maintenance;
	cin.ignore();
	cout<<setw(23)<<"Enter Electricity: ";
	getline(cin,electricity);
}

void Technological::output()
{
	Items::output();

	cout<<fixed;
	cout.precision(2);

	cout<<"| "<<setw(18)<<left<<"Calculated "<<left<<"| ";
	cout<<setw(18)<<left<<Technological::caculated()<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"VAT "<<left<<"| ";
	cout<<setw(18)<<left<<VAT<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Electricity "<<left<<"| ";
	cout<<setw(18)<<left<<electricity<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Maintenance "<<left<<"| ";
	cout<<setw(18)<<left<<maintenance<<setw(8)<<right<<"|"<<endl;
	cout<<" ----------------------------------------------"<<endl;
}

float Technological::caculated()
{
	float a =prices+prices*VAT + maintenance  + 15000;
	return  a;
}

istream &operator>>(istream &is, Technological &p)
{
	cout<<setw(38)<<"----------------------------------"<<endl;
	cout<<endl;
	cout<<setw(14)<<"Enter ID: ";
	is>>p.id;
	is.ignore();
	cout<<setw(16)<<"Enter Name: ";
	getline(is, p.name);
	cout<<setw(16)<<"Enter Type: ";
	getline(is, p.type);
	cout<<setw(18)<<"Enter Prices: ";
	is>>p.prices;
	is.ignore();
	cout<<setw(18)<<"Enter Source: ";
	getline(is, p.source);
	cout<<setw(29)<<"Enter dateOfManufacture: ";
	getline(is, p.dateOfManufacture);
	cout<<setw(22)<<"Enter importDate: ";
	getline(is, p.importDate);
	cout<<setw(22)<<"Enter VAT: ";
	is>>p.VAT;
	is.ignore();
	cout<<setw(22)<<"Enter Maintenance: ";
	is>>p.maintenance;
	is.ignore();
	cout<<setw(22)<<"Enter Electricity: ";
	getline(is,p.electricity);
	return is;
}

ostream &operator<<(ostream &os, Technological &p)
{
	cout<<" ----------------------------------------------"<<endl;
	cout<<"| "<<setw(18)<<left<<"ID "<<left<<"| ";
	os<<setw(18)<<left<<p.id<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Name "<<left<<"| ";
	os<<setw(20)<<left<<p.name<<setw(6)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Type "<<left<<"| ";
	os<<setw(18)<<left<<p.type<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Prices "<<left<<"| ";
	os<<setw(18)<<left<<p.prices<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Source "<<left<<"| ";
	os<<setw(18)<<left<<p.source<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"DateOfManufacture "<<left<<"| ";
	os<<setw(18)<<left<<p.dateOfManufacture<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"ImportDate "<<left<<"| ";
	os<<setw(18)<<left<<p.importDate<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"VAT "<<left<<"| ";
	os<<setw(18)<<left<<p.VAT<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Maintenance "<<left<<"| ";
	os<<setw(18)<<left<<p.maintenance<<setw(8)<<right<<"|"<<endl;
	cout<<"| "<<setw(18)<<left<<"Electricity "<<left<<"| ";
	os<<setw(18)<<left<<p.electricity<<setw(8)<<right<<"|"<<endl;
	cout<<" ----------------------------------------------"<<endl;
	return os;
}
struct list_buy
{
	public:
		int ID;
		int Quantity;
		void in()
		{
			cout<<"Enter the ID you want to buy:";
			cin>>ID;
			cout<<"Enter Quantity :";
			cin>>Quantity;
			cin.ignore();
		}
};
struct Acc
{
	public:
		string name;
		string account;
		string pass;
		int surplus;
		void set_Acc(string name, string account, string pass, int surplus)
		{
			this->name=name;
			this->account=account;
			this->pass=pass;
			this->surplus=surplus;
		}
};
class SalesManagementSystem
{
	public:
		Items *a[1000];
		int n;
		SalesManagementSystem()
		{
			this->n = 0;
		}
		void inputItems()
		{
			int chon, i;
			while( n < 1000 )
			{
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<endl;
				cout<<setw(61)<<"W  E  L  C  O  M  E"<<endl;
				cout<<endl;
				cout<<endl;
				cout<<setw(61)<<"        	 T  O"<<endl;
				cout<<endl;
				cout<<endl;
				cout<<setw(60)<<" S  A  L  E  S"<<endl;
				cout<<endl;
				cout<<endl;
				cout<<setw(72)<<" S  Y  S  T  E  M  S"<<endl;
				cout<<endl;
				cout<<setw(87)<<" ----------------------------------------------------------- "<<endl;
				cout<<endl;
				cout<<endl;
				cout<<setw(61)<<" >> [1] HouseWares"<<endl;
				cout<<endl;
				cout<<setw(65)<<" >> [2] Learning Tools"<<endl;
				cout<<endl;
				cout<<setw(64)<<" >> [3] Technological"<<endl;
				cout<<endl;
				cout<<setw(55)<<" >> [4] Exit"<<endl;
				cin>>chon;
				cin.get();
				switch(chon)
				{
					case 1:
						system ("cls");
						a[n]=new HouseWares();
						break;
					case 2:
						system ("cls");
						a[n]=new LearningTools();
						break;
					case 3:
						system ("cls");
						a[n]=new Technological();
						break;
					default:
						system ("cls");
						return;
				}
				a[n++]->input();
			}
		}
		//tach du lieu tung dong trong line
		vector<string> split (const string &s, char delim)
		{
			vector<string> result;
			stringstream ss (s);
			string item;
			while (getline (ss, item, delim))
			{
				result.push_back (item);
			}

			return result;
		}
		//ham lay du lieu tu file
		void inputByFile()
		{
			string filename("DATA.txt");
			string line;
			ifstream input_file(filename);
			if (!input_file.is_open())
			{
				cerr << "Could not open the file - '"
				     << filename << "'" << endl;
				exit(0);
			}
			getline(input_file, line);
			int end= stoi(line);
			for(int i=0; i<end; i++)
			{
				getline(input_file, line);
				char delimiter = ',';
				vector<string> v = split (line, delimiter);

				string type = v[0];

				int id = stoi(v[1]);

				string name=v[2];

				int quantity=stoi(v[3]);

				float prices= stof(v[4]);

				string source = v[5];

				string dateOfManufacture= v[6];

				string importDate=v[7];

				if(type=="House Wares")
				{
					//int id,string name,float prices,string source,string dateOfManufacture,string importDate,float VAT, bool liquidationGoods

					float VAT = stof(v[8]);
					bool liquidationGoods;
					if(v[9]=="0")
						liquidationGoods = true;
					else
						liquidationGoods = false;
					//cout<<id<<"   "<<name<<"   "<<prices<<"   "<<source<<"   "<<dateOfManufacture<<"   "<<importDate<<"   "<<VAT<<"   "<<liquidationGoods<<endl;
					a[n++] = new HouseWares(id,name,quantity,prices,source,dateOfManufacture,importDate,VAT,liquidationGoods);
				}
				if(type=="Learning Tools")
				{
					//int id,string name,float prices,string source,string dateOfManufacture,string importDate,float VAT

					float VAT = stof(v[8]);
					a[n++] = new LearningTools(id,name,quantity,prices,source,dateOfManufacture,importDate,VAT);
				}
				if(type=="Technological")
				{
					//int id,string name,float prices,string source,string dateOfManufacture,string importDate,float VAT, float maintenance, string electricity
					float VAT = stof(v[8]);
					float maintenance=stof(v[9]);
					string electricity= v[10];
					a[n++] = new Technological(id,name,quantity,prices,source,dateOfManufacture,importDate,VAT,maintenance,electricity);
				}
			}
			input_file.close();
		}
		//xuat cac mat hang
		void outputItems()
		{
			for(int i=0; i<n; i++)
			{
				a[i]->output();
			}
		}
		//sap xep theo gia tang dan
		void sortAscendingByPrice()
		{
			cout<<"Sort Ascending By Price"<<endl;
			cout<<"---------------------------------------------------------"<<endl;
			for(int i=0; i<n-1; i++)
			{
				for(int j=i+1; j<n; j++)
				{
					if(a[i]->caculated()>a[j]->caculated())
					{
						Items *t=a[i];
						a[i]=a[j];
						a[j]=t;
					}
				}
			}
		}
		//sap xep theo gia giam dan
		void sortDescendingByPrice()
		{
			cout<<"Sort Descending By Price"<<endl;
			cout<<"---------------------------------------------------------"<<endl;
			for(int i=0; i<n-1; i++)
			{
				for(int j=i+1; j<n; j++)
				{
					if(a[i]->caculated()<a[j]->caculated())
					{
						Items *t=a[i];
						a[i]=a[j];
						a[j]=t;
					}
				}
			}
		}
		int count(Items *a[], int n)
		{
			int s=0;
			for(int i=0; i<n; i++)
			{
				if(a[i]->type=="Technological"&&a[i+1]->type!="Technological")
				{	
					s=i+1;
				}
			}
			return s;
		}
		//sap xep theo nhom: cong nghe->dung cu hoc tap-> gia dung
		void sortByGroup()
		{

			for(int i=0; i<n-1; i++)
			{
				for(int j=i+1; j<n; j++)
				{
					if(a[i]->type!="Technological"&&a[j]->type=="Technological")
					{
						Items *t=a[i];
						a[i]=a[j];
						a[j]=t;
					}
				}
			}
			for(int i=count(a,n); i<n-1; i++)
			{
				for(int j=i+1; j<n; j++)
				{
					if(a[i]->type=="House Wares"&&a[j]->type=="Learning Tools")
					{
						Items *t=a[i];
						a[i]=a[j];
						a[j]=t;
					}
				}
			}
		}
		void maxCaculated()
		{
			float max = a[0]->caculated();
			for(int i=1; i<n; i++)
			{
				if(a[i]->caculated() > max )
				{

					max = a[i]->caculated();
				}
			}
			cout<<"Max Calculated"<<endl;
			cout<<"---------------------------------------------------------"<<endl;
			for(int j=0; j<n; j++)
			{
				if(a[j]->caculated() == max)
				{

					a[j]->output();
				}
			}
		}
		void minCaculated()
		{
			float min = a[0]->caculated();
			for(int i=1; i<n; i++)
			{
				if(a[i]->caculated() < min)
				{
					min = a[i]->caculated();
				}
			}
			cout<<"Min Calculated"<<endl;
			cout<<"---------------------------------------------------------"<<endl;
			for(int i=0; i<n; i++)
			{
				if(a[i]->caculated() == min)
				{
					a[i]->output();
				}
			}
		}
		void searchByName()
		{
			bool result = false;
			string searchName;
			cout<<"Enter the name of the item you want to search for:";
			getline(cin,searchName);
			for(int i=0; i<n; i++)
			{
				transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
				string nameItems = a[i]->name;
				transform(nameItems.begin(), nameItems.end(), nameItems.begin(), ::tolower);
				if(nameItems==searchName)
				{
					a[i]->output();
					result = true;
				}
			}
			if(!result)
			{
				cout<<endl<<setw(72)<<"No results were found!!"<<endl;
			}
		}
		void searchByID()
		{
			bool result = false;
			int searchID;
			cout<<"Enter the ID of the item you want to search for:";
			cin>>searchID;
			cin.ignore();
			for(int i=0; i<n; i++)
			{
				if(a[i]->id==searchID)
				{
					a[i]->output();
					result = true;
				}
			}
			if(!result)
			{
				cout<<endl<<setw(72)<<"No results were found!!"<<endl;
			}
		}
		void searchByImportDate()
		{
			bool result = false;
			string searchImportDate;
			cout<<"Enter the Import Date of the item you want to search for:";
			getline(cin,searchImportDate);
			for(int i=0; i<n; i++)
			{
				if(a[i]->importDate==searchImportDate)
				{
					a[i]->output();
					result = true;
				}
			}
			if(!result)
			{
				cout<<endl<<setw(72)<<"No results were found!!"<<endl;
			}
		}
		void editInformation()
		{
			int number_edit;
			string searchName;
			cout<<"Enter the name of the item you want to search for:";
			getline(cin,searchName);
			for(int i=0; i<n; i++)
			{
				transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
				string nameItems = a[i]->name;
				transform(nameItems.begin(), nameItems.end(), nameItems.begin(), ::tolower);
				if(nameItems==searchName)
				{
					a[i]->output();
					number_edit = i;
				}
			}
			int chon;
			cout<<setw(87)<<" ----------------------------------------------------------- "<<endl;
			cout<<endl;
			cout<<endl;
			cout<<setw(68)<<" >> [1] HouseWares"<<endl;
			cout<<endl;
			cout<<setw(72)<<" >> [2] Learning Tools"<<endl;
			cout<<endl;
			cout<<setw(71)<<" >> [3] Technological"<<endl;
			cout<<endl;
			cout<<setw(62)<<" >> [4] Exit"<<endl;
			cin>>chon;
			cin.get();
			switch(chon)
			{
				case 1:
					a[number_edit]=new HouseWares();
					break;
				case 2:

					a[number_edit]=new LearningTools();
					break;
				case 3:
					a[number_edit]=new Technological();
					break;
				default:
					return;
			}
			a[number_edit]->input();
		}
		//ham copy du lieu file
		void copyFile(string fileOrigin, string fileCopy)
		{
			ifstream input_file(fileCopy);
			ofstream outfile;
			outfile.open(fileOrigin);

			string line;
			getline(input_file, line);
			int end= stoi(line);
			outfile<<end<<endl;
			for(int i=0; i<end; i++)
			{
				getline(input_file, line);
				outfile<<line<<endl;
			}
			input_file.close();
			outfile.close();
		}
		//Register Account

		void Register()
		{
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl;
			cout<<setw(65)<<"R   E   G   I   S   T   E   R"<<endl<<endl;
			cout<<setw(79)<<"---------------------------------------------------------"<<endl;
			string file_acc_name("User Account.txt");
			string line;
			string account;
			string password;
			string name;
			int surplus;
			bool result=true;
			do
			{
				cout<<"Enter your Name: ";
				getline(cin,name);
				cout<<"Enter Account: ";
				getline(cin,account);
				cout<<"Enter Password: ";
				getline(cin,password);

				cout<<"Enter Surplus: ";
				cin>>surplus;
				cin.ignore();

				ifstream input_file(file_acc_name);
				getline(input_file, line);
				int end= stoi(line);
				for(int i=0; i<end; i++)
				{
					getline(input_file, line);
					char delimiter = ',';
					vector<string> v = split (line, delimiter);

					string f_name=v[0];
					string f_account = v[1];
					string f_password= v[2];
					int f_surplus = stoi(v[3]);
					if(f_account==account)
					{
						result = true;
						cout<<"Your account is not valid, please re-enter!!"<<endl;
					}
					else
					{
						result = false;
					}

				}
				input_file.close();
			}
			while(result);

			string file_copy("temporary file.txt");
			ofstream outfile;
			outfile.open(file_copy);

			ifstream input_file(file_acc_name);
			getline(input_file, line);
			int end= stoi(line);
			outfile<<end+1<<endl;
			for(int i=0; i<end; i++)
			{
				getline(input_file, line);
				char delimiter = ',';
				vector<string> v = split (line, delimiter);

				string f_name=v[0];
				string f_account = v[1];
				string f_password= v[2];
				int f_surplus = stoi(v[3]);
				outfile<<f_name<<","<<f_account<<","<<f_password<<","<<f_surplus<<endl;
			}
			outfile<<name<<","<<account<<","<<password<<","<<surplus<<endl;
			//copy all du lieu tu file Register.txt(file luu tam thoi) sang User Account.txt(file goc)
			copyFile(file_acc_name,file_copy);
			cout<<"Sign Up Success!!!!"<<endl;
			input_file.close();
			outfile.close();
		}
		string signin(Acc &l_acc)
		{
			string file_account("User Account.txt");
			string line;

			string account;
			string password;
			string name;

			ifstream input_file(file_account);

			bool check = false;
			system("cls");
			cout<<endl<<endl<<endl<<endl<<endl;
			cout<<setw(59)<<" S    I    G    N    I    N"<<endl<<endl;
			cout<<setw(73)<<"-------------------------------------------------------"<<endl;
			cout<<"Account Private: ";
			getline(cin,account);
			cout<<"Password: ";
			getline(cin,password);

			getline(input_file, line);
			int end= stoi(line);
			for(int i=0; i<end; i++)
			{
				getline(input_file, line);
				char delimiter = ',';
				vector<string> v = split (line, delimiter);
				string f_name=v[0];
				string f_account = v[1];
				string f_password= v[2];
				int f_surplus = stoi(v[3]);

				if(account==f_account&&password==f_password)
				{
					l_acc.set_Acc(f_name,f_account,f_password,f_surplus);
					name=f_name;
					check = true;
				}

			}
			input_file.close();
			if(check)
			{
				cout<<"Successfully logged in - as "<<name<<endl;
				return account;
			}
			return "Error!!!!!\n";
		}
		void outlist()
		{
			cout<<"---------------------------------------------------------"<<endl;
			cout<<"| "<<setw(7)<<left<<"ID "<<left;
			cout<<"| "<<setw(25)<<left<<"Name "<<left;
			cout<<"| "<<setw(18)<<left<<"Price "<<left<<"|"<<endl;
			cout<<"---------------------------------------------------------"<<endl;
			for(int i=0; i<n; i++)
			{
				cout<<"| "<<setw(7)<<left<<a[i]->id<<left;
				cout<<"| "<<setw(25)<<left<<a[i]->name<<left;
				cout<<fixed;
				cout.precision(0);
				cout<<"| "<<setw(9)<<left<<a[i]->caculated()<<setw(9)<<" VND"<<left<<"|"<<endl;
				cout<<"---------------------------------------------------------"<<endl;
			}
		}
		void outlist(list_buy list[], int num)
		{
			cout<<"----------------------------------------------------------------------------------------"<<endl;
			cout<<"| "<<setw(7)<<left<<"ID "<<left;
			cout<<"| "<<setw(25)<<left<<"Name "<<left;
			cout<<"| "<<setw(18)<<left<<"Price "<<left;
			cout<<"| "<<setw(9)<<left<<"Quantity "<<left;
			cout<<"| "<<setw(18)<<left<<"Into money "<<left<<"|"<<endl;
			cout<<"----------------------------------------------------------------------------------------"<<endl;
			for(int i=0; i<num; i++)
			{
				if(check_location(list[i].ID)!=-1 && (list[i].Quantity <= a[check_location(list[i].ID)]->quantity))
				{
					cout<<"| "<<setw(7)<<left<<list[i].ID<<left;
					cout<<"| "<<setw(25)<<left<<a[check_location(list[i].ID)]->name<<left;
					cout<<fixed;
					cout.precision(0);
					cout<<"| "<<setw(9)<<left<<a[check_location(list[i].ID)]->caculated()<<setw(9)<<" VND"<<left;
					cout<<"| "<<setw(9)<<left<<list[i].Quantity<<left;
					cout<<"| "<<setw(9)<<left<<a[check_location(list[i].ID)]->caculated()*list[i].Quantity<<setw(9)<<" VND"<<left<<"|"<<endl;
					cout<<"----------------------------------------------------------------------------------------"<<endl;
				}
			}
		}
		int check_location(int id)
		{
			int numLn=-1;
			for(int i=0; i<n; i++)
			{
				if(id==a[i]->id)
					numLn=i;
			}
			if(numLn==-1)
			{
				cout<<"Wrong ID: '"<<id<<"'!!! --- Please Re-Enter ID"<<endl;
			}
			return numLn;
		}

		float totalMoney(list_buy list[], int num)
		{
			float	total_Money=0;
			for(int i=0; i<num; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(list[i].ID==a[j]->id)
					{
						total_Money += a[j]->caculated()*list[i].Quantity;
					}
				}
			}
			return total_Money;
		}
		bool checkQuantityAndBalance(Acc l_acc,list_buy list[], int num)
		{
			bool result = true;

			for(int i=0; i<num; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(list[i].ID==a[j]->id)
					{
						if(list[i].Quantity>a[j]->quantity )
						{
							result= false;
						}
					}
				}
			}
			if(totalMoney(list,num)>l_acc.surplus)
			{
				result= false;
			}

			return result;
		}
		void invoice(Acc l_acc,list_buy list[], int num)
		{
			if(checkQuantityAndBalance(l_acc,list,num))
			{

				ofstream outfile("Invoice.txt");
				float total_Money=0;
				outfile<<"\t\t\t   -----INVOICE----- "<<endl;

				time_t now = time(0);

				tm *ltm = localtime(&now);

				outfile<<"Customer name: "<<l_acc.name<<endl;
				outfile << "Day: "<<  ltm->tm_mday ;
				outfile<<"/" << 1 + ltm->tm_mon;
				outfile<< "/" << 1900 + ltm->tm_year << endl;
				outfile<< "Time: "<< 1 + ltm->tm_hour << ":";
				outfile<< 1 + ltm->tm_min << ":";
				outfile<< 1 + ltm->tm_sec << endl;
				outfile<<"| "<<setw(25)<<left<<"Name "<<left;
				outfile<<"| "<<setw(18)<<left<<"Price "<<left;
				outfile<<"| "<<setw(9)<<left<<"Quantity "<<left;
				outfile<<"| "<<setw(18)<<left<<"Into money "<<left<<"|"<<endl;
				outfile<<"-------------------------------------------------------------------------------"<<endl;
				for(int i=0; i<num; i++)
				{
					for(int j=0; j<n; j++)
					{
						if(list[i].ID==a[j]->id)
						{
							//xuat hoa don
							outfile<<"| "<<setw(25)<<left<<a[j]->name<<left;
							outfile<<fixed;
							outfile.precision(0);
							outfile<<"| "<<setw(9)<<left<<a[j]->caculated()<<setw(9)<<" VND"<<left;
							outfile<<"| "<<setw(9)<<left<<list[i].Quantity<<left;
							outfile<<"| "<<setw(9)<<left<<a[j]->caculated()*list[i].Quantity<<setw(9)<<" VND"<<left<<"|"<<endl;
							total_Money += a[j]->caculated()*list[i].Quantity;
							a[j]->quantity -= list[i].Quantity;
						}
					}
				}

				l_acc.surplus -= total_Money;
				outfile<<endl<<endl<<"TOTAL MONEY: "<<total_Money<<" VND.\t\t\t Staff: Group III OOP"<<endl<<endl<<endl;
				outfile<<setw(50)<<"\t\t----------SEE YOU AGAIN----------"<<endl;
				outfile.close();
				system("cls");
				cout<<"\tPlease open the file 'Invoice.txt' in the same folder to view the invoice."<<endl;
				cout<<"\tPress enter to continue....."<<endl;
				cin.ignore();
				system("cls");
			}
			else
			{
				system("cls");
				cout<<"\tThere was an error during checkout, please check your balance or item quantity!!"<<endl;
				cout<<"\tPress enter to continue....."<<endl;
				cin.ignore();
			}

		}
		void purchase()
		{
			Acc l_acc;
			string acccount_buy;
			list_buy list[100];
			int num=0;
			acccount_buy=signin(l_acc);
			if(acccount_buy!="Error!!!!!\n")
			{
				outlist();
				cout<<"Do you want to see detailed product information?"<<endl<<"[1] Yes | [2] No "<<endl;
				cout<<"Enter: ";
				int chon;
				cin>>chon;
				cin.ignore();
				if(chon == 1)
				{
					system("cls");
					outputItems();
				}
				chon=1;
				while(chon==1)
				{
					list[num++].in();
					cout<<"Again?"<<endl<<"[1] Yes | [2] No ";
					cout<<endl<<"Enter: ";
					cin>>chon;
				}
				system("cls");
				cout<<setw(71)<<"List of items you have selected and are eligible for"<<endl<<endl;
				outlist(list,num);
				chon=0;
				cout<<"Payment confirmation"<<endl<<"[1] Yes | [2] No ";
				cout<<endl<<"Enter: ";
				cin>>chon;
				cin.ignore();
				if(chon == 1)
				{
					invoice(l_acc,list,num);
				}

				else return;
			}
			else
			{
				cout<<"Login failed!!! "<<endl<<"[1] Register | [2] Exit ";
				cout<<endl<<"Enter: ";
				int chon;
				cin>>chon;
				cin.ignore();
				if(chon==1)
				{
					Register();
				}
				else
					return;

			}
			return;
		}
};

int main()
{
start:
	SalesManagementSystem a;
	int condition=0;
	while(condition==0)
	{
		//	a.inputByFile();
		int number_menu;
		bool number_exit= false;
		cout<<endl<<endl<<endl<<endl<<endl;
		cout<<setw(68)<<" G    R    O    U    P    III "<<endl;
		cout<<endl<<endl;
		cout<<setw(69)<<" P    R    O    J    E    C    T"<<endl<<endl<<endl<<endl;
		cout<<setw(74)<<"------------------------------------------"<<endl;
		cout<<endl<<endl<<endl;
		cout<<setw(53)<<right<<">> [1] Input"<<endl;
		cout<<setw(52)<<right<<">> [2] Sort"<<endl;
		cout<<setw(57)<<right<<">> [3] Max - Min"<<endl;
		cout<<setw(54)<<right<<">> [4] Search"<<endl;
		cout<<setw(64)<<right<<">> [5] Edit information"<<endl;
		cout<<setw(56)<<right<<">> [6] Purchase"<<endl;
		cout<<setw(67)<<right<<">> [7] Register an account"<<endl;
		cout<<setw(56)<<right<<">> [8] Out List"<<endl;
		cout<<setw(53)<<right<<">> [9] Exit "<<endl;
		cin>>number_menu;
		cin.ignore();
		switch(number_menu)
		{
			case 1:
				int number_in;
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(56)<<" I   N   P   U   T"<<endl<<endl;
				cout<<setw(68)<<"------------------------------------------"<<endl;
				cout<<endl<<endl<<endl;
				cout<<setw(56)<<right<<">> [1] Input By File"<<endl<<endl<<endl;
				cout<<setw(55)<<right<<">> [2] Manual Input"<<endl<<endl<<endl;
				cout<<setw(55)<<right<<">> [3] Exit Options"<<endl;
				cin>>number_in;
				cin.ignore();
				switch(number_in)
				{
					case 1:
						system("cls");
						a.inputByFile();
						break;
					case 2:
						system("cls");
						a.inputItems();
						break;
					default:
						system("cls");
						break;
				}
				break;
			case 2:
				int number_sort;
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(56)<<" S    O    R    T"<<endl<<endl;
				cout<<setw(68)<<"------------------------------------------"<<endl;
				cout<<endl<<endl<<endl;
				cout<<setw(58)<<right<<">> [1] Sort Ascending By Price"<<endl<<endl<<endl;
				cout<<setw(59)<<right<<">> [2] Sort Descending By Price"<<endl<<endl<<endl;
				cout<<setw(48)<<right<<">> [3] Sort By Group"<<endl<<endl<<endl;
				cout<<setw(47)<<right<<">> [4] Exit Options"<<endl;
				cin>>number_sort;
				cin.ignore();
				switch(number_sort)
				{
					case 1:
						system("cls");
						a.sortAscendingByPrice();
						a.outputItems();
						break;
					case 2:
						system("cls");
						a.sortDescendingByPrice();
						a.outputItems();
						break;
					case 3:
						system("cls");
						a.sortByGroup();
						a.outputItems();
						break;
					default:
						system("cls");
						break;
				}
				break;
			case 3:
				int number_maxmin;
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(59)<<" M   A   X  -  M   I   N"<<endl<<endl;
				cout<<setw(68)<<"------------------------------------------"<<endl;
				cout<<endl<<endl<<endl;
				cout<<setw(58)<<right<<">> [1] Max By Calculated"<<endl<<endl<<endl;
				cout<<setw(58)<<right<<">> [2] Min By Calculated"<<endl<<endl<<endl;
				cout<<setw(53)<<right<<">> [3] Exit Options"<<endl;
				cin>>number_maxmin;
				cin.ignore();
				switch(number_maxmin)
				{
					case 1:
						system("cls");
						a.maxCaculated();
						break;
					case 2:
						system("cls");
						a.minCaculated();
						break;
					default:
						system("cls");
						break;
				}
				break;
			case 4:
				int number_search;
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(57)<<" S   E   A   R   C   H"<<endl<<endl;
				cout<<setw(68)<<"------------------------------------------"<<endl;
				cout<<endl<<endl<<endl;
				cout<<setw(58)<<right<<">> [1] Search By Name"<<endl<<endl<<endl;
				cout<<setw(56)<<right<<">> [2] Search By ID"<<endl<<endl<<endl;
				cout<<setw(65)<<right<<">> [3] Search By Import Date"<<endl<<endl<<endl;
				cout<<setw(56)<<right<<">> [4] Exit Options"<<endl;
				cin>>number_search;
				cin.ignore();
				switch(number_search)
				{
					case 1:
						system("cls");
						cout<<endl<<endl<<endl<<endl<<endl;
						cout<<setw(58)<<" S   E   A   R   C   H"<<endl<<endl;
						cout<<setw(68)<<"------------------------------------------"<<endl;
						cout<<endl<<endl<<endl;
						a.searchByName();
						break;
					case 2:
						system("cls");
						cout<<endl<<endl<<endl<<endl<<endl;
						cout<<setw(58)<<" S   E   A   R   C   H"<<endl<<endl;
						cout<<setw(68)<<"------------------------------------------"<<endl;
						cout<<endl<<endl<<endl;
						a.searchByID();
						break;
					case 3:
						system("cls");
						cout<<endl<<endl<<endl<<endl<<endl;
						cout<<setw(58)<<" S   E   A   R   C   H"<<endl<<endl;
						cout<<setw(68)<<"------------------------------------------"<<endl;
						cout<<endl<<endl<<endl;
						a.searchByImportDate();
						break;
					default:
						system("cls");
						break;
				}
				break;
			case 5:
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(70)<<" E  D  I  T  ---  I  N  F  O  R  M  A  T  I  O  N"<<endl<<endl;
				cout<<setw(79)<<"----------------------------------------------------------------"<<endl;
				cout<<endl<<endl<<endl;
				a.editInformation();
				break;
			case 6:
				a.purchase();
				a.maxCaculated();
				system("cls");
				break;
			case 7:
				a.Register();
				break;
			case 8:
				system("cls");
				cout<<endl<<endl<<endl<<endl<<endl;
				cout<<setw(63)<<" O   U   T  ---  L   I   S   T"<<endl<<endl;
				cout<<setw(68)<<"------------------------------------------"<<endl;
				cout<<endl<<endl<<endl;
				a.outputItems();
				break;
			case 9:
				number_exit= true;
				break;
			default:
				cout<<"System List Of Only 9 Functions, Please Re-Enter!!!!"<<endl;
				break;
		}
		if(number_exit ==false )
		{

			cout<<endl<<endl<<endl<<endl<<endl;
			cout<<setw(68)<<" G    R    O    U    P    III "<<endl;
			cout<<endl<<endl;
			cout<<setw(69)<<" P    R    O    J    E    C    T"<<endl<<endl<<endl<<endl;
			cout<<setw(74)<<"------------------------------------------"<<endl;
			cout<<endl<<endl<<endl;
			cout<<setw(68)<<"Do You Want To Go Back To The Menu:"<<endl<<setw(41)<<">> [1] Yes"<<endl<<setw(40)<<">> [2] No"<<endl;
			cin>>condition;
		}
		if(condition == 1)
		{

			condition=0;
			system("cls");
		}
		else
		{
			condition = 1;
			system("cls");
			cout<<endl<<endl<<right<<setw(60)<<"\t\t------------------- P R O G R A M M I N G  B Y  G R O U P  3 ---------------------"<<endl;
		}

	}
	return 0;
}