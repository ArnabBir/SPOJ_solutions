#include <bits/stdc++.h>

using namespace std;

string subtract_big(string a, string b){

	int carry = 0;
	string s, result;

	for(int i = 0; i < b.size(); ++i){

		s += (char)(a[a.size() - i - 1] - b[b.size() - i -1] - carry + '0');

		if(s[i] < '0'){

			s[i] += 10;
			carry = 1;
		}
		else	carry = 0;
	}

	for(int i = b.size(); i < a.size(); ++i){

		s += (char)(a[a.size() - i - 1] - carry);
		//cout<<s<<" ";
		if(s[i] < '0'){

			s[i] += 10;
			carry = 1;
		}
		else	carry = 0;
	}

	int zp = s.size() - 1;

	while(s[zp] == '0' && zp > 0)	--zp;
	
	result = s.substr(0, zp+1);
	reverse(result.begin(), result.end());

	return result;
}

string add_big(string a, string b){

	int carry = 0;
	string s, result;

	for(int i = 0; i < b.size(); ++i){

		s += (char)(a[a.size() - i - 1] + b[b.size() - i -1] + carry - '0');

		if(s[i] > '9'){

			carry = (s[i] - '0') / 10;
			s[i] = (char)((s[i] - '0') % 10 + '0');
		}
		else	carry = 0;
	}

	for(int i = b.size(); i < a.size(); ++i){

		s += (char)(a[a.size() - i - 1] + carry);

		if(s[i] > '9'){

			carry = (s[i] - '0') / 10;
			s[i] = (char)((s[i] - '0') % 10 + '0');
		}
		else	carry = 0;
	}

	if(carry > 0)	s += (char)(carry + '0');

	int zp = s.size() - 1;

	while(s[zp] == '0' && zp > 0)	--zp;
	
	result = s.substr(0, zp+1);
	reverse(result.begin(), result.end());

	return result;
}

string divide_2_big(string s){

	string d;
	int carry = 0, divisor, zp = 0;

	for(int i = 0; i < s.size(); ++i){
		//cout<<"s[i] = "<<s[i]<<endl;	
		divisor = (int)((int)(s[i] - '0') + carry * 10);
		d += (char)( divisor / 2 + '0');
		//cout<<"d = "<<d<<endl;
		carry = divisor % 2;
	}

	if(d.size() == 1)	return d;
	else{
		while(d[zp] == 0 && zp < d.size()-1)	++zp;
		return d.substr(zp, d.size()-zp);
	}
}

int main(){

	int T;
	string inp, diff, sbtr, a, b;

	T = 10;

	while(T--){

		cin>>inp>>diff;
		//cout<<subtract_big(inp, diff)<<" ";
		if(inp == diff){

			a = inp;
			b = "0";
		}
		else{
			inp = add_big(inp, diff);
			//cout<<"add = "<<inp<<endl;
			//cout<<divide_2_big(inp)<<endl;
			inp = divide_2_big(inp);
			b = subtract_big(inp, diff);
			a = add_big(inp, "0");
		}
		cout<<a<<endl<<b<<endl;
	}

	return 0;
}
