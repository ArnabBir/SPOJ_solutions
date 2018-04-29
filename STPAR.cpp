#include <bits/stdc++.h>

using namespace std;

int main(){

	int N, scan;
	bool flag;

	while(true){

		cin>>N;
		if(N == 0)	break;

		flag = true;
		queue<int> q;
		stack<int> s;

		for(int i = 0; i < N; ++i){

			cin>>scan;
			q.push(scan);
		}

		int count = 1;

		while(!q.empty() /*|| !s.empty()*/){
			if(!q.empty()){


				if(q.front() == count){
					q.pop();
					++count;
				}
				else if(!s.empty()){
					
					if(s.top() == count){
						s.pop();
						++count;
					}
					else{

						if(s.top() < q.front()){
							
							flag = false;
							break;
						}
						else{
						
							s.push(q.front());
							q.pop();
						}
					}
				}
				else{

					s.push(q.front());
					q.pop();
				}
			}
			// else{


			// }
			
		}

		cout<<(flag ? "yes" : "no")<<endl;
	}

	return 0;
}
