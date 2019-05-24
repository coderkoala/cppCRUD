#include<iostream>
#include<vector>
#include<sqlite3.h>
#include"sqlite_orm.h"
#include<string>
#define log(x) std::cout<<x<<endl;

class coords{

	public:
		coords( int a, int b, int c) : x(a),y(b),z(c)
			{

			}

	
	friend std::ostream& operator<<(std::ostream& out, const coords &param);

	private:
		int x,y,z;		
		
};


std::ostream& operator<<(std::ostream& out, const coords &param)
{
    out<<param.x<<","<<param.y<<","<<param.z<<std::endl;
}

static int callback(void* data, int argc, char** argv, char** azColName) 
{ 
	    int i; 
	        fprintf(stderr, "%s: ", (const char*)data); 
		  
		    for (i = 0; i < argc; i++) { 
			            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
				        } 
		      
		        printf("\n"); 
			    return 0; 
} 

void insert(const auto &arg)
{
	sqlite3* DB;
	sqlite3_open("example.db", &DB);
	std:: string a(arg[1]), b(arg[2]), c(arg[3]), d(arg[4]);
	std::string query = "insert into ramesh (fname, lname, email, phone) values (\'" + a + "\',\'" + b + "\',\'" + c + "\',\'" + d + "\');";	

//	std::cout<<query<<std::endl<<std::endl;
	sqlite3_exec(DB, query.c_str(), NULL, 0, 0);

	sqlite3_close(DB);
}

int main(int argc, char** argv){
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("example.db", &DB);
	if(exit){
		std::cout<<"Exited due to: "<<sqlite3_errmsg(DB)<<std::endl;
		return 0;
		
	}
	else std::cout<<"Database opened successfully\n\n";
	if(argc == 5)
	{
		insert(argv);
	}
	std::string query = "Select * from Ramesh";
	sqlite3_exec(DB, query.c_str(), callback, 0, 0);
	sqlite3_close(DB);
	//std::vector<coords> cords;
	//cords.push_back(coords(1,2,3));
	//cords.push_back(coords(5,6,7));
	
	//for(coords v : cords)
	//	std::cout<<v;
	std::cout<<std::endl<<"Database closed successfully"<<std::endl;
	std::cin.get();

	return 0;
}
