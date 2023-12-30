// A Lucas Theorem based solution to compute nCr % p
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

// Returns nCr % p. In this Lucas Theorem based program,
// this function is only called for n < p and r < p.
lli nCrModpDP(lli n, lli r, lli p)
{
	// The array C is going to store last row of
	// pascal triangle at the end. And last entry
	// of last row is nCr
	lli C[r+1];
	memset(C, 0, sizeof(C));

	C[0] = 1; // Top row of Pascal Triangle

	// One by constructs remaining rows of Pascal
	// Triangle from top to bottom
	for (lli i = 1; i <= n; i++)
	{
		// Fill entries of current row using previous
		// row values
		for (lli j = min(i, r); j > 0; j--)

			// nCj = (n-1)Cj + (n-1)C(j-1);
			C[j] = (C[j] + C[j-1])%p;
	}
	return C[r];
}

// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion
// recursive function. First we compute last digits of
// n and r in base p, then recur for remaining digits
lli nCrModpLucas(lli n, lli r, lli p)
{
// Base case
if (r==0)
	return 1;

// Compute last digits of n and r in base p
lli ni = n%p, ri = r%p;

// Compute result for last digits computed above, and
// for remaining digits. Multiply the two results and
// compute the result of multiplication in modulo p.
return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
		nCrModpDP(ni, ri, p)) % p; // Remaining digits
}

// Driver program
int main()
{
	lli n,r;
	cin>>n;
	cin>>r;
	lli p = 1000000007;
	cout << nCrModpLucas(n, r, p);
	return 0;
}
