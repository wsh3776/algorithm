#include <iostream>

using namespace std;

int main() {
	// freopen函数模版    
	#ifdef ONLINE_JUDGE
	#else
	    freopen("in.txt","r",stdin);
	    //freopen("out.txt","w",stdout);
	#endif
	
	int a;
	scanf("%d", &a);

	auto t = a + 100;
	cout << "a = " << a << "," <<" t = " << t << endl;

	return 0;
}

