#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int num_of_frames;
		cin >> num_of_frames;


		vector<string> sender_v;

		for (int i = 0; i < num_of_frames; i++)
		{
			string s;
			cin >> s;
			sender_v.push_back(s);
		}


		string s1;


		for (int i = 0; i < num_of_frames; i++)
		{
			int w = sender_v[i].size();
			w++;
			string w1 = to_string(w);

			s1 += w1;
			s1 += sender_v[i];

		}


		cout << s1 << endl;


		cout << "Data at reciever side : ";


		string s2;
		cin >> s2;


		//handle the case where s2 is empty


		int idx = 1;
		int req_len = s2[0] - '0';
		req_len--;
		string current_string = "";
		int current_cnt = 0;
		vector<string> rec_v;

		bool  is_error = false;


		while (idx < s2.length())
		{
			if (current_cnt == req_len)
			{
				rec_v.push_back(current_string);
				current_string = "";
				current_cnt = 0;
				req_len = s2[idx] - '0';
				if (req_len == 1)
				{
					is_error = true;
					break;
				}
				req_len--;
			}
			else
			{
				current_string += s2[idx];
				current_cnt++;
			}
			idx++;
		}


		if (is_error == false)
		{
			if (req_len == current_cnt)
			{
				is_error = false;
				rec_v.push_back(current_string);
			}
			else
			{
				is_error = true;
			}
		}



		cout << endl;
		cout << "The data after removing character count is : ";

		for (auto x : rec_v)
		{
			cout << x << " ";
		}

		cout << "The data in the frame from : ";
		cout << endl;

		for (int i = 0; i < rec_v.size(); i++)
		{
			cout << "Frame " << i + 1 << " : " << rec_v[i];
		}


		cout << endl;

		if (is_error)
		{
			cout << "Error";
		}
		else cout << "No Error";


	}
	return 0;
}
