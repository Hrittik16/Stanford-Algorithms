#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define rep(i, a, b) for(int i = a; i < b; i++) 
#define repll(i, a, b) for(ll i = a; i < b; i++) 
#define all(a) (a).begin(),(a).end()
#define pb push_back


class inv {
public:
	int count;
	inv() {
		count = 0;
	}
	void merge(vi& ar, int beg, int mid, int end) {
		int n1, n2, i = 0, j = 0, k = beg;
		n1 = mid-beg+1;
		n2 = end-mid;
		int a[n1], b[n2];
		for(i = 0; i < n1; i++) {
			a[i] = ar[beg+i];
		}
		for(i = 0; i < n2; i++) {
			b[i] = ar[mid+1+i];
		}
		i = 0;
		j = 0;
		while(i < n1 && j < n2) {
			if(a[i] > b[j]) {
				ar[k] = b[j];
				j++;
				k++;
				count += n1-i;
			}
			else {
				ar[k] = a[i];
				i++;
				k++;
			}
		}
		while(i < n1) {
			ar[k] = a[i];
			i++;
			k++;
		}
		while(j < n2) {
			ar[k] = b[j];
			j++;
			k++;
		}
	}
	void inversion_count(vi& ar, int beg, int end) {
		if(beg < end) {
			int mid = beg + (end-beg)/2;
			inversion_count(ar, beg, mid);
			inversion_count(ar, mid+1, end);
			merge(ar, beg, mid, end);
		}
	}
};

int main() {
	
	vi ar = {6, 5, 4, 3, 2, 1};

	int n = ar.size();

	inv obj1;

	obj1.inversion_count(ar, 0, n);

	cout << obj1.count << "\n";

	return 0;
}