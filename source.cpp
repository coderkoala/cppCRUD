#include<iostream>
#include<vector>
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
	
	std::vector<coords> cords;
	cords.push_back(coords(1,2,3));
	cords.push_back(coords(5,6,7));
	
	for(coords v : cords)
		std::cout<<v;
	std::cin.get();

	return 0;
}
