#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
using namespace std;

#define MAX_D 101
#define MAX(a, b) ((a > b) ? (a):(b))

int n;

typedef struct {
	int degree;
	int coef[MAX_D];
	int epoonent[MAX_D];
}poly;

//poly poly_minus(poly A, poly B) {
//	poly C;
//	int Apos = 0, Bpos = 0, Cpos = 0;
//	int degree_a = A.degree;
//	int degree_b = B.degree;
//	C.degree = MAX(A.degree, B.degree);
//
//	while (Apos <= A.degree && Bpos <= B.degree) {
//		if (degree_a > degree_b) {
//			C.coef[Cpos++] = A.coef[Apos++];
//			degree_a--;
//		}
//		else if (degree_a == degree_b) {
//			C.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
//			degree_a--;
//			degree_b--;
//		}
//		else {
//			C.coef[Cpos++] = B.coef[Bpos++];
//			degree_b--;
//		}
//	}
//	return C;
//}

poly poly_minus(poly A, poly B) {
	poly C;

	C.degree = MAX(A.degree, B.degree);
	int i = 0;
	int j = 0;
	int cnt = C.degree;

	
	for (int k = 0; k < cnt; k++) {

		if (A.epoonent[i] == B.epoonent[j]) {
			//cout << 1 << ":";
			C.coef[k] = A.coef[i] - B.coef[j];
			//cout << C.coef[k] << endl;
			C.epoonent[k] = A.epoonent[i];
			i++;
			j++;
		}
		else if (A.epoonent[i] > B.epoonent[j]) {
			//cout << 2 << " : " << endl;
			C.coef[k] = A.coef[i];
			C.epoonent[k] = A.epoonent[i];
			i++;
		}
		else if (A.epoonent[i] < B.epoonent[j]) {
			//cout << 3 << " : " << endl;
			//cout << A.epoonent[i] << endl;
			C.coef[k] = 0 - B.coef[j];
			//cout << C.coef[k] << endl;
			C.epoonent[k] = B.epoonent[j];
			j++;
		}
	}
	

	/*for (int i = 0; i < cnt; i++) {
		cout << "C의 coef값" << C.coef[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < cnt; i++) {
		cout << "C의 epo값" << C.epoonent[i] << " ";
	}
	cout << endl;*/
	return C;
}

void print_poly(poly p) {
	bool b = false;
	for (int i = 0; i < p.degree-1; i++) {

		if (p.coef[i] == 1 || p.coef[i] == -1) {
			if (p.epoonent[i] == 1) {
				printf("x");
			}
			else {
				printf("x^%d", p.epoonent[i]);
			}
		}
		else if (p.epoonent[i] == 1) {
			printf("%dx", abs(p.coef[i]));
		}
		else {
			printf("%dx^%d", abs(p.coef[i]), p.epoonent[i]);
		}
		if (p.coef[i + 1] >= 0) {
			printf("+");
		}
		else {
			printf("-");
		}
	}
	if(p.epoonent[p.degree-1] == 0) {
		printf("%d", abs(p.coef[p.degree - 1]));
	}
	if (p.coef[p.degree - 1] == 0) {
		printf("%d", 0);
	}
	cout << endl;
}

poly make_poly(vector<int> &v) {
	poly p;
	p.degree = v[0];
	for (int i = 1; i < v.size(); i += 2) {
		p.coef[i/2] = v[i];
		p.epoonent[i/2] = v[i+1];

		//cout << i << " = " << p.coef[i/2] << ":" << v[i] << " " << p.epoonent[i/2] << ":" << v[i + 1] << endl;
	}
	return p;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int> v1;
		vector<int> v2;
		poly p1;
		poly p2;
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				int nterm;
				cin >> nterm;
				v1.push_back(nterm);
				while (nterm--) {
					int a, b;
					cin >> a >> b;
					v1.push_back(a);
					v1.push_back(b);
				}

				p1 = make_poly(v1);
				/*print_poly(p1);
				cout << endl;*/
			}
			if (i == 1) {
				int nterm;
				cin >> nterm;
				v2.push_back(nterm);
				while (nterm--) {
					int a, b;
					cin >> a >> b;
					v2.push_back(a);
					v2.push_back(b);
				}

				p2 = make_poly(v2);
				/*print_poly(p2);
				cout << endl;*/
			}
		}
		poly p3 = poly_minus(p1, p2);
		print_poly(p3);
	}
}