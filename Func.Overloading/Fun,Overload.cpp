#include <iostream>
#include <cmath>
using namespace std;

class Vector {
	private:
		int i, j, k;
		double mag;
	public:
		Vector(){
			i=0;
			j=0;
			k=0;
			mag=0;
		}
		Vector(int a, int b, int c){
			i = a;
			j = b;
			k = c;
			mag = sqrt(i*i + j*j + k*k);
		}
		bool operator == (Vector A){
			return i==A.i && j==A.j && k==A.k;
		}
		bool operator != (Vector A){
			return i!=A.i || j!=A.j || k!=A.k;
		}
		bool operator < (Vector A){
			return mag < A.mag;
		}
		bool operator <= (Vector A){
			return mag <= A.mag;
		}
		bool operator > (Vector A){
			return mag > A.mag;
		}
		bool operator >= (Vector A){
			return mag >= A.mag;
		}
		void display(){
			cout<<i<<"i + "<<j<<"j + "<<k<<"k"<<endl;
		}
};

int main(){
	int a, b, c;
	cout<<"Enter i for vector 1: ";
	cin>>a;
	cout<<"Enter j for vector 1: ";
	cin>>b;
	cout<<"Enter k for vector 1: ";
	cin>>c;
	Vector V1(a, b, c);
	cout<<"Enter i for vector 2: ";
	cin>>a;
	cout<<"Enter j for vector 2: ";
	cin>>b;
	cout<<"Enter k for vector 2: ";
	cin>>c;
	Vector V2(a, b, c);

	cout<<"V1: ";
	V1.display();
	cout<<"V2: ";
	V2.display();

	cout<<"V1 == V2: "<<(V1==V2)<<endl;
	cout<<"V1 != V2: "<<(V1!=V2)<<endl;
	cout<<"V1 < V2: "<<(V1<V2)<<endl;
	cout<<"V1 <= V2: "<<(V1<=V2)<<endl;
	cout<<"V1 > V2: "<<(V1>V2)<<endl;
	cout<<"V1 >= V2: "<<(V1>=V2)<<endl;

	return 0;
}
