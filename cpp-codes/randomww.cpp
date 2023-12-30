#include<bits/stdc++.h>
//#include<add_iding.h>
using namespace std;

char Class_finder(char add_id[])
{
	char store[4];
	int i = 0;
	while (add_id[i] != '.')
	{
		store[i] = add_id[i];
		i++;
	}
	i--;
	int ip = 0, j = 1;
	while (i >= 0)
	{
		ip = ip + (add_id[i] - '0') * j;
		j = j * 10;
		i--;
	}
	if (ip >= 0 && ip <= 127)
		return 'A';
	else if (ip >= 128 && ip <= 191)
		return 'B';
	else if (ip >= 192 && ip <= 223)
		return 'C';
	else if (ip >= 224 && ip <= 239)
		return 'D';
	else
		return 'E';
}

void find_network_and_hostId(char add_id[], char class_ip)
{
	char network[12], host[12];
	for (int k = 0; k < 12; k++)
		network[k] = host[k] = '\0';
	if (class_ip == 'A')
	{
		int i = 0, j = 0;
		while (add_id[j] != '.')
			network[i++] = add_id[j++];
		i = 0;
		j++;
		while (add_id[j] != '\0')
			host[i++] = add_id[j++];
		cout << "\nThe Network ID is as : " << network;
		cout << "\nTHe Host ID is as : " << host;
	}
	else if (class_ip == 'B')
	{
		int i = 0, j = 0, dotCount = 0;
		while (dotCount < 2)
		{
			network[i++] = add_id[j++];
			if (add_id[j] == '.')
				dotCount++;
		}
		i = 0;
		j++;
		while (add_id[j] != '\0')
			host[i++] = add_id[j++];
		cout << "\nThe Network ID is : " << network;
		cout << "\nThe Host ID is : " << host;
	}
	else if (class_ip == 'C')
	{
		int i = 0, j = 0, dotCount = 0;
		while (dotCount < 3)
		{
			network[i++] = add_id[j++];
			if (add_id[j] == '.')
				dotCount++;
		}
		i = 0;
		j++;
		while (add_id[j] != '\0')
			host[i++] = add_id[j++];
		cout << "\nTheNetwork ID is : " << network;
		cout << "\nTheHost ID is : " << host;
	}
	else
		cout << "\nThe IP address in this class  is not"
		     " divided into Network and Host ID\n";
}

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	char add_id[100];
	cout << "Enter IP address : ";
	cin >> add_id;
	char class_ip = Class_finder(add_id);
	cout << "Given IP address belongs to Class " << class_ip;
	find_network_and_hostId(add_id, class_ip);
	return 0;
}
