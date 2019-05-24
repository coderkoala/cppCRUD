#include<iostream>
#include<vector>
#include<sqlite3.h>
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


int main(){
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("example.db", &DB);
	if(exit){
		std::cout<<"Exited due to: "<<sqlite3_errmsg(DB)<<std::endl;
		return 0;
		
	}
	else std::cout<<"Database opened successfully"<<std::endl;
	sqlite3_close(DB);
	std::vector<coords> cords;
	cords.push_back(coords(1,2,3));
	cords.push_back(coords(5,6,7));
	
	for(coords v : cords)
		std::cout<<v;
	std::cin.get();

	return 0;
}
