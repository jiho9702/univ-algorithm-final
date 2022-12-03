#include <iostream>
#include <stdio.h>

using namespace std;

//param
int t;

//test case
/*
1
2 9 3 7 2
2 9 1 8 0

*/

typedef struct {
	int n;
	int co[101];
	int in[101];
}poly;

int n;

int comp(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

poly poly_sub(poly a, poly b) {

	poly p = {};
	//cout << "p.n = " << p.n << endl;

	
	int i = 0, j = 0, k = 0;

	while(true) {
		if (a.in[i] == b.in[j]) {
			p.in[k] = a.in[i];
			p.co[k] = a.co[i] - b.co[j];
			i++;
			j++;
			k++;
		}
		else if (a.in[i] > b.in[j]) {
			p.in[k] = a.in[i];
			p.co[k] = a.co[i];
			i++;
			k++;
		}
		else if (a.in[i] < b.in[j]) {
			p.in[k] = b.in[j];
			p.co[k] = -b.co[j];
			j++;
			k++;
		}

		if (i == a.n && j == b.n) {
			p.n = k;
			break;
		}
	}

	return p;
}

void print_poly(poly c) {

	for (int i = 0; i < c.n; i++) {

		if (c.co[i] == 0 && i == c.n - 1) {
			printf("0");
			continue;
		}
		if (c.co[i] == 0 && i != c.n - 1) {
			continue;
		}

		if (c.co[i] > 0) {
			if (c.co[i] == 1) {
				if (c.in[i] == 0) {
					printf("%d", c.co[i]);
				}
				else if (c.in[i] == 1) {
					printf("x");
				}
				else {
					printf("x^%d", c.in[i]);
				}
			}
			else {
				if (c.in[i] == 0) {
					printf("%d", c.co[i]);
				}
				else if (c.in[i] == 1) {
					printf("%dx", c.co[i]);
				}
				else {
					printf("%dx^%d", c.co[i], c.in[i]);
				}
			}
		}

		if (c.co[i] < 0) {
			if (c.co[i] == -1) {
				if (c.in[i] == 0) {
					printf("%d", c.co[i]);
				}
				else if (c.in[i] == 1) {
					printf("-x");
				}
				else {
					printf("-x^%d", c.in[i]);
				}
			}
			else {
				if (c.in[i] == 0) {
					printf("%d", c.co[i]);
				}
				else if (c.in[i] == 1) {
					printf("%dx", c.co[i]);
				}
				else {
					printf("%dx^%d", c.co[i], c.in[i]);
				}
			}
		}
		if (i < c.n - 1) {
			if (c.co[i + 1] >= 0) {
				printf("+");
			}
		}
	}
	/*cout << endl;
	cout << endl;
	cout << endl;*/
}

int main() {
	cin >> t;

	while (t--) {

		poly c = {};
		poly p1 = {};
		poly p2 = {};

		for (int i = 0; i < 2; i++) {
			int nterm;
			cin >> nterm;
			if (i == 0) {
				p1.n = nterm;
				for (int i = 0; i < nterm*2; i++) {
					p1.co[i] = 0;
					p1.in[i] = -1;
				}
				for (int j = 0; j < nterm; j++) {
					int a, b;
					cin >> a >> b;
					p1.co[j] = a;
					p1.in[j] = b;
				}
				/*cout << p1.n << endl;
				for (int j = 0; j < nterm; j++) {
					cout << p1.co[j] << " ";
				}
				cout << endl;
				for (int j = 0; j < nterm; j++) {
					cout << p1.in[j] << " ";
				}
				cout << endl;*/
			}
			if (i == 1) {
				p2.n = nterm;
				for (int i = 0; i < nterm*2; i++) {
					p2.co[i] = 0;
					p2.in[i] = -1;
				}
				for (int j = 0; j < nterm; j++) {
					int a, b;
					cin >> a >> b;
					p2.co[j] = a;
					p2.in[j] = b;
				}

				/*cout << p2.n << endl;
				for (int j = 0; j < nterm; j++) {
					cout << p2.co[j] << " ";
				}
				cout << endl;
				for (int j = 0; j < nterm; j++) {
					cout << p2.in[j] << " ";
				}
				cout << endl;*/
			}
			
		}
		/*cout << endl;
		cout << endl;
		cout << endl;*/
		c = poly_sub(p1, p2);
		/*cout << c.n << endl;
		for (int j = 0; j < c.n; j++) {
			cout << c.co[j] << " ";
		}
		cout << endl;
		for (int j = 0; j < c.n; j++) {
			cout << c.in[j] << " ";
		}
		cout << endl;
		cout << endl;
		cout << endl;*/

		print_poly(c);
		cout << "\n";
	}
}