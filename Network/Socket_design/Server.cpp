#include<bits/stdc++.h>
#include<sys/socket.h>
#include<arpa/inet.h>
using namespace std;

int main(){
	int nSocket=socket(AF_INET , SOCK_STREAM , 0);
	/**
	Address Family - AF_INET (this is IP version 4)
	Type - SOCK_STREAM (this means connection oriented TCP protocol)
		SOCK_DGRAM which indicates the UDP protocol
	Protocol - 0 [ or IPPROTO_IP This is IP protocol]
	*/
	if(nSocket>0) cout<<"Initialization of Socket is Sucessfull"<<endl;
	else	cout<<"Initializaton of Socket Fail"<<endl;

	struct sockaddr_in server;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );

	if (connect(nSocket , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		cout<<"connect error"<<endl;
		return 1;
	}else
		cout<<"Sucess"<<endl;

	return 0;
}
