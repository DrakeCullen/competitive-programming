#include <bits/stdc++.h>

using namespace std;

int main() {
	//Part 1
	/*
	int count = 0;
	string inp = "k";
	while(true) {
		bool byr, iyr, eyr, hgt, hcl, ecl, pid, cid;
		byr=iyr=eyr=hgt=hcl=ecl=pid=cid=false;
		while(getline(cin,inp)) {;
			if(inp.empty()) break;
			if(inp.find("byr") != string::npos) byr = true;
			if(inp.find("iyr") != string::npos) iyr = true;
			if(inp.find("eyr") != string::npos) eyr = true;
			if(inp.find("hgt") != string::npos) hgt = true;
			if(inp.find("hcl") != string::npos) hcl = true;
			if(inp.find("ecl") != string::npos) ecl = true;
			if(inp.find("pid") != string::npos) pid = true;
		}
		if(iyr && byr && eyr && hgt && hcl && ecl && pid) count++;
		cout<<count<<endl;
	}
	*/
	
	int count = 0;
	string inp = "k", temp;
	while(true) {
		bool byr, iyr, eyr, hgt, hcl, ecl, pid, cid;
		byr=iyr=eyr=hgt=hcl=ecl=pid=cid=false;
		while(getline(cin,inp)) {;
			if(inp.empty()) break;
			stringstream ss(inp);
			while(ss>>temp) {
				
			}
			if(inp.find("byr") != string::npos) byr = true;
			if(inp.find("iyr") != string::npos) iyr = true;
			if(inp.find("eyr") != string::npos) eyr = true;
			if(inp.find("hgt") != string::npos) hgt = true;
			if(inp.find("hcl") != string::npos) hcl = true;
			if(inp.find("ecl") != string::npos) ecl = true;
			if(inp.find("pid") != string::npos) pid = true;
		}
		if(iyr && byr && eyr && hgt && hcl && ecl && pid) count++;
		cout<<count<<endl;
	}
	return 0;
}





