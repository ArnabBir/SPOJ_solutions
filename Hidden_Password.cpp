#include<iostream>
#include <algorithm>
using namespace std;

int convertBit(char bit){
    if(bit == '1')
        return 1;
    else return 0;
 }

string toBinary(const int &integer,int base=10)
{
    if (integer==0) return string("0");
    string a;
    int start, digits, piece;
    //count digits
    digits=0;
    piece=((integer<0)? 0-integer : integer);
    while( piece > 0 )
    {
        piece-= (piece%base);
        piece/=base;
        digits++;
    }
    start=((integer<0)? 1 : 0);
    a.resize(digits+start,' ');//allocate memory only once
    if (integer<0) a[0]='-';
    piece=((integer<0)? 0-integer : integer);
    for(int i=0;  piece > 0; i++ )
    {
        a[ digits+start-i-1] = (piece%base)+48;
        piece-= (piece%base);
        piece/=base;
    }
    return a;
}

int toDecimal(char num[]){
    int dec = 0, rem, base = 1;
    for(int i = 0; i < 64; ++i)
    {
        rem = convertBit(num[i]);
        dec = dec + rem * base;
        base = base * 2;
    }
    return dec;
}

int get_a(char subcipher[]){
    char deciphered[6];
	for(int i = 0; i < 6; ++i){
		int ascii = subcipher[i];
		string binary = toBinary(ascii, 2);
		reverse(binary.begin(), binary.end());
		deciphered[i] = binary[i % 6];
	}
	return toDecimal(deciphered);
}

int get_b(char subcipher[]){
    char deciphered[6];
	for(int i = 0; i < 6; ++i){
		int ascii = subcipher[i];
		string binary = toBinary(ascii, 2);
		reverse(binary.begin(), binary.end());
		deciphered[i] = binary[(i + 3) % 6];
	}
	return toDecimal(deciphered);
}

int main(){
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int * a = new int[n];
		int * b = new int[n];
		char cipher [n][6];
		char * key = new char[64];
		for(int i = 0; i < n; ++i){
				cin>>cipher[i];
		}
		cin>>key;

		for(int i =0; i < n; ++i){
				cout<<key[get_a(cipher[i])]<<key[get_b(cipher[i])];
		}
		cout<<endl;
	}
	return 0;
}
