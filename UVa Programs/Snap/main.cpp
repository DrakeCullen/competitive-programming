#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	while(n--) {
		string jaup, jadown, joup, jodown;
		int count = 0;
		cin.ignore();
		cin>>jadown>>jodown;
		while(count <= 1000) {
			if(jadown.empty()) {
				reverse(jaup.begin(), jaup.end());
				jadown = jaup;
				jaup = "";
			}
			if(jodown.empty()) {
				reverse(joup.begin(), joup.end());
				jodown = joup;
				joup = "";
			}
			jaup.insert(0,1,jadown[0]);
			joup.insert(0,1,jodown[0]);
			jadown = jadown.substr(1);
			jodown = jodown.substr(1);
			if(jaup[0] == joup[0]) {
				if(random()/141%2 == 0) {
					joup += jaup;
					jaup = joup;
					joup = "";
					cout<<"Snap! for Jane: "<<jaup<<endl;
					if(joup.size() == 0 && jodown.size() == 0) break;
				} else {
					jaup += joup;
					joup = jaup;
					jaup = "";
					cout<<"Snap! for John: "<<joup<<endl;
					if(jaup.size() == 0 && jadown.size() == 0) break;
				}
			}
			count++;
		}
		if(joup.size() == 0 && jodown.size() == 0) cout<<"Jane wins."<<endl<<endl;
		else if(jaup.size() == 0 && jadown.size() == 0) cout<<"John wins."<<endl<<endl;
		else cout<<"Keeps going and going ..."<<endl<<endl;
	}
	
	return 0;
}





